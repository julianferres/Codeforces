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

int is_pass(int i, int j, vector <vector <ll> > &v, int n, int m) {
  int ans = 0;
  if(i+1 < n && j+1 < m && i-1 >= 0 && j-1 >= 0) {
    if(v[i+1][j] == -1 || v[i-1][j] == -1 || v[i][j-1] == -1 || v[i][j+1] == -1)
      ans = 0;
    else if(v[i+1][j] > v[i][j] && v[i-1][j] > v[i][j] && v[i][j-1] < v[i][j] && v[i][j+1] < v[i][j]) {
      ans = 1;
    }
  }
  return ans;
}

int main(){
  FIN;
    
  
  int r, c, k;
  cin >> r >> c >> k;
  vector <vector <ll> > v(r,vector<ll>(c));
  forn(i,r) {
    forn(j,c) cin >> v[i][j];
  }
  
  //~ forn(i,r) {
    //~ forn(j,c) {
      //~ cout << v[i][j] << " ";
    //~ }  cout << "\n";
  //~ }
  
  ll dp[r+1][c+1][13];
  
  forr(i,0,r+1) {
    forr(j,0,c+1) {
      forr(z,0,k+2) {
        dp[i][j][z] = INF;
      }
    }
  }
  
  forn(i,r+1) {
    dp[i][0][0] = 0;
  }
  
  forn(j,c) {
    forn(i,r) {
      if(v[i][j] == -1) continue;
      int p = is_pass(i,j,v,r,c);
      
      forn(z,k+1) {
        if(i-1 >= 0) {
          dp[i-1][j+1][z+p] = min(dp[i-1][j+1][z+p], dp[i][j][z] + v[i][j]);
        }
        if(i+1 < r) {
          dp[i+1][j+1][z+p] = min(dp[i+1][j+1][z+p], dp[i][j][z] + v[i][j]);
        }
        dp[i][j+1][z+p] = min(dp[i][j+1][z+p], dp[i][j][z] + v[i][j]);
      }
    }
  }
  ll ans = INF;
  
  //~ forn(i,r) {
    //~ forn(j,c) {
      //~ cout << dp[i+1][j+1][k] << " ";
    //~ } cout << "\n";
  //~ }
  
  forn(i,r) {
    if(dp[i+1][c][k] == -1) continue;
    ans = min(ans,dp[i+1][c][k]);
  } 
  
  if(ans == INF) cout << "impossible\n";
  else cout << ans << "\n";
  
    
  return 0;
}
