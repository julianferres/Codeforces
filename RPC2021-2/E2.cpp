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
const ll INF = 2e18;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

vector<vi> a;
vector<vector<vi>> dp;

bool is_pass(int i, int j, int r, int c);

int main(){  
    FIN;


    int r, c, n; cin >> r >> c >> n;
    a.resize(r+1, vi(c+1, -1));
    dp.resize(r+1, vector<vi>(c+1, vi(n+3, INF)));
    forr(i, 1, r+1){
        forr(j, 1, c+1) cin >> a[i][j];
    }
    
    forn(i, r+1){
        forn(j, c+1){
            forn(k, n+2){
                if(a[i][j] == -1) continue;
                else if(is_pass(i, j)){

                }
                else{

                }
            }
        }
    }



    return 0;
}
