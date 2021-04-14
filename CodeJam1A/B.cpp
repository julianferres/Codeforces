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

const int MAXSUM  = 30303;


int main(){  
    FIN;

    int tc; cin >> tc;
    forr(case_n, 1, tc+1){
    	int m; cin >> m;

    	vii cartas(m); 
    	ll suma_total = 0;
    	forn(i, m){
    		cin >> cartas[i].first >> cartas[i].second;
    		suma_total += cartas[i].first * cartas[i].second;
    	}

    	auto valid = [&](ll product, ll suma){
    		forn(i, m){
    			int cnt = 0;
    			while(product % cartas[i].first == 0){
    				// dbg(product);
    				product /= cartas[i].first;
    				suma -= cartas[i].first;
    				cnt++;
    			}
    			if(cnt > cartas[i].second) return false;
    		}
    		return suma == 0 && product == 1;
    	};

    	bool is_zero = true;
    	for(ll i = 1; i < MAXSUM && i < suma_total; i++){
    		if(valid(suma_total - i, i)){
    			is_zero = false;
	    		cout << "Case #" << case_n << ": " << suma_total - i << "\n";
    			break;
    		}
    	}
    	if(is_zero){
	    	cout << "Case #" << case_n << ": " << 0 << "\n";
    	}


    }

    return 0;
}

