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
const int MAXN  = 1e5+5;

struct arista {
  int from, next, ind;
};

vector < vector <arista> > g(MAXN);  
vector < arista > todos, ans;

vector <bool> visto;
vector <int> tin, low;
vii spanning_edges;
int timer;
bool connected = true;

void IS_BRIDGE(arista aux) { ans.pb(aux); }

void dfs(int x, int p = -1) {
  visto[x] = true;
  tin[x] = low[x] = timer++;
  for(arista to : g[x]) {
    if(to.next == p) continue;
    if(visto[to.next]) low[x] = min(low[x], tin[to.next]);
    else {
      spanning_edges.pb({to.from, to.next});
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
    dfs(0);
    forn(i,n) if(!visto[i]) connected = false;
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

    // dbg(ans.size());
    if(!connected || ans.size() > 0){
    	cout << "IMPOSSIBLE";
    	return 0;
    }
    dbg(spanning_edges);
    assert((int) spanning_edges.size() == n-1);

    set<ii>is_spanning;
    forn(i, n-1){
    	is_spanning.insert(spanning_edges[i]);
    }
    dbg(tin);

    forn(i, m){
    	int src = todos[i].from, dst = todos[i].next;
    	ii act = {src, dst}, rev_act = {dst, src}; 
    	if(esta(act, is_spanning)){
    		cout << src+1 << " " << dst+1;
    	} 
    	else if(esta(rev_act, is_spanning)){
    		cout << dst+1 << " " << src+1;
    	}
    	else if(tin[dst] < tin[src]){
    		cout << src+1 << " " << dst+1;
    	} else {
    		cout << dst+1 << " " << src+1;
    	}
    	cout << "\n";
    }



    return 0;
}
