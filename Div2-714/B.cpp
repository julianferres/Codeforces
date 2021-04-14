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

ll mult(ll a, ll b){
	return (a%MOD) * (b%MOD) % MOD;
}

vi f(MAXN, 1);

int main(){  
    FIN;

    forr(i, 2, MAXN) f[i] = mult(i, f[i-1]);

    int tc; cin >> tc;
    while(tc--){
    	map<ll, ll> cnt;
    	ll n; cin >> n;
    	vi a(n); forn(i, n) cin >> a[i];
    	ll and_total = a[0];
    	forn(i, n){
    		and_total &= a[i];
    		cnt[a[i]]++;
    	}

    	bool possible = true;

    	forn(i, n){
    		if((a[i] & and_total) != and_total){
    			dbg(a[i], a[i] & and_total);
    			possible = 0;
    		}
    	}

    	dbg(and_total);

    	auto choose2 = [&](ll x){ return x * (x-1) / 2; };

    	if(possible){
    		cout << mult(2 * choose2(cnt[and_total]), f[n-2]) << "\n";
    	} else {
    		cout << 0 << "\n";
    	}

    }
    

    return 0;
}
