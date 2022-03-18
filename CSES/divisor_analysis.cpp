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
const int INF = 1e9+15; // const ll INF = 2e18;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

ll be(ll x, ll y, ll m) {
    if (y == 0) return 1;
    ll p = be(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}

ll inv(ll x) {return be(x,MOD-2, MOD);}
ll mul(ll a, ll b){ return a * b % MOD; }
ll mul(ll a, ll b, ll m){ return a * b % m;}
ll dv(ll a, ll b){ return mul(a, inv(b)); }
ll geom(ll p, ll e){ return dv(be(p, e+1, MOD)-1, p-1); } // 1 + p + p^2 + ... + p^e
ll nC2(ll n){ return (n * (n+1)/2) % (MOD - 1); }

int main(){  
    FIN;

    int n; cin >> n;

    ll count = 1, sum = 1, product = 1;

    vii a(n); forn(i, n) cin >> a[i].first >> a[i].second;

    forn(i, n) count = mul(count, (a[i].second + 1));

    forn(i, n) sum = mul(sum, geom(a[i].first, a[i].second));

    vi pre(n, 1); forr(i, 1, n) pre[i] = pre[i-1] * (a[i-1].second + 1) % (MOD - 1);
    vi pos(n, 1); for(int i = n-2; i >= 0; i--) pos[i] = pos[i+1] * (a[i+1].second + 1) % (MOD - 1);

    forn(i, n) product = mul(product, be(a[i].first, mul(nC2(a[i].second), mul(pre[i], pos[i], MOD-1), MOD-1), MOD));

    cout << count << " " << sum <<  " " << product << endl;

    return 0;
}
