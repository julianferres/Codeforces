#! /usr/bin/env python3
import logging
import os
import shutil
from argparse import ArgumentParser

import requests
from bs4 import BeautifulSoup

# define logging
logging.basicConfig(level=logging.INFO,
                    format='%(asctime)s %(levelname)-8s %(message)s',
                    datefmt='%Y-%m-%d %H:%M:%S')
logger = logging.getLogger(__name__)

# URL schemes
CONTEST_URL_SCHEME = 'http://codeforces.com/{type}/{contest}'
PROBLEM_URL_SCHEME = 'http://codeforces.com/{type}/{contest}/problem/{problem}'

PYTHON_TEMPLATE = "main.py"
CPP_TEMPLATE = "main.cpp"
MAKEFILE = "Makefile"
DEBUGGER = "dbg.cpp"
CPP_EXTENSION = ".cpp"


# Tet location and naming definition
IN_FILE_PATTERN = '{problem_id}{id}.in'
OUT_FILE_PATTERN = '{problem_id}{id}.out'


def parse_contest_for_problem_list(contest_type, contest_id):
    """
    Parses codeforces contest page for list of problems.

    Parameters
    ----------
    contest_id : int
        id of codeforces contest, can be seen in the url, example codeforces.com/contest/100/

    Returns
    -------
    problem_list : list of strings
        list of problem names, example ['A', 'B', ...]
    """
    logger.debug('Parsing problem %s', contest_id)
    url = CONTEST_URL_SCHEME.format(type=contest_type, contest=contest_id)
    page = requests.get(url)
    soup = BeautifulSoup(page.content, 'html.parser')

    problems_table = soup.findAll('table', 'problems')
    if len(problems_table) != 1:
        logger.warning('Contest %s page parsing failed. Problems table not found', contest_id)
        return []

    html_problems_list = problems_table[0].findAll('td', 'id')
    problem_list = [x.get_text().strip() for x in html_problems_list]
    logger.debug('Parsed contest page, found %s problems %s', len(problem_list), problem_list)
    return problem_list


def parse_problem(contest_type, contest_id, problem_id):
    """
    Parses codeforces problem page for provided test samples.


    Parameters
    ----------
    contest_id : int
        id of codeforces contest, can be seen in the url, example codeforces.com/contest/100/
    problem_id : str
        name of codeforces problem, can be seen in the url, example codeforces.com/contest/100/problem/A/

    Returns
    -------
    tests : zip object
        zip object of pairs of strings (input, output)

    """
    logger.debug('Parsing problem %s', problem_id)
    url = PROBLEM_URL_SCHEME.format(type=contest_type, contest=contest_id, problem=problem_id)
    page = requests.get(url)
    soup = BeautifulSoup(page.content, 'html.parser')

    for br in soup.find_all('br'):
        br.replace_with('\n')

    tests = soup.findAll('div', 'sample-test')
    if len(tests) != 1:
        logger.warning('Contest %s, problem %s page parsing failed. Tests not found', contest_id, problem_id)
        return []

    def get_sample_data(bs_divs):
        return [x.pre.get_text() for x in bs_divs]

    tests = tests[0]
    ins = get_sample_data(tests.findAll('div', 'input'))
    outs = get_sample_data(tests.findAll('div', 'output'))
    logger.debug('Parsed problem %s, found %s test samples', problem_id, len(ins))
    return zip(ins, outs)


def download_cf_contest(contest_type, contest, root_path, templates_dir=None):
    """
    Parses codeforces contest and downloads test data for all the problems.
    Following file structure is created in provided `root_path`:
        <root_path>/<contest>/<problem>/tests/

    If templates_dir is provided, templates are copied to the contest and problem dirs.
    It is expected that templates_dir contains two directories: contest and problem.

    Parameters
    ----------
    contest : int
        id of codeforces contest, can be seen in the url, example codeforces.com/contest/100/
    root_path : str
        root dir where tests where file structure will be created
    templates_dir : str
        templates source directory, if None it is simply ignored.
    """
    logger.info('Parsing contest %s', contest)
    problem_list = parse_contest_for_problem_list(contest_type, contest)
    contest_root = os.path.join(root_path, str(contest))

    for problem in problem_list:
        logger.info('Parsing problem %s', problem)
        tests_data = parse_problem(contest_type, contest, problem)
        tests_path = contest_root
        # , TESTS_SUBDIR)
        _dump_tests_to_file(problem, tests_data, tests_path)

    if templates_dir and len(problem_list) > 1:
        logger.info('Copying templates from %s to %s', templates_dir, contest_root)
        _copy_templates(contest_root, problem_list, templates_dir)


def _dump_tests_to_file(problem_id, tests, tests_path='./'):
    """
    Dumps parsed tests to files.

    In given `root` creates dir for contest with subdirs for every problem that contain tests directory. Test samples
    are stored in the tests subdirectory.

    Parameters
    ----------
    tests : zip
        zip object of pairs of strings (input, output)
    tests_path : str
        root dir where tests where file structure will be created
    """
    if not tests:
        return []

    _makedirs(tests_path)

    def dump_to_file(data, file_path):
        with open(file_path, 'w') as fout:
            fout.write(data.lstrip())

    for i, (in_data, out_data) in enumerate(tests):
        in_path = os.path.join(tests_path, IN_FILE_PATTERN.format(problem_id=problem_id, id=i+1))
        out_path = os.path.join(tests_path, OUT_FILE_PATTERN.format(problem_id=problem_id, id=i+1))

        dump_to_file(in_data, in_path)
        dump_to_file(out_data, out_path)


def _copy_templates(contest_root, problem_list, templates_dir):
    contents = os.listdir(templates_dir)
    if 'contest' in contents:
        _copy_content(os.path.join(templates_dir, 'contest'), contest_root)

    if 'problem' in contents:
        _copy_template_cpp(problem_list, os.path.join(templates_dir, 'problem'), contest_root)
        _copy_env_files(os.path.join(templates_dir, 'problem'), contest_root)
        for problem in problem_list:
            break
            # _copy_content(os.path.join(templates_dir, 'problem'), os.path.join(contest_root, problem))

def _copy_template_cpp(problem_list, src, dst):
    cpp_template_path = os.path.join(src, CPP_TEMPLATE)
    for problem_id in problem_list:
        shutil.copy(cpp_template_path, os.path.join(dst, problem_id + CPP_EXTENSION))
    logger.info("Copying CPP Templates...")

def _copy_env_files(src, dst):
    shutil.copy(os.path.join(src, PYTHON_TEMPLATE), dst)
    shutil.copy(os.path.join(src, MAKEFILE), dst)
    shutil.copy(os.path.join(src, DEBUGGER), dst)
    logger.info("Copying Makefile, dbg.cpp and Py Template...")


def _makedirs(path):
    # added for support with py2
    # os.makedirs(tests_path, exist_ok=True)
    try:
        os.makedirs(path)
    except OSError:
        pass


def _copy_content(src, dest):
    _makedirs(dest)
    for d in os.listdir(src):
        path = os.path.join(src, d)
        logger.debug('Copy %s to %s', src, dest)
        if os.path.isdir(path):
            shutil.copytree(path, dest)
        else:
            shutil.copy(path, dest)


def main():
    parser = ArgumentParser(description='Simple CLI tool for parsing Codeforces contest test samples')
    parser.add_argument('type', type=str, help='Type of the contest (contest, gym, etc, ...)')
    parser.add_argument('contest', type=int, help='ID of the contest')
    parser.add_argument('root_dir', type=str, default='./', nargs='?',
                        help='Optional argument root dir, where file structure will be created. '
                             'By default, this is current dir')
    parser.add_argument('-t', '--template_dir', type=str,
                        help='Optional argument for templates. Expected path to directory containing subdirectory '
                             '`contest` whose contents are copied to contest root dir, and subdirectory `problem` '
                             'with template files that are copied to every problem subdirectory. '
                             'If not provided, no templates are copied.')
    args = parser.parse_args()
    download_cf_contest(args.type, args.contest, args.root_dir, args.template_dir)
    logger.info("Let's code !!!")


if __name__ == '__main__':
    main()
