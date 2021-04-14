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
const int MAXN  = 2e5+5;

struct dsu{
    vi link, sz;

    void init(int tam){
        link.resize(tam+1), sz.resize(tam+1);
        forn(i, tam+1) link[i]=i, sz[i]=1;
    }

    ll find(ll x){ return link[x] = (link[x] == x ? x : find(link[x])); }
    bool same(ll a, ll b) { return find(a)==find(b); }

    void join(ll a, ll b) {
        a=find(a), b=find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        sz[a]+=sz[b];
        link[b]=a;
    }
};

struct edge{
    ll a, b, w;

    bool operator <(const edge& other) const {
        return w < other.w;        
    }
};

int main(){  
    FIN;

    int tc; cin >> tc;
    while(tc--){
        
        ll n, m, k; cin >> n >> m >> k;

        vector<edge> edges(m); forn(i, m) cin >> edges[i].a >> edges[i].b >> edges[i].w;

        dsu check_conn; check_conn.init(n);

        forn(i, m){
            if(edges[i].w <= k)
                check_conn.join(edges[i].a, edges[i].b);
        }
        sort(all(edges));
        bool connected = false;
        forr(i, 1, n+1) connected |= (check_conn.sz[i] == n);


        if(!connected){
            vector<edge> aux_edges = edges;
            forn(i, m) aux_edges[i].w = max(0LL, edges[i].w - k);
            dsu MST1; MST1.init(n);

            sort(all(edges));
            ll ans = 0;
            int edges_used = 0;
            forn(i, m){
                if(edges_used > n-1) break;
                if(!MST1.same(aux_edges[i].a, aux_edges[i].b)){
                    MST1.join(aux_edges[i].a, aux_edges[i].b);
                    edges_used++;
                    ans += aux_edges[i].w;
                }
            }
            cout << ans << "\n";
        } else {
            ll ans = INF;
            forn(i, m) ans = min(ans, abs(edges[i].w - k));
            cout << ans << "\n";
        }
    
    }
    

    return 0;
}
