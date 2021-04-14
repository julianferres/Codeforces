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
const int MAXN  = 2e5+5;

void cout_ans(int ans, int testcase){
    cout << "Case #" << testcase << ": " << ans << "\n";
}

int main(){  
    FIN;

    int tc; cin >> tc;
    forr(testcase, 1, tc+1){
        int g; string s; cin >> g >> s;

        vector<vector<string>> ranks(5, vector<string>(20));
        vector<string>ec_rank(20);

        forn(i, 5){ forn(j, 20){ cin >> ranks[i][j]; } }
        forn(i, 20) cin >> ec_rank[i];


        vector<string> x_rank; unordered_set<string> seen_x;

        forn(j, 20){
            forn(i, 5){
                if(!esta(ranks[i][j], seen_x)){
                    x_rank.pb(ranks[i][j]), seen_x.insert(ranks[i][j]);
                }
            }
        }
        int first_s = -1;
        forn(i, x_rank.size()){
            if(x_rank[i] == s){ 
                first_s = i; break;
            }
        }
        if(first_s == -1){
            cout_ans(0, testcase);
            continue;
        }

        int y_ans = -1;

        forn(y_act, g+1){
            unordered_set<string> seen;
            forn(i, g-y_act){
                seen.insert(x_rank[i]);
            }
            forn(i, ec_rank.size()){
                if(seen.size() >= g) break;
                if(esta(ec_rank[i], seen)) continue;
                seen.insert(ec_rank[i]);
            }
            if(!esta(s, seen)){
                y_ans = y_act;
                break;
            }
        }
        if(y_ans == -1){
            cout << "Case #" << testcase << ": ADVANCED!\n";
            continue;
        }
        cout_ans(y_ans, testcase);

    }

    

    return 0;
}
