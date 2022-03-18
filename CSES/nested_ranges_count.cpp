/*   AUTHOR: julianferres   */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

typedef int ll;
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

struct range{
    int l, r, idx;
};
int cmp_outside(range a, range b){
    if(a.l != b.l) return a.l < b.l;
    if(a.r != b.r) return b.r < a.r;
    assert(false); // cant have repeated ranges
}

int cmp_inside(range a, range b){
    if(a.r != b.r) return b.r < a.r;
    if(a.l != b.l) return a.l < b.l;
    assert(false);
}

typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main(){
    FIN;

    int n; cin >> n;
    vector<range> a(n); forn(i, n) cin >> a[i].l >> a[i].r, a[i].idx = i;
    sort(all(a), cmp_outside);
    vi outside(n), inside(n);

    indexed_set open;

    forn(i, n){
        if(open.size() && (--open.end())->first >= a[i].r)
            outside[a[i].idx] = open.size() - open.order_of_key({a[i].r, -1});
        open.insert({a[i].r, i});
    }
    open.clear();
    sort(all(a), cmp_inside);

    forn(i, n) open.insert({a[i].l, a[i].idx});

    forn(i, n){
        open.erase({a[i].l, a[i].idx});
        if(open.size() && (--open.end())->first >= a[i].l)
            inside[a[i].idx] = open.size() - open.order_of_key({a[i].l, -1});
        // cerr << open << open.order_of_key({a[i].l, -1})  << " " << a[i].l << " " << a[i].idx << endl;
    }

    forn(i, n) cout << inside[i] << " \n"[i == n-1];
    forn(i, n) cout << outside[i] << " \n"[i == n-1];

    return 0;
}
