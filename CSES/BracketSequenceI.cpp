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
const int MAXN  = 2e6+5;

vector <ll> f;

ll be(ll x, ll y, ll m) {
    if (y == 0) return 1;
    ll p = be(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}

ll inv_mod(ll x, ll m) {return be(x,m-2,m);}

void factorial() { // O(N)
	f.pb(1); forn(i,MAXN) f.pb((f.back()*(ll)(i+1)) % MOD);
}

ll combinatorio(ll n, ll m) {
	// Retorna n tomados de a m en O(Log N)
	ll ans = 1; ans *= f[n];
	ans *= inv_mod(f[m],MOD); ans %= MOD;
	ans *= inv_mod(f[n-m],MOD); ans %= MOD;
	return ans;
}


int main(){  
    FIN;

    factorial();

    int n; cin >> n; 
    if(!n || (n&1)){
        cout << 0 << "\n";
        return 0;
    }
    n /= 2;
    ll ans = combinatorio(2*n, n);
    ans *= inv_mod(n+1, MOD);
    ans = ((ans%MOD) + MOD)%MOD;
    
    cout << ans << "\n";

    return 0;
}
