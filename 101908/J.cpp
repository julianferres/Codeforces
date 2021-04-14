/*   AUTHOR: julianferres   */
#include <bits/stdc++.h>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const ll INF = 2e18;
const int MOD = 1e9+7; // 998244353
const int MAXN = 105;
const int CAPITALS = 10;

typedef long double ld;
typedef vector<ld> vd;

vector<vd> dp;

ll sq(ll x){ return x*x; }
ld dist(ii a , ii b){
    return sqrt(sq(a.first - b.first) + sq(a.second - b.second));
}

int main(){
    FIN;

    ll n, k; cin >> n >> k;
    vii a(n); forn(i, n) cin >> a[i].first >> a[i].second;

    vector<vd> d(n, vd(n, INF));

    forn(i, n) d[i][i] = 0;
    forn(i, n){ forn(j, n){ if(i != j) d[i][j] = dist(a[i], a[j]); } }
    forn(i, n)forn(j, n)forn(l, n) d[i][j] = min(d[i][j], d[i][l] + d[l][j]);

    dp.resize(n, vd(1<<k, INF));
    forr(i, k, n) forn(cap, k) dp[i][(1<<cap)] = min(dp[i][(1<<cap)], d[i][cap]);

    forn(mask, (1<<k)){
        forr(i, k, n){
            ll s = 0;
            do {
            // process subset s
                dp[i][mask] = min(dp[i][mask], dp[i][s] + dp[i][mask^s]);
            } while ((s=(s-mask)&mask));
            forr(j, k, n){
                dp[j][mask] = min(dp[j][mask], dp[i][mask] + d[i][j]);
            }
        }
    }

    // dbg(dpm);

    ld ans = INF;
    forr(i, 0, n) ans = min(ans, dp[i][(1<<k)-1]);
    cout << fixed << setprecision(5) << ans << "\n";

    return 0;
}
