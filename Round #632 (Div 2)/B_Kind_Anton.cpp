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

int main(){
    FIN;
    int test; cin >> test;
	while(test--)
	{
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		forn(i,n) cin >> a[i];
		forn(i,n) cin >> b[i];
		if(a[0] != b[0])
		{
			cout << "NO\n"; continue;
		}
		vector <bool> vv(10,false);
		vv[a[0]+1]=true;
		bool dd=true;
		forr(i,1,n)
		{
			if(a[i] < b[i] && vv[2]==false) dd=false;
			if(a[i] > b[i] && vv[0]==false) dd=false;
			vv[a[i]+1]=true;
		}
        
		if(dd==true) cout << "YES\n";
		else cout << "NO\n";
	}
	
    return 0;
}

