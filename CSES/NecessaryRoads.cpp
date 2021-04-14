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

struct arista {
  int from, next, ind;
  friend ostream& operator<<(ostream &os, const arista& x){
  	return os << "(" << x.from << "," << x.next << "," << x.ind << ")";
  }
};

vector < vector <arista> > g(MAXN);  
vector < arista > todos, ans;

vector <bool> visto;
vector <int> tin, low;
int timer;

void IS_BRIDGE(arista aux) { ans.pb(aux); }

void dfs(int x, int p = -1) {
  visto[x] = true;
  tin[x] = low[x] = timer++;
  for(arista to : g[x]) {
    if(to.next == p) continue;
    if(visto[to.next]) low[x] = min(low[x], tin[to.next]);
    else {
      dfs(to.next, x);
      low[x] = min(low[x], low[to.next]);
      if(low[to.next] > tin[x]) IS_BRIDGE(to);
    }
  }
}

void find_bridges(int n) {
    timer = 0;
    visto.assign(n, false);
    tin.assign(n, -1); low.assign(n, -1);
    forn(i,n) if(!visto[i]) dfs(i);
    
}

void read(int n, int m) {
	forn(i,m) {
		int x, y;
		cin >> x >> y; x--; y--;
		g[x].pb({x,y,(int)i}); g[y].pb({y,x,(int)i});
		todos.pb({x,y,(int)i});
	}
}

int main(){  
    FIN;

    int n, m; cin >> n >> m;
    read(n, m);

    find_bridges(n);

	cout << ans.size() << "\n";
	for(auto x: ans){
		cout << x.next + 1 << " " << x.from + 1 << "\n";
	}    

    return 0;
}
