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


int ask(int i, int j, int k){
	cout << i << " " << j << " " << k << endl;
	int mediana; cin >> mediana;
	return mediana;
}


void solve_test(int tc, int n, int q){
	set<ll> extremos = {1, 2};
	forr(i, 3, n+1){
		extremos.insert(i);
		vi copia;
		for(ll u: extremos){
			copia.pb(u);
		}
		extremos.erase(ask(copia[0], copia[1], copia[2]));
	}
	// dbg(extremos);

	vi ans = { (ll) *extremos.begin() };

	forr(i, 1, n+1){
		if(i == ans[0]) continue;

		int l = 1, r = ans.size();
		while(l < r){
			int mid = (l + r)/2;
			if(ask(ans[0], ans[mid], i) == ans[mid]){
				l = mid + 1;
			} else {
				r = mid;
			}
		}

		ans.insert(ans.begin() + l + 1, i);
		// dbg(l, r, ans);
	}

	forn(i, n) cout << ans[i] << " \n"[i == n-1];
	int x; cin >> x;
}

int main(){  
    FIN;

    int t, n, q; cin >> t >> n >> q;
    forr(i, 1, t+1){
    	solve_test(i, n, q);
    }    

    return 0;
}
