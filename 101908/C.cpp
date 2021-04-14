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

vii comprimir(vii a, int n){
    vii aux1, aux2, ans(n);
    forn(i, n) aux1.pb({a[i].first, i}), aux2.pb({a[i].second, i});
    sort(all(aux1)), sort(all(aux2));
    forn(i, n) ans[aux1[i].second].first = i, ans[aux2[i].second].second = i;
    return ans;
}

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



int main(){
    FIN;

    ll X, Y; cin >> X >> Y;
    ll H, V; cin >> H >> V;

    vii lineas_h(H), lineas_v(V);

    forn(i, H) cin >> lineas_h[i].first >> lineas_h[i].second;
    sort(all(lineas_h));
    forn(i, V) cin >> lineas_v[i].first >> lineas_v[i].second;
    sort(all(lineas_v));
    ll vertices = 4 + 2*H + 2*V + H*V, aristas = 2*(H+1) + 2*(V+1);

    //Comprimo coordenadas
    vii h_comp = comprimir(lineas_h, H);
    vii v_comp = comprimir(lineas_v, V);

    /////////////////////////
    vi aux(H), ans_H(H); build(aux, H);
    forn(i, H){
        ans_H[i] += query(h_comp[i].second, H-1);
        modify(h_comp[i].second, 1);
    }
    vi aux2(H); build(aux2, H);
    for(int i = H - 1; i >= 0; i--){
        ans_H[i] += query(0, h_comp[i].second);
        modify(h_comp[i].second, 1);
    }

    forn(i, H) aristas += (V + ans_H[i] + 1);
    ll suma_h = 0; forn(i, H) suma_h += ans_H[i];
    vertices += suma_h /2;

    ////////////////////////
    vi aux3(V), ans_V(V); build(aux3, V);
    forn(i, V){
        ans_V[i] += query(v_comp[i].second, V-1);
        modify(v_comp[i].second, 1);
    }
    vi aux4(V); build(aux4, V);
    for(int i = V - 1; i >= 0; i--){
        ans_V[i] += query(0, v_comp[i].second);
        modify(v_comp[i].second, 1);
    }
    forn(i, V) aristas += (H + ans_V[i] + 1);
    ll suma_v = 0; forn(i, V) suma_v += ans_V[i];
    vertices += suma_v/2;



    cout << 1 + aristas - vertices << "\n";

    return 0;
}
