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
const int MOD = 1e9+7; // 998244353
const int MAXN  = 5e4+5;
typedef vector<vi> vvi;

vvi g(MAXN), gr(MAXN), g_scc(MAXN);
vb seen_scc(MAXN), visto(MAXN);
vector<int>order, component;
vector<bitset<MAXN>>reachable(MAXN);

void dfs_scc(int v){
    seen_scc[v] = reachable[v][v] = 1;
    for(auto u: g_scc[v]){
        if(!seen_scc[u]) dfs_scc(u);
        reachable[v] |= reachable[u];
    }
}

//scc
vector<vector<int>> ans;
void DFS1 (int v) {
  visto[v] = true;
  for (int u : g[v]) if(!visto[u]) DFS1(u);
  order.pb(v);
}

void DFS2 (int v) {
    visto[v] = true;
  component.pb(v);
  for (int u : gr[v]) if(!visto[u]) DFS2(u);
}

void solve_scc(int n) {
    fill(all(visto),false);
    forn(i,n) if(!visto[i]) DFS1(i);
    fill(all(visto),false);
    forn(i,n) {
        int v=order[n-i-1];
        if(!visto[v]) { 
            DFS2(v);
            ans.pb(component);
            component.clear();
        }
    }
}


int main(){  
    FIN;

    int n, m, q; cin >> n >> m >> q;

    forn(i, m){
    	int a, b; cin >> a >> b;
    	a--, b--;
    	g[a].pb(b); gr[b].pb(a);
    }

    solve_scc(n);
    vector<int> scc_idx(n);
    forn(i, ans.size()){
        for(int j: ans[i]) scc_idx[j] = i;
    }

    forn(i, n){
        for(int j: g[i]){
            if(scc_idx[i] == scc_idx[j]) continue;
            g_scc[scc_idx[i]].pb(scc_idx[j]);
        }
    }


    forn(i, n) if(!seen_scc[scc_idx[i]]) dfs_scc(scc_idx[i]);

    forn(i, q){
        int a, b; cin >> a >> b;
        a--, b--;
        if(scc_idx[a] == scc_idx[b]){
            cout << "YES\n";
        } else{
            cout << (reachable[scc_idx[a]][scc_idx[b]] ? "YES": "NO") << "\n";
        }
    }

}
