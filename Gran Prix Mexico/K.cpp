#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
const ll INF = (ll)(1e10+7);
const int MAXN = 400005;
const ll MOD = (ll)(1e9+7);
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define forr(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define forn(i,n) forr(i,0,n)
#define DBG(x) cerr << #x << " = " << x << endl
#define all(c) (c).begin(),(c).end()
#define pb push_back
 
vector <ll> f;
 
ll be(ll x, ll y, ll m) {
    if (y == 0) return 1;
    ll p = be(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}
 
ll inv_mod(ll x, ll m) {return be(x,m-2,m);}
 
void factorial() { // O(N)
	f.pb(1); forn(i,MAXN) f.pb((f.back()*(ll)(i+1)) % MOD);
}
 
ll combinatorio(ll n, ll m) {
	// Retorna n tomados de a m en O(Log N)
	ll ans = 1; ans *= f[n];
	ans *= inv_mod(f[m],MOD); ans %= MOD;
	ans *= inv_mod(f[n-m],MOD); ans %= MOD;
	return ans;
}
 
int main() {
  FIN;
  
  int t; cin >> t;
  factorial();
  while(t--) {
    ll a, b, c, k, p;
    cin >> a >> b >> c >> k >> p;
    if(p > c) {
      cout << "0\n"; 
      continue;
    }
    if(k-p > a+b) {cout << "0\n"; continue;}
    ll ans = combinatorio(c,p);
    ll aux = combinatorio(a+b,k-p);
    ll z1 = 0, z2 = 0;
    k -= p;
    if(k <= b) z1 = combinatorio(b,k);
    if(a >= k) z2 = combinatorio(a,k);
    aux += (MOD - z1%MOD) % MOD;
    aux += (MOD - z2%MOD) % MOD;
    aux %= MOD;
    ans *= aux; ans %= MOD;
    cout << ans << "\n";
  }
  
  
  
  return 0;
}