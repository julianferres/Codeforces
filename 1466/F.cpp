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
const int MAXN  = 5e5+5;

vector <int> link(MAXN), sz(MAXN), unitario(MAXN);

void iniciar(int n) {forn(i,n+1) link[i]=i, sz[i]=1, unitario[i] = 0;}

int find(int x) {
	if(x==link[x]) return x;
	return link[x]=find(link[x]);
}

bool same(int a, int b) {
	return find(a)==find(b);
}

void unite(int a, int b) {
	a=find(a); b=find(b);
	if(sz[a]<sz[b]) swap(a,b);
	sz[a]+=sz[b];
	unitario[a] = (unitario[a] | unitario[b]);
	link[b]=a;
}

ll be(ll x, ll y, ll m) {
    if (y == 0) return 1;
    ll p = be(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}


int main(){  
    FIN;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      

    int n, m; cin >> n >> m;
    ll ans = 0;
    iniciar(m+3);

    vector<bool> used(n);

    forn(i, n){
    	int k; cin >> k;
    	if(k == 2){
    		int a, b; cin >> a >> b;
    		if(same(a, b)) continue;
    		if(unitario[find(a)] && unitario[find(b)]) continue;
    		else{
    			used[i] = 1;
    			unite(a, b);
    			ans++;
    		}
    	} else { // k = 1
    		int a; cin >> a;
    		int par_a = find(a);
    		if(unitario[par_a]) continue;
    		else{
    			used[i] = 1;
    			ans++;
    			unitario[par_a] = 1;
    		}
    	}

    }
    

    cout << be(2, ans, MOD) << " " << ans << "\n";

    ll usados = 0; forn(i, n) usados += used[i];

    // dbg(ans); dbg(usados);
    assert(usados == ans);
    forn(i, n)
    	if(used[i]) cout << i+1 << " ";

    cout << "\n";


    return 0;
}
