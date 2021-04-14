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
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;
const int MAXLOG  = 20;

ll GCD[MAXN][MAXLOG];

ll query(ll L, ll R){
    ll j = (ll)log2(R - L + 1);
    return __gcd(GCD[L][j], GCD[R - (1 << j) + 1][j]);
}

vector <ll> link, sz;
  
void DSU(ll tam) {
    link.resize(tam+5), sz.resize(tam+5);
    forn(i,tam+5) link[i] = i, sz[i] = 1;
}
  
int find(ll x){return link[x] = (link[x] == x ? x : find(link[x]));}
bool same(ll a, ll b) { return find(a)==find(b); }

void join(ll a, ll b) {
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    link[b] = a;
  }



int main(){  
    FIN;

    int tc; cin >> tc;
    while(tc--){
    	ll n, p; cin >> n >> p; 
    	vi a(n); forn(i, n) cin >> a[i];

    	// memset(GCD, 0, sizeof(GCD));
    	forn(i, n) GCD[i][0] = a[i];
  
	    // Build sparse GCD
	    forr(j, 1, MAXLOG)
	        for (ll i = 0; i + (1<<j) <= n; i++)
	            GCD[i][j] = __gcd(GCD[i][j - 1], GCD[i + (1 << (j - 1))][j - 1]);

    	// dbg("sparse OK");
    	vii pairs; forn(i, n) pairs.emplace_back(a[i], i);
    	sort(all(pairs));

    	DSU(n);

    	ll ans = 0;
    	for(auto x: pairs){
    		ll m = x.first, i = x.second;
    		if(m >= p) break;

    		//Atras
    		if(i != 0 && a[i-1] % a[i] == 0){
    			ll first = i;
    			for(ll j = MAXLOG - 1; j >= 0; j--){
    				if(first - (1<<j) >= 0 && !same(i, first - (1<<j)) && query(first - (1<<j), i) == m)  {
    					first -= (1<<j);
    				}
    			}
    			// dbg(m, i, first);
    			if(first == i) continue;
    			forr(j, first, i){
    				if(!same(j, j+1)){
    					join(j, j+1);
    					ans += m;
    				}
    			}
    		}
    		if(i != n-1 && a[i+1] % a[i] == 0 && !same(i, i+1)){
    			// dbg("Entra");
				ll last = i;
    			for(ll j = MAXLOG - 1; j >= 0; j--){
    				if(last + (1<<j) < n && !same(i, last + (1<<j)) && query(i, last + (1<<j)) == m)  {
    					last += (1<<j);
    				}
    			}
    			if(last == i) continue;
    			forr(j, i, last){
    				// dbg(i, j);
					if(!same(j, j+1)){
    					join(j, j+1);
    					ans += m;
    				}
    			}
    		}
    	}

    	forn(i, n-1){
    		if(!same(i, i+1)){
    			join(i, i+1);
                
    			ans += p;
    		}
    	}

    	cout << ans << "\n";

    }

    

    return 0;
}
