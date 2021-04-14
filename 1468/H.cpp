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

typedef int ll;
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

void YES(){ cout << "YES\n"; }
void NO(){ cout << "NO\n"; }

bool divisible(int a, int b){ return (a%b + b)%b == 0; }

int main(){  
    FIN;

    int tc; cin >> tc;
    while(tc--){
        
        int n, k, m; cin >> n >> k >> m;
        vi b(m); forn(i, m) cin >> b[i];

        int to_r = n - m;

        if(!divisible(n - m, k - 1)){
            NO(); continue;
        }

        vector<bool>to_remove(n+1, 1);
        for(int x: b) to_remove[x] = 0;
        
        //dbg(b);

        vi cum(n+1);
        forr(i, 1, n+1) cum[i] = cum[i-1] + to_remove[i];

        //dbg(b, to_remove, cum);

        bool possible = 0;

        forr(i, 1, n+1){
            possible |= (!to_remove[i] && cum[i] >= k/2 && to_r - cum[i] >= k/2);
        }



        (possible ? YES() : NO());
    }

    

    return 0;
}
