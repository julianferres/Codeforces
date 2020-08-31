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
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MOD 1000000007
#define MAXN 200005
#define INF 1e18

vi v[30];
vector <bool> seen(30,false);
string ans;

void DFS(int n)
{
	ans.pb('a'+n);
	seen[n]=true;
	for(auto u : v[n])
	{
		if(seen[u]==false) DFS(u);
	}
}

int main()
{
	FIN;
	#ifdef input
		freopen("test1.txt", "r", stdin);
	#endif
	int t;
	cin >> t;
	while(t--)
	{
		string pal;
		cin >> pal;
		ans.clear();
		forn(i,30) v[i].clear();
		forn(i,30) seen[i]=false;
		bool matriz[30][30];
		memset(matriz,false,sizeof(matriz));
		forn(i,pal.size())
		{
			if(i==0) continue;
			if(pal[i]==pal[i-1]) continue;
			if(matriz[pal[i]-'a'][pal[i-1]-'a']==true) continue;
			v[pal[i]-'a'].pb(pal[i-1]-'a');
			v[pal[i-1]-'a'].pb(pal[i]-'a');
			matriz[pal[i]-'a'][pal[i-1]-'a']=true;
			matriz[pal[i-1]-'a'][pal[i]-'a']=true;
		}
		
		bool d=true;
		forn(i,26)
		{
			/*cout << i << " - "; 
			for(auto u : v[i]) cout << u << " ";
			cout << endl;*/
			if(v[i].size() > 2) {d=false;}
		}
		if(d==false) {cout << "NO\n"; continue;}
		
		forn(i,26)
		{
			if(seen[i]==false && v[i].size()<=1)
			{
				DFS(i);
			}
		}
		if(ans.size()==26) {cout << "YES\n"; cout << ans << "\n"; continue;}
		else cout << "NO\n";
		
	}
	
    return 0;
}