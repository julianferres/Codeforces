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
typedef long double ld;
typedef pair<ld, ld> dd;
ld EPS = 1e-6;

ld sq(ld x){ return x * x; }

int count(vii points, dd center, ld r){
    int ans = 0;
    forn(i, points.size()){
        ld dist = sqrtl(sq(center.first - points[i].first) + sq(center.second - points[i].second));
        if(r - dist >= 0 || fabs(r - dist) < EPS) ans++;
    }
    return ans;
}

int process_pair(ii p1, ii p2, ld r, vii points){
    ld q = sqrtl(sq(p2.first - p1.first) + sq(p2.second - p1.second));
    if(q > r*2) return 1;

    dd m = {(p1.first + p2.first) / 2.0, (p1.second + p2.second) / 2.0};

    ld r1x = m.first + sqrtl(r * r - (q / 2) * (q / 2)) * (p1.second - p2.second) / q;
    ld r1y = m.second + sqrtl(r * r - (q / 2) * (q / 2)) * (p2.first - p1.first) / q;

    ld r2x = m.first - sqrtl(r * r - (q / 2) * (q / 2)) * (p1.second - p2.second) / q;
    ld r2y = m.second - sqrtl(r * r - (q / 2) * (q / 2)) * (p2.first - p1.first) / q;

    dd center1 = {r1x, r1y}, center2 = {r2x, r2y};
    
    return max(count(points, center1, r), count(points, center2, r));
}



int main(){  
    FIN;

    ld r; cin >> r;
    int n; cin >> n;
    vii a(n); forn(i, n) cin >> a[i].first >> a[i].second;

    
    int ans = 0;

    forn(i, n){
        forr(j, i+1, n){
            ans = max(ans, process_pair(a[i], a[j], r, a));
        }
    }
    cout << ans << "\n";

    return 0;
}
