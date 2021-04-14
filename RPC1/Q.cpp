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
typedef tuple<int, int, int> iii;

struct st{
	vector<iii>s;

	bool empty(){
		return s.size() == 0;
	}

	void push(ll x){
		if(s.size() == 0) s.pb({x, x, x});
		else{
			ll last, m, M; tie(last, m, M) = s.back();
			s.pb({x, min(m, x), max(M, x)});
		}
	}

	void pop(){
		if(s.size() == 0) return;
		s.pop_back();
	}
	ll query(){
		ll last, m, M; tie(last, m, M) = s.back();
		return M - m;
	}
};

int main(){  
    FIN;

	int tc; cin >> tc;

    while(tc--){
    	st a;
    	int q; cin >> q;
    	// dbg(q);
    	forn(i, q){
    		ll tipo; cin >> tipo;
    		if(tipo == 1){
    			ll x; cin >> x;
    			a.push(x);
    		}
    		if(tipo == 2){
    			a.pop();
    		}
    		if(tipo == 3){
    			if(a.empty()) cout << "Empty!\n";
    			else{
    				cout << a.query() << "\n";
    			}
    		}
    	}
    }    
    
    return 0;
}
