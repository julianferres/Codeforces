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
const ll INF = 2e16;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;


int main(){  
    FIN;

    int tc; cin >> tc;
    while(tc--){
    	ll n; cin >> n;
    	vi a(n); forn(i, n) cin >> a[i];
    	ll ans = n*(a[1] + a[0]);

    	ll suma_impar = a[1], suma_par = a[0];
    	ll min_impar = a[1], min_par = a[0];
    	ll cnt_pares = 1, cnt_impares = 1;

    	forr(i, 2, n){
    		if(i&1){
    			suma_impar += a[i];
    			min_impar = min(min_impar, a[i]);
    			cnt_impares++;
    		} else {
    			suma_par += a[i];
    			min_par = min(min_par, a[i]);
    			cnt_pares++;
    		}

    		ll ans_impar = (suma_impar - min_impar) + (n - (cnt_impares - 1))*min_impar;
    		ll ans_par = (suma_par - min_par) + (n - (cnt_pares - 1))*min_par;
    		dbg(i, ans_impar, ans_par);
    		// dbg(i, suma_impar, suma_par);
    		ans = min(ans, ans_impar + ans_par);
    	}

    	cout << ans << "\n";
    }


    return 0;
}