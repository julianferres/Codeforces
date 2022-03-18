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
};

vector < vector <arista> > g(MAXN);  
vector < arista > todos;
vector <bool> cutpoint(MAXN,false);
vector <int> ans;

vector <bool> visto;
vector <int> tin, low;
int timer;

void IS_CUTPOINT(int x) { cutpoint[x] = true; }

void DFS(int x, int p = -1) {
  visto[x] = true;
  tin[x] = low[x] = timer++;
  int children=0;
  for(arista to : g[x]) {
    if(to.next == p) continue;
    if(visto[to.next]) low[x] = min(low[x], tin[to.next]);
    else {
      DFS(to.next, x);
      low[x] = min(low[x], low[to.next]);
      if(low[to.next] >= tin[x] && p!=-1) IS_CUTPOINT(x);
      ++children;
    }
  }
  if(p == -1 && children > 1) IS_CUTPOINT(x);
}

void find_cutpoints(int n) {
  timer = 0;
  visto.assign(n, false);
  tin.assign(n, -1); low.assign(n, -1);
  forn(i,n) if(!visto[i]) DFS(i);
  forn(i,n) if(cutpoint[i]) ans.pb(i);
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

    find_cutpoints(n);

    cout << ans.size() << "\n";

    for(auto x: ans){
    	cout << x+1 << " ";
    }

    

    return 0;
}
