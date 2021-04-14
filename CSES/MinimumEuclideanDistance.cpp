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
const ll INF = 8e18;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;
typedef long double ld;

ll dist2(ii a, ii b){
    auto sq = [&](ll n){ return n * n; };
    return sq(a.first - b.first) + sq(a.second - b.second);
}
ld dist(ii a, ii b){
    return sqrtl(dist2(a, b));
}


int main(){  
    FIN;

    int n; cin >> n;
    vii a(n);
    forn(i, n) cin >> a[i].first >> a[i].second;
    sort(all(a));

    ll ans2 = dist2(a[0], a[1]);
    ld ans = dist(a[0], a[1]);
    set<ii> box = {{a[0].second, a[0].first}};
    int left = 0;

    forr(i, 1, n){
        while(left < i && a[left].first < a[i].first - ceil(ans)){
            ii to_remove = a[left];
            box.erase({to_remove.second, to_remove.first});
            left++;
        }
        for(auto it = box.lower_bound({a[i].second - ans, a[i].first - ceil(ans)}); it != box.end() && it->first <= a[i].second + ceil(ans); it++){
            ii p = {it->second, it->first};
            ans = min(ans, dist(a[i], p));
            ans2 = min(ans2, dist2(a[i], p));
        }
        box.insert({a[i].second, a[i].first});
    }

    cout << ans2 << "\n";

    return 0;
}
