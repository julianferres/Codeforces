/*   AUTHOR: julianferres   */
#include <bits/stdc++.h>
#include <queue>
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
typedef tuple<ll, ll, ll> iii;

ll dist(ii a, ii b){ return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second); }

ld solve(vii judges, vii points){
    priority_queue<iii>d;
    forn(i, judges.size()){
        forn(j, points.size()){
            d.push({-dist(judges[i], points[j]), -i, -j});
        }
    }
    vb used_1(judges.size()), used_2(points.size());

    ld suma = 0.0;

    forn(_, judges.size()){
        ll top_d, top_i, top_j;
        iii top = d.top(); d.pop();
        tie(top_d, top_i, top_j) = top;
        while(used_1[-top_i] || used_2[-top_j]){
            top = d.top(); d.pop();
            tie(top_d, top_i, top_j) = top;
        }
        dbg(top_d, top_i, top_j);
        suma += sqrtl(-top_d);

        used_1[-top_i] = 1;
        used_2[-top_j] = 1;

    }

    return suma;
}


int main(){  
    FIN;

    int n, m, p; cin >> n >> m >> p;

    vii a(n), b(m), c(p);
    forn(i, n) cin >> a[i].first >> a[i].second;
    forn(i, m) cin >> b[i].first >> b[i].second;
    forn(i, p) cin >> c[i].first >> c[i].second;

    cout << fixed << setprecision(10) <<  solve(a, b) + solve(a, c);

    return 0;
}
