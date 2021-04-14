#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

/*
 * uses binary search to find best speed to ensure a given number of late projects
 */

const int MAXJOBS = 100000;

class job
{
public:
    int length, due;
};
int njobs;

bool compareDue(job j1, job j2)
{
    return (j1.due < j2.due);
}

class mycomparison
{
public:
    bool operator() (const job& lhs, const job&rhs) const
    {
        return (lhs.length < rhs.length);
    }
};


priority_queue<job, vector<job>, mycomparison> pq;

int moores(long long speed, vector<job>jobs)
{
    long double time = 0;
    int count = 0;
    while (!pq.empty())
        pq.pop();
    for(job j : jobs) {
//cerr << "processing job " << j.due << ',' << j.length << endl;
        pq.push(j);
        time += j.length/(double)speed;
//cerr << "   time = " << time << endl;
        if (time > j.due && fabs(time-j.due) >= 5e-15) {
            job removeJob = pq.top();
            pq.pop();
            cout << "speed: " << speed << "   removing job " << removeJob.due << endl;
            time -= removeJob.length/(double)speed;
            count++;
        }
    }
    return count;
}

int main()
{
    int nlate;
    cin >> njobs >> nlate;
    vector<job> jobs(njobs);

    double totLength = 0;
    int maxDue = 0;
    for(int i=0; i<njobs; i++) {
        cin >> jobs[i].length >> jobs[i].due;
        totLength += jobs[i].length;
    }
    sort(jobs.begin(), jobs.end(), compareDue);
    maxDue = (*jobs.rbegin()).due;

    long long shigh = totLength/maxDue;         // approximate upper bound on speed
    while (moores(shigh, jobs) > nlate)
        shigh *= 2;
    long long slow = 1.0;
    int chigh = moores(shigh, jobs);
    int clow = moores(slow, jobs);
    while (shigh - slow > 1) {
//cerr << fixed << shigh << ',' << slow << ", diff = " << shigh-slow << " " << chigh << ',' << clow << endl;
        long long smid = (shigh+slow)/2.0;
        int cmid = moores(smid, jobs);
//cerr << "    smid, cmid = " << smid << ',' << cmid << endl;
        if (cmid > nlate) {
            slow = smid;
            clow = cmid;
        }
        else if (cmid < nlate) {
            shigh = smid;
            chigh = cmid;
        }
/**/
        else if (clow == nlate) {
            slow = smid;
            clow = cmid;
        }
        else {
            shigh = smid;
            chigh = cmid;
        }
/**/
    }
    if (moores(slow, jobs) <= nlate)
        cout << slow << endl;
    else
        cout << slow+1 << endl;
}
