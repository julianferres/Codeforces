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


void set_min(ll &a, ll b){
	a = min(a, b);
}





ll solve_test(){
	int x, y; cin >> x >> y;
	string s; cin >> s;
	int n = (int) s.size();

	vi dp_c(n, INF), dp_j(n, INF);
	if(s[0] != 'C') dp_j[0] = 0;
	if(s[0] != 'J') dp_c[0] = 0;

	forr(i, 1, n){
		if(s[i] == '?'){
			set_min(dp_c[i], min(dp_c[i-1], dp_j[i-1] + y));
			set_min(dp_j[i], min(dp_j[i-1], dp_c[i-1] + x));
		} else if (s[i] == 'C'){
			set_min(dp_c[i], min(dp_c[i-1], dp_j[i-1] + y));
		} else{
			assert(s[i] == 'J');
			set_min(dp_j[i], min(dp_j[i-1], dp_c[i-1] + x));
		}
	}

	return min(dp_c[n-1], dp_j[n-1]);
}

int main(){  
    FIN;

    int tc; cin >> tc;
    forr(t, 1, tc+1){
		cout << "Case #" << t << ": " << solve_test() << "\n";
    }
    
    return 0;
}