/* AUTHOR: julianferres */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1e9+10; // const ll INF = 1e18+10;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 105;

int n;
string s;
int go[MAXN][26];
vector<int> dp(MAXN);

int main() {
    FIN;

    cin >> n >> s;
    forn(i, s.size()){
        string t = s.substr(0,i);
        forn(j, 26){
            string T = t+char('A'+j);
            while (T != s.substr(0,T.size())) T = T.substr(1,T.size()-1);
            go[i][j] = (int) T.size();
        }
    }
    dp[0] = 1;
    forn(i,n) {
        vector<int> aux_dp(MAXN);
        forn(j,s.size()) forn(k,26) aux_dp[go[j][k]] = (aux_dp[go[j][k]]+dp[j]) % MOD;
        aux_dp[s.size()] = 0;
        dp = aux_dp;
    }
    ll ans = 1; forn(i,n) ans = 26*ans % MOD;
    forn(i,s.size()) ans = (ans+MOD-dp[i]) % MOD;


    cout << ans << endl;
}