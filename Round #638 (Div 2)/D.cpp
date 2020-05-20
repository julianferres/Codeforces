/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
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
const ll inf = 1LL<<62;
const int mod = 1e9+7; // 998244353
const int N  = 2e5+5;

ll pot2(ll n)
{
	ll pot_2 = 0;
	while(n) {pot_2++; n/=2;}
	return pot_2;
}
 
int main() {
    FIN;
    
	int test; cin >> test;
	while(test--){
		ll n; cin >> n;
		if(n<=3){
			cout << "1" << "\n" <<  n-2 << "\n";
			continue;
		}
		
		ll pot_2 = pot2(n);
		pot_2--;
		cout << pot_2 << "\n";
		int act = 1;int actact=1;
		vi v;
		forn(i,pot_2-2)
		{
			v.pb((1<<i));
			act += (1<<(i+1));
			actact = max(actact,(1<<(i+1)));
		}
		int x = (1<<(pot_2-1)); 
		if(2*x >= n-act)
		{
			int y = (n-act)/2;
			int z = (n-act+1)/2;
			//DBG(y); DBG(z);
			v.pb(y-actact); v.pb(z-y);
		}
		else
		{
			v.pb(x-actact);
			v.pb(n-act-2*x);
		}
		for(auto u : v) cout << u << " "; cout << "\n";
	}
	
    return 0;
}
