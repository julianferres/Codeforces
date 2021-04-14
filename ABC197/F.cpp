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
const ll INF = 2e18;
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 1005;

int edges[MAXN][MAXN];

vi g[MAXN*MAXN], h[MAXN];

vector<pair<ll, bool>> dist(MAXN*MAXN, {INF, false});

void bfs(int start, int n) {
  	queue <int> q;
	dist[start] = {0,true};
	q.push(start);
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int u : g[v]) {
			if(dist[u].second) continue;
			dist[u] = {dist[v].first+1, true}; q.push(u);
		}
	}
}


int main(){  
    FIN;

	int n, m; cin >> n >> m;
	memset(edges, -1, sizeof(edges));

	forn(i, m){
		int ai, bi; char ci;
		cin >> ai >> bi >> ci;
		ai--, bi--;
		edges[ai][bi] = ci - 'a';
		edges[bi][ai] = ci - 'a';
		h[ai].pb(bi); h[bi].pb(ai);
	}    

	forn(a, n){
		forn(b, n){
			for(auto c: h[a]){
				for(auto d: h[b]){
					if(edges[a][c] > -1 && edges[a][c] == edges[b][d] && (a != c || b != d)){
						g[a*n + b].pb(c * n + d),						
						g[c*n + d].pb(a * n + b);
					}
				}
			}
		}
	}


	bfs(n-1, n * n);
	ll ans = INF;
	forn(i, n){
		if(!dist[i * n + i].second)
			continue;
		ans = min(ans, 2*dist[i * n + i].first);

	}
	dbg(ans);
	forn(i, n){
		forn(j, n){
			if(i != j && edges[i][j] != -1){
				if(dist[i*n+j].second)
					ans = min(ans, 2*dist[i * n + j].first + 1);
				if(dist[j*n+i].second)
					ans = min(ans, 2*dist[j * n + i].first + 1);
			}
		}
	}


	cout << (ans == INF ? -1 : ans);


    return 0;
}
