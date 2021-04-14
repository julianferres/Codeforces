#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
 
typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const ll MOD = (ll)(1e9+7); // 998244353 
#define INF 1e12+5 
typedef long long tipo;
const int MAXN = 300005;

pair<ll,ll> dame(int a)
{
	int dos=0, cinco=0;
	while(a%2==0)
	{
		a/=2;
		dos++;
	}
	while(a%5==0)
	{
		a/=5;
		cinco++;
	}
	if(a==1) return {dos,cinco};
	else return {-1,-1};
}

int main(){
  //FIN;
  int a, n;  
  while(cin >> a)
  {
	  cin >> n;
	  pair<ll,ll> ans=dame(a);
	  if(ans.first==-1) cout << "Precision Error\n";
	  else
	  {
		  cout << max(ans.first*n, ans.second*n) << " " << 5^();
	  }
	
}
  return 0;
}
