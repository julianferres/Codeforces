/*   AUTHOR: julianferres   */
#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1e9+15; // const ll INF = 2e18;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 1005;

int memo[MAXN][MAXN];
string text, pattern;

bool dp(int i, int j, bool changed_plus_to_star){ //i texto, j patron
    if(memo[i][j] != -1) return memo[i][j];
    // dbg(i, j);

    if(j == (int)pattern.size()) memo[i][j] = (i == (int) text.size());
    else{
        int first_match = (i < (int)text.size() && pattern[j] == text[i]);

        if(j + 1 < (int) pattern.size() && (pattern[j + 1] == '*' || changed_plus_to_star))
            memo[i][j] = dp(i, j + 2, 0) || (first_match && dp(i + 1, j, changed_plus_to_star));
        if(j + 1 < (int) pattern.size() && pattern[j + 1] == '+'){
            memo[i][j] = (first_match && dp(i + 1, j + 2, 0)) || (first_match && dp(i+1, j, 1));
        }
        if(pattern[j + 1] != '*' && pattern[j + 1] != '+'){
            memo[i][j] = first_match && dp(i + 1, j + 1, 0);
        }
    }

    return memo[i][j];
}

int main(){
    FIN;

    cin >> pattern >> text;

    memset(memo, -1, sizeof(memo));

    // memo[(int)text.size()][(int)pattern.size()] = 1;
    dp(0, 0, 0);

    cout << (memo[0][0] ? "Yes" : "No");

    return 0;
}
