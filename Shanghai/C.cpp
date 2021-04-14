/*   AUTHOR: julianferres   */
#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v)
    os << sep << x, sep = ", ";
  return os << '}';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail> void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}

#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
#define FIN                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define esta(x, c) ((c).find(x) != (c).end())
const int INF = 1e9 + 15; // const ll INF = 2e18;
const int MOD = 1e9 + 7;  // 998244353;
const int MAXN = 2e5 + 5;
const int MAXBIT = 33;

int X, Y;

ll dp[MAXBIT][2][2][2];
ll x[MAXBIT], y[MAXBIT];

ll rec(int sz, int sx, int sy, int z) {
    if (sz == -1) return 1;
    if (dp[sz][sx][sy][z] != -1) return dp[sz][sx][sy][z];

    int mx = (sx ? x[sz] : 1);
    int my = (sy ? y[sz] : 1);

    ll ans = 0;
    forn(i, mx+1){
        forn(j, my+1){
            if (i & j) continue;
            int cnt = 1;
            
            if (z && (i || j)) cnt = sz + 1;
            ans = (ans + rec(sz-1, sx && i == mx, sy && j == my, z && !i && !j) * cnt % MOD) % MOD;
        }
    }
    return dp[sz][sx][sy][z] = ans;
}

ll solve() {
    memset(dp, -1, sizeof(dp));
    int sz = 0;

    while (X || Y) {
        x[sz] = (X & 1); y[sz] = (Y & 1);
        X >>= 1; Y >>= 1;
        sz++;
    }

    return rec(sz - 1, 1, 1, 1);
}

int main() {

    int tc; cin >> tc;
    while(tc--){
        cin >> X >> Y;

        cout << (solve() - 1 + MOD) % MOD << endl;
    }

    return 0;
}