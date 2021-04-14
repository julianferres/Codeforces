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
const int MAXN  = 1e4+5;
const int MAXBIT = 60;

vi bs(MAXBIT+2), x(MAXN);  
vii g[MAXN]; 
vb seen(MAXN);

void upd(ll xr) {
    for (ll i = MAXBIT; i >= 0; --i) {
        if (xr & (1LL << i)) {
            if (!bs[i]) {
                bs[i] = xr; 
                break; 
            }
            xr ^= bs[i]; 
        }
    }
} 

void dfs(ll u) {
    // dbg(u);
    seen[u] = true;
    for (auto edge: g[u]) {
        ll v = edge.first, w = edge.second; 
        if (!seen[v]) {
            x[v] = x[u] ^ w; 
            dfs(v); 
        } else {
            upd(x[u] ^ x[v] ^ w); 
        }
     }
}

int main(){  
    FIN;

    ll n, m, q; cin >> n >> m >> q;

    forn(i, m){
        ll u, v; ll w;
        cin >> u >> v >> w; u--, v--;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    // dbg("llega");
    dfs(0);

    while(q--){
        int u, v; cin >> u >> v; u--, v--;

        ll ans = x[u] ^ x[v];

        for(int i = MAXBIT; i >= 0; i--){
            ans = min(ans, ans ^ bs[i]);
        }
        cout << ans << "\n";    
    }

    return 0;
}
