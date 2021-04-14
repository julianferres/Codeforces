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

typedef int ll;
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
const int MAXN  = 1e5+5;

vi g[MAXN], c(MAXN), cnt(MAXN);
vi ans;

void dfs(int v, int p){
	if(cnt[c[v]] == 0) ans.pb(v+1);
	cnt[c[v]]++;
	for(int u: g[v]){
		if(u == p) continue;
		dfs(u, v);
	}
	cnt[c[v]]--;
}


int main(){  
    FIN;

    int n; cin >> n;
    forn(i, n) cin >> c[i];

    forn(i, n-1){
    	int ai, bi; cin >> ai >> bi;
    	ai--, bi--;
    	g[ai].pb(bi), g[bi].pb(ai);
    }
    dfs(0, -1);
    sort(all(ans));

    for(auto x: ans) cout << x << "\n";

    return 0;
}
