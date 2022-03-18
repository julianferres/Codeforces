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
const int MAXVAL = 1e6+5;

vector<ll> criba(ll n) {
    vector <bool> prime(n+1,true);
    vector <ll> primos;
    for(ll p=2; p*p<=n; p++){
        if (prime[p] == true) {
            for(ll i=p*p; i<=n; i += p) prime[i] = false;
        }
    }
    for(ll i=2; i<=n; i++) if(prime[i]) primos.push_back(i);
    return primos;
}
vi primos;
vector<vi> primos_presentes;

void init_primos_presentes(ll mx){
	primos_presentes.resize(mx+1);
	for(ll p: primos){
		int i = 1;
		while(i * p <= mx){
			primos_presentes[i * p].pb(p);
			i++;
		}
	}
}


int main(){  
    FIN;

    ll n; cin >> n;
    vi a(n); forn(i, n) cin >> a[i];

    primos = criba(MAXVAL);

    ll mx = a[0]; forn(i, n) mx = max(mx, a[i]);
    init_primos_presentes(mx);

    map<ll, ll>cnt, sgn;

    ll ans = n*(n-1)/2;

    forn(i, n){
    	forr(mask, 1, (1<<primos_presentes[a[i]].size())){
    		ll x = 1;
    		forn(j, primos_presentes[a[i]].size())
    			if((1 << j) & mask) 
    				x *= primos_presentes[a[i]][j];
    		cnt[x]++;
    		sgn[x] = __builtin_popcount(mask);
    	}
    }

    auto choose2 = [&](ll x){ return x*(x-1)/2;};

    for(auto& [k, v]: cnt){
    	if(sgn[k]&1) ans -= choose2(v);
    	else ans += choose2(v);
    }

    cout << ans << "\n";

    return 0;
}
