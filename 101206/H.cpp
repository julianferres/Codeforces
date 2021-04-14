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

vector<int> match[20], c[20], d[20];
int areas_cubiertas[105], dp[20][2050];

bool hay_match(int i){
    for(int area:c[i]){
        if(!areas_cubiertas[area]) return 0;
    }
    return 1;
}

int main(){  
    FIN;


    int tc; cin >> tc;
    forr(caso, 1, tc+1){
        cout << "Case #" << caso << ": ";
        int n, m; cin >> n >> m;

        forr(i, 1, n+1){
            int ci; cin >> ci;
            c[i].clear();

            forr(j, 1, ci+1){
                int aux; cin >> aux;
                c[i].pb(aux);
            }

        }
        
        forr(i, 1, m+1){
            int di; cin >> di;
            d[i].clear();

            forr(j, 1, di+1){
                int aux; cin >> aux;
                d[i].pb(aux);
            }

        }          

        forr(i, 1, n+1){
            match[i].clear();
            forr(j, 1, (1<<m)){
                memset(areas_cubiertas, 0, sizeof areas_cubiertas);                
                forn(k, 10){
                    if((1<<k) & j){
                        for(int cubre_area: d[k+1])
                            areas_cubiertas[cubre_area]++;                            
                    }
                }
                if(hay_match(i)) match[i].pb(j);
            }

        }
        
        ll ans = 0;

        vector<vi> dp(20, vi(2048));

        forr(i, 1, n+1){
            forr(j, 1, (1<<m)){
                for(int msk: match[i]){
                    if((j & msk) == msk){
                        dp[i][j] = max(dp[i][j], dp[i - 1][j - msk] + 1);
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
            forr(j, 1, (1<<m)) dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }

        cout << ans << "\n";
    }

    

    return 0;
}
