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
const int INF = 2000000000;
#define MOD 1000000007
#define MAXN 200005

int main()
{ 
	FIN;
	
	int test;
	cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		int pos;
		vector <int> visto(n+10,false);
		forn(i,n)
		{
			int k; cin >> k;
			vector <int> v(k);
			bool d=false;
			forn(j,k) 
			{
				cin >> v[j];
				if(visto[v[j]]==false && d==false)
				{
					d=true;
					visto[v[j]]=true;
				}
			}
			if(d==false)
			{
				pos=i+1;
			}
		}
		bool respuesta = true;
		for(int i =1; i<=n; i++)
		{
			if(visto[i]==false && respuesta==true)
			{
				respuesta=false;
				cout << "IMPROVE\n";
				cout << pos << " " << i << "\n";
			}
		}
		if(respuesta == true) cout << "OPTIMAL\n";
		
		
	}
	return 0;
}