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

vi totient;
void init_totient_sieve(int n){
	totient.resize(n+1);
	forr(i, 1, n+1) totient[i] = i;
	forr(i, 2, n+1){
		if(totient[i] == i){
			for(int j = i; j <= n; j+= i)
				totient[j] -= totient[j] / i;
		}
	}
}

ll mul(ll a, ll b){ return a * b % MOD; }
void add(ll &a, ll b){
	a += b;
	if(a > MOD) a -= MOD;
}

ll be(ll x, ll y, ll m) {
    if (y == 0) return 1;
    ll p = be(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}

ll inv(ll x, ll m) {return be(x,m-2,m);}


int main(){  
    FIN;

	int n, m; cin >> n >> m;    

	init_totient_sieve(n+5);

	// 1/n * sum_d|n( phi(d) * m ^(n/d) )
	ll ans = 0;

	forr(i, 1, n+1){
		if(n % i == 0) add(ans, mul(totient[i], be(m, n/i, MOD)));
	}
	ans = mul(ans, inv(n, MOD));

	cout << ans << endl;

    return 0;
}
