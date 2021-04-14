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


vi pot2(1, 1);
ll mul(ll a, ll b){
	return (a%MOD)*(b%MOD)%MOD;
}
void add(ll &a, ll b){
	a+=b;
	if(a > MOD) a-= MOD;
}

int main(){  
    FIN;

    int tc; cin >> tc;
    forn(i, 65){
    	ll aux = pot2.back();
    	pot2.pb((aux*2)%MOD);
    }

    while(tc--){
    	int n; cin >> n;
    	vi a(n); forn(i, n) cin >> a[i];

    	vi cnt(62);
    	forn(i, n){ forn(j, 62){ if((a[i] & (1LL << j))) cnt[j]++; }}

    	ll ans = 0;

    	// dbg(pot2);
    	dbg(cnt);


    	forn(i, n){
    		ll suma_or = 0, suma_and = 0;
    		forn(j, 62){
    			if((a[i] & (1LL << j))){
    				suma_and += mul(cnt[j], pot2[j]);
    				suma_or += mul(n, pot2[j]);
    			} else{
    				suma_or += mul(cnt[j], pot2[j]);
    			}
    		}
    		add(ans, mul(suma_or, suma_and));
    	}


    	cout << ans << "\n";

    }

    

    return 0;
}
