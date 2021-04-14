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

const int MAXN = 1e6+5;
typedef long long tipo;

struct nodo {
  //d -> distance, visto -> seen
  tipo d, p, idx; bool visto;
};

vector<nodo> BFS(int start, int n, vector<vector<int>> g) {
  	vector<nodo> ans(n); queue <int> q;
  	forn(i,n) ans[i] = {INF, -1, i, false};
	ans[start] = {0, -1, start, true}; q.push(start);
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int u : g[v]) {
			if(ans[u].visto) continue;
			ans[u] = {ans[v].d+1, v, u, true}; q.push(u);
		}
	}
  	return ans;
}

int hsh(int i, int j, int w){ return i * w + j; }
ii unhsh(int hs, int w){ return {hs/w, hs%w}; }

bool valid(int i, int j, int w, int h){
	return 0 <= i && i < h && 0 <= j && j < w;
}

int main(){  
    FIN;

    int tc; cin >> tc;
    forr(idCase, 1, tc+1){
    	int w, h; cin >> w >> h;
    	vector<string> a(h); forn(i, h) cin >> a[i];
    	ii start;
    	forn(i, h) forn(j, w) if(a[i][j] == '@') start = {i, j};

    	vector<vector<int>> g(h * w);

    	forn(i, h){
    		forn(j, w){
    			if(a[i][j] == '#') continue;
    			if(valid(i-1, j, w, h) && a[i-1][j] != '#')
    				g[hsh(i, j, w)].pb(hsh(i-1, j, w));
    			if(valid(i+1, j, w, h) && a[i+1][j] != '#')
    				g[hsh(i, j, w)].pb(hsh(i+1, j, w));
    			if(valid(i, j-1, w, h) && a[i][j-1] != '#')
    				g[hsh(i, j, w)].pb(hsh(i, j-1, w));
    			if(valid(i, j+1, w, h) && a[i][j+1] != '#')
    				g[hsh(i, j, w)].pb(hsh(i, j+1, w));
    		}
    	}
    	vector<nodo> distancias = BFS(hsh(start.first, start.second, w), w * h, g);
    	ll max_dist = 0;
    	for(nodo x: distancias){
    		if(x.visto)
    			max_dist = max(max_dist, x.d);
    	}
    	vector<nodo> destinos; 
    	for(nodo x: distancias) 
    		if(x.visto && x.d == max_dist)
    			destinos.push_back(x);

    	cout << "Case " << idCase << ":\n";
    	cout << destinos.size() << " " << destinos[0].d << "\n";
    	forn(i, destinos.size()) dbg(destinos[i].idx);

    	vector<string> caminos;
    	forn(index, destinos.size()){
    		nodo dest = destinos[index];
    		string path = "";
    		while(dest.d > 0){
    			int pos_padre = dest.p, pos_act = dest.idx;
    			if(pos_padre + w == pos_act) path += 'D';
    			if(pos_padre - w == pos_act) path += 'U';
    			if(pos_padre - 1 == pos_act) path += 'L';
    			if(pos_padre + 1 == pos_act) path += 'R';
    			dest = distancias[dest.p];
    		}

    		reverse(all(path));
    		caminos.pb(path);
    	}
    	sort(all(caminos));
    	for(string path: caminos){
    		cout << path << "\n";
    	}
    	dbg("----");
    	dbg("----");


    }
    return 0;
}
