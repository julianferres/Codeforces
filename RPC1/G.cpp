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
const int MOD = 1e9; // 998244353
const int MAXN  = 2e5+5;
const int PHI = 4e8;

ll be_iter(ll a, ll b, ll m){
	ll res = 1;
	while(b > 0){
		if(b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}


int main(){  
    FIN;

	int tc; cin >> tc;
    while(tc--){
    	int k, q; cin >> k >> q;
    	vector<int> a(k); forn(i, k) cin >> a[i];

    	forn(i, q){
    		ll n; cin >> n;
    		ll base = a[n%k];
    		ll pot = n/k + 1;
    		pot %= PHI;
    		bool neg = base < 0;
    		base = abs(base);
    		ll ans = be_iter(base, pot, MOD);

    		if((pot&1) && neg) ans = -ans;
    		ans = ((ans % MOD) + MOD)%MOD;

    		cout << ans << "\n";
    	}

    }    

    return 0;
}
