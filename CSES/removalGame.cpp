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
typedef vector<vi> vvi;

vvi dp;
vi a;

ll rec(int l, int r){
    if(l > r) return 0;
    if(dp[l][r] != -INF) return dp[l][r];
    ll tomar_izq = min(a[l] + rec(l + 2, r), a[l] + rec(l + 1, r - 1));
    ll tomar_der = min(a[r] + rec(l, r - 2), a[r] + rec(l + 1, r - 1));

    return dp[l][r] = max(tomar_izq, tomar_der);
}

int main(){  
    FIN;

    int n; cin >> n;

    a.resize(n);
    forn(i, n) cin >> a[i];

    dp.resize(n, vi(n, -INF));
    forn(i, n) dp[i][i] = a[i]; 
    cout << rec(0, n-1) << endl;



    return 0;
}
