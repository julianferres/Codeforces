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


int main(){  
    FIN;

    int n, m; cin >> n >> m;
    vi v(n);
    vii a(n); forn(i, n){ cin >> a[i].first; a[i].second = i; v[i] = a[i].first; }
    sort(all(a));
    
    int rounds_act = 1;
    forn(i, n-1) if(a[i].second > a[i+1].second) rounds_act++;
    //dbg(a);

    forn(i, m){
        int index_a, index_b; cin >> index_a >> index_b; index_a--, index_b--;
        int x = v[index_a], y = v[index_b];

        int d1 = 0, d2 = 0, d3 = 0, d4 = 0;

        if(x > 1){
            d1 = (int) (index_b < a[x-2].second) - (int) (index_a < a[x-2].second);
        }
        if(x < n){
            d2 = (int) (index_b > a[x].second) - (int) (index_a > a[x].second);
        }
        if(y > 1){
            d3 = (int) (index_a < a[y-2].second) - (int) (index_b < a[y-2].second);
        }
        if(y < n){
            d4 = (int) (index_a > a[y].second) - (int) (index_b > a[y].second);
        }
        if(abs(x - y) == 1){ d1++; }
        rounds_act += (d1 + d2 + d3 + d4);
    
        dbg(x, y, d1, d2, d3, d4);
        cout << rounds_act << "\n";

        a[x-1].second = index_b;
        a[y-1].second = index_a;
        swap(v[index_a], v[index_b]);
    }


    return 0;
}
