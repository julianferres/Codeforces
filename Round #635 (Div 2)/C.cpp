/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int inf = 1<<30; // const ll inf = 1LL<<62;
const int mod = 1e9+7; // 998244353
const int N  = 2e5+5;
 
 
vi g[N];
vector <int> d(N,0);
 
void dfs(ll v, ll p)
{
	for(auto u : g[v])
	{
		if(u!=p)
		{
			dfs(u,v);
			d[v]+=d[u]+1;
		}
	}
}
 
 
int main()
{ 
	FIN;
	
	int n, k;
	cin >> n >> k;
	forn(i,n-1)
	{
		int x, y;
		cin >> x >> y;
		x--,y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0,-1);
	priority_queue <pair<int, pair<int,int> >> q;
	q.push(mp(d[0],mp(0,0)));
	ll ans = 0;
	vector <bool> chosen(N,false);
	forn(i,n-k)
	{
		auto x = q.top();
		
		ll peso=x.first;
		ll nodo=x.second.first;
		ll inc=x.second.second;
		q.pop();
		
		ans += peso; 
		
		
		chosen[nodo]=true;
		for(auto u : g[nodo])
		{
			if(chosen[u]==false) q.push(mp(d[u]-(inc+1),mp(u,inc+1)));
		}
		
	}
	cout << ans << endl;
	
	return 0;
}
