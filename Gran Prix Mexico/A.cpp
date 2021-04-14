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

vector <ll> e, d, s;
ll dp[105][15][105];
bool visto[105][15][105];

ll solve(int prob, int chabon, int ener, int n, int p) {
  if(prob == p || chabon == n) return 0LL;
  if(visto[prob][chabon][ener] == true) return dp[prob][chabon][ener];
  visto[prob][chabon][ener] = true;
  if(ener >= d[prob]) {
    dp[prob][chabon][ener] = max(dp[prob][chabon][ener], solve(prob+1,chabon,ener-d[prob],n,p) + s[prob]);
  }
  else {
    dp[prob][chabon][ener] = max(dp[prob][chabon][ener], solve(prob+1,chabon,ener,n,p));
  }
  dp[prob][chabon][ener] = max(dp[prob][chabon][ener], solve(prob,chabon+1,e[chabon+1],n,p));

  return dp[prob][chabon][ener];
}

int main() {
  FIN;
  int n, p; cin >> n >> p;
  e.resize(n+1); d.resize(p+1); s.resize(p+1);


  forn(i, n) cin >> e[i];
  forn(i, p) cin >> d[i];
  forn(i, p) cin >> s[i];

  // dp[problema][chabon][energia]

  memset(dp, 0LL, sizeof(dp));
  memset(visto,false,sizeof(visto));

  solve(0,0,e[0],n,p);
  cout << dp[0][0][e[0]] << "\n";
  return 0;
}
