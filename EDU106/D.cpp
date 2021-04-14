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
const int MAXVAL  = 2e7+5;

vi divisors(ll n){
	vi ans;
	int d = 1;
	while(d*d <= n){
		if(n % d == 0){
			if(d*d != n) ans.pb(n/d);
			ans.pb(d);
		}
		d++;
	}

	return ans;
}

//Obtiene todos los primeros primos menores que n
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
vi nPrimos(MAXVAL);

void criba_n_primos() {
	for(ll p: primos){
        for(ll i=p; i < MAXVAL; i += p) nPrimos[i]++;
	}
}

ll countPairs(ll k){
	//Big prime
	return (1LL << nPrimos[k]);
}



int main(){  
    FIN;

    primos = criba(2e7+5);
    criba_n_primos();
    // dbg(nPrimos[0], nPrimos[1], nPrimos[4], nPrimos[60]);

	int tc; cin >> tc;
	while(tc--){
		ll c, d, x; cin >> c >> d >> x; 

		vi divs = divisors(x);
		ll ans = 0;

		for(auto g: divs){
			if(((x/g) + d) % c == 0){
				ll k = ((x/g) + d)/c;
				ans += countPairs(k);
			}
		}
		cout << ans << "\n";
	}   

    return 0;
}