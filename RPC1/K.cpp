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
const int MAXN  = 1e5+5;

typedef long long tipo;
vector <tipo> t;
int tam;
 
void build(vector <tipo> &v, int n) {  // build the tree 
  // root en 1, ojas en el intervalo [tam, 2*tam-1]
  tam = sizeof(int) * 8 - __builtin_clz(n); tam = 1<<tam;
  t.resize(2*tam,0LL);
  forn(i,n) t[tam+i] = v[i];
  for (tipo i = tam - 1; i > 0; i--) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, tipo value) {  // set value at position p
  for (t[p += tam] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
  //Tener cuidado aca, podria ser que en cosas no conmutativas, para p impar: p > p^1.
}

tipo query(int l, int r) {  // sum on interval [l, r]
  tipo res = 0;
  for (l += tam, r += tam; l <= r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (!(r&1)) res += t[r--];
  }
  return res;
}

vi comprimir(vi a, int n){
	vi srt_a = a;
	sort(all(srt_a));
	map<ll, int> mp;
	int cnt = 0;
	forn(i, n){
		if(esta(srt_a[i], mp)) continue;
		else{
			mp[srt_a[i]] = cnt++;
		}
	}

	vi ans(n); forn(i, n) ans[i] = mp[a[i]];
	return ans;
}
 



int main(){  
    FIN;

    int n, k; cin >> n >> k;
    vi a(n); forn(i, n) cin >> a[i];
    a = comprimir(a, n);
    ll max_color = 0;
    forn(i, n) max_color = max(max_color, a[i]);

    vii grupos;
    ll act = a[0], cnt = 1;
    int idx = 1;
    while(idx < n){
    	if(a[idx] != act){
    		grupos.pb({act, cnt});
    		act = a[idx], cnt = 1;
    	} else {
    		cnt++;
    	}
    	idx++;
    }
    grupos.pb({act, cnt});
    int g = (int) grupos.size();

    vi aux(g); forn(i, g) aux[i] = grupos[i].second;
    build(aux, g);

    vector<vector<int>> colores(max_color+1);

    forn(i, g){
    	colores[grupos[i].first].pb(i);
    }

    ll ans = INF;
    dbg(a);

    forn(color, max_color+1){
    	int nn = (int) colores[color].size();
    	vi distancias;
    	forn(i, nn-1) distancias.pb(query(colores[color][i]+1, colores[color][i+1]-1));
    	dbg(color, distancias);
    	// int pa = 0, pb = 0;
    	// while(pb < nn){


    	// 	pb++;
    	// }
    }

    cout << (ans != INF ? ans : -1) << "\n";

    return 0;
}
