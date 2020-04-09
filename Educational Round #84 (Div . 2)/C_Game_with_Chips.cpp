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
const int INF = 2000000000;
#define MOD 1000000007
#define MAXN 200005



struct target
{
	int xi, yi, xf, yf;
};

int main()
{ 
	FIN;
	int n, m, k;
	cin >> n >> m >> k;
	vector <target> a(k);
	forn(i,k) cin >> a[i].xi >> a[i].yi;
	forn(i,k) cin >> a[i].xf >> a[i].yf;
	vector <char> ans;
	forn(i,n-1) ans.pb('D');
	forn(i,m-1) ans.pb('R');
	forn(i,n)
	{
		forn(j,m-1)
		{
			if(i%2==0) ans.pb('L');
			else ans.pb('R');
		}
		ans.pb('U');
	}
	cout << ans.size() << "\n";
	for(auto u : ans) cout << u;
	cout << endl;
	
	return 0;
}