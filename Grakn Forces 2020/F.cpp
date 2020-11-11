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

typedef int ll;
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
const int MAXN  = 2e5+5;
const int MAXLOG = 14;

int n;
vb seen;

void solve(vi &a, int l, int r, vector<pair<int,int>> &q){
    if(l + 1 == r){
        q.pb({l, l+1});
        return;
    }
    int med = (l+r)/2;

    solve(a, l, med, q);
    solve(a, med+1, r, q);

    ll offset = (r-l+1)/2;
    debug() << imie(l) imie(r) imie(offset);
    forr(i, l, med+1){
        if( i + offset < n )
            q.pb({i, i + offset});
    }
}

int main(){  
    FIN;

    cin >> n;

    vi a(n); forn(i, n) a[i] = i + 1;
    vector<pair<int, int>>q;
    
    if(n == 1){
        cout << "0\n";
        return 0;
    }

    ll k = 1;
    while((1<<(k+1)) <= n){ k++; }

    solve(a, 0, (1<<k)-1, q);
    solve(a, n-(1<<k), n-1, q);

    cout << q.size() << "\n";
    forn(i, q.size()) cout << q[i].first+1 << " " << q[i].second+1 << "\n";

    return 0;
}
