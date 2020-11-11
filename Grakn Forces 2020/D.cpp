/*    AUTHOR: julianferres   */
#include <bits/stdc++.h>
using namespace std;

// DEBUGGER
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//END DEBUGGER

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 1e6+5;

vector<vi> g(MAXN);

int main(){  
    FIN;

    int n, m; cin >> n >> m;
    vii a(n), b(m);

    forn(i, n) cin >> a[i].first >> a[i].second;
    forn(i, m) cin >> b[i].first >> b[i].second;

    forn(i, n){
        forn(j, m){
            ll actr = max(0LL, b[j].first - a[i].first + 1);
            ll actu = max(0LL, b[j].second - a[i].second + 1);
            
            g[actr].pb(actu);
        }
    }

    ll maxact = 0, ans = 1e6+5;

    for(ll max_pos = 1e6; max_pos>=0; max_pos--){
        for(ll u : g[max_pos+1]){
            maxact = max(maxact, (ll) u);
        }
        ans = min(ans, maxact + max_pos);
    }

    cout << ans << "\n";


    

    return 0;
}
