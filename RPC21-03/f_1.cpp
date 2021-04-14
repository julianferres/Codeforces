#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define forr(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===========================" << endl

ll INF = (ll)(1e18+7);

typedef ll tipo;
const int MAXN = 1005;
 
struct arista {
  // x -> next node, w = weight  
  int x; tipo w; 
};
 
struct nodo {
   // d -> distance, v -> actual node, a = previous node
   tipo d, v, a;
   bool operator<(const nodo& x) const {return d > x.d;}
};

vector <nodo> Dijkstra(int start, vector < vector<arista> > &g) {
  vector <nodo> ans(MAXN);
  vector <bool> visto(MAXN,false);
  priority_queue <nodo> p; p.push({0,start,-1});
  while(!p.empty()) {
    nodo it=p.top(); p.pop();
    if(visto[it.v]==true) continue;
    else {
      ans[it.v] = it; visto[it.v] = true;
      for(arista u : g[it.v]) {
        if(visto[u.x]==false) p.push({it.d + u.w, u.x, it.v});
      }
    }
  }
  return ans;
}

int main() {
  FIN;
  
  ll n, m, p, combi;
  cin >> n >> m >> p >> combi;
  vector <ll> pos(p);
  forn(i,p) cin >> pos[i];
  vector <vector <arista> > g(n+1);
  forn(i,m) {
    int x, y; ll peso;
    cin >> x >> y >> peso;
    g[x].pb({y,peso});
    g[y].pb({x,peso});
  }
  
  vector <vector <nodo> > dist(p);
  
  vector <nodo> desde_uno = Dijkstra(1,g);
  
  forn(i,p) {
    dist[i] = Dijkstra(pos[i],g);
  }
  
  //~ forn(i,p) {
    //~ forr(j,1,n+1) cout << dist[i][j].d << " "; cout << "\n";
  //~ } 
  
  ll ans = INF;
  
  forr(caso,1,n+1) {
    ll suma = 0;
    forn(i,p) {
      if(desde_uno[pos[i]].d == desde_uno[caso].d + dist[i][caso].d) {
        suma += min(dist[i][1].d,dist[i][caso].d + combi);
      } else {
        suma += desde_uno[pos[i]].d;
      }
    }
    ans = min(ans,suma);
    //~ DBG(ans);
    
  }
  
  cout << ans << "\n";
  
  return 0;
}
