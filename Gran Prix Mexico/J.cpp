#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
//~ const ll INF = (ll)(1e10+7);
//~ const int MAXN = 400005;
const ll MOD = (ll)(1e9+7);
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define forr(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define forn(i,n) forr(i,0,n)
#define DBG(x) cerr << #x << " = " << x << endl
#define all(c) (c).begin(),(c).end()
#define pb push_back
 
const int MAXN = 1005;
typedef long long tipo;
tipo INF = (tipo)(1e9+7);
 
struct nodo {
  //d -> distance, visto -> seen
  tipo d; bool visto;
};
 
vector <nodo> BFS(int start, int n, vector <vector <int> > g) {
  vector <nodo> ans(MAXN); queue <int> q;
  forn(i,n) ans[i] = {INF,false};
	ans[start] = {0,true}; q.push(start);
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int u : g[v]) {
			if(ans[u].visto) continue;
			ans[u] = {ans[v].d+1, true}; q.push(u);
		}
	}
  return ans;
}
 
struct item { int w, v; };
 
ll knapsack(vector <item> &v, int n, int w) {
	vector <ll> dp(w+1,0), aux(w+1,0);
	forn(i,n) {
		forn(j,w+1) {
			aux[j]=dp[j];
			if(j-v[i].w < 0) continue;
			aux[j]=max(aux[j],dp[j-v[i].w]+v[i].v);
		}
		forn(j,w+1) dp[j]=aux[j];
	}
	ll ans = 0;
	forn(i,w+1) ans=max(ans,dp[i]);
	return ans;
}
 
int main() {
  FIN;
  
  int n, m, k;
  cin >> n >> m >> k;
  vector <vector <int> > g(n);
  forn(i,m) {
    int x, y; cin >> x >> y; x--; y--;
    g[x].pb(y); g[y].pb(x);
  }
  vector <vector <nodo> > dist;
  forn(i,n) {
    dist.pb(BFS(i,n,g));
  }
  
  int o, t; cin >> o >> t;
  //~ DBG(o); DBG(t);
  int ans = 0;
  vector <ll> v(o); 
  forn(i,o) cin >> v[i], v[i]--;
  int cur = 0;
  forn(i,o) {
    ans += dist[cur][v[i]].d;
    cur = v[i];
  }
  ans += dist[cur][0].d;
  if(ans * k > t) {
    cout << "impossible" << "\n";
  }
  
  vector <item> todos(o);
  
  v.pb(0);
  cur = 0;
    //~ DBG("HOLA");
  forn(i,o) {
    int d, precio;
    cin >> d >> precio; d--;
    todos[i].w = (dist[v[i]][d].d + dist[d][v[i+1]].d - dist[v[i]][v[i+1]].d) * k;
    todos[i].v = precio;
  }
 
  int fin = knapsack(todos,todos.size(),t - ans * k);
  cout << fin << "\n";
  return 0;
}