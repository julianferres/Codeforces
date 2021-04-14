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
const ll INF = (ll)(1e9+10); // (1e18+10)
const int MAXN = (int)(2e5+5);


int main(){
  FIN;
	
  int n, k;
  cin >> n >> k;
  vector <pair<ll,ll> > v(n);
  forn(i,n) cin >> v[i].second >> v[i].first;
  sort(all(v));
  //~ for(pair <ll,ll> u : v) cout << u.first << " " << u.second << "\n";
  ll a = 0, b = (ll)(1e9+7);
  ll acum = 0;
  while(b-a > 1) {
    //~ acum = 0;
    ll med = (a+b)/2;
    int cont = 0;
    forn(i,n) {
      if(v[i].second > v[i].first * med) cont++;
    }
    //~ DBG(cont);
    //~ RAYA;
    if(cont >= k) a = med;
    else b = med;
  }
  cout << b << "\n";
  
	
  return 0;
}
