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


typedef long long tipo;
 
struct segtree {
  struct node {
    tipo ans, l, r; // Poner el neutro del update
    tipo suma_total;
    tipo nomatch = 0; // No match en el intervalo de query
    node base(node aux) {aux.ans = nomatch; aux.suma_total = 0; return aux;} //Poner el neutro de la query
    void set_node(tipo x, tipo pos) {suma_total = x, ans = max(0LL, x), l = r = pos;}; // Assigment
    void combine(node a, node b) {
      suma_total = a.suma_total + b.suma_total; //Operacion de query
      ans = max(a.ans, a.suma_total + b.ans);
      l = min(a.l,b.l); r = max(a.r,b.r);
    }
  };
  vector <node> t; 
    
  node ask(int p, tipo l, tipo r) {
    if(l > t[p].r || r < t[p].l) return t[p].base(t[p]);
    if(l <= t[p].l && t[p].r <= r) return t[p];
    node ans; ans.combine(ask(2*p+1,l,r),ask(2*p+2,l,r));
    return ans;
  }
  
  void update(int p, tipo pos, tipo val) {
    if(t[p].r < pos || t[p].l > pos) return;
    if(t[p].l == t[p].r) { t[p].set_node(val,pos); return; }
    update(2*p+1, pos, val); update(2*p+2, pos, val);
    t[p].combine(t[2*p+1], t[2*p+2]);
  }
  
  void build(tipo a, tipo b, int p, vector <tipo> &v) {
    if(a==b) {t[p].set_node(v[a],a); return;}
    tipo med=(a+b)/2;
    build(a, med, 2*p+1, v); build(med+1, b, 2*p+2, v);
    t[p].combine(t[2*p+1], t[2*p+2]);
  }
  node query(tipo l, tipo r) {return ask(0,l,r);}
  void modificar(tipo pos, tipo val) {update(0,pos,val);}  
  void construir(vector <tipo> &v, int n) { t.resize(4*n); build(0,n-1,0,v); }
};

//~ Range Minimum Query with cont

int main(){  
    FIN;

    int n, q; cin >> n >> q;

    vi a(n); forn(i, n) cin >> a[i];
    segtree st; st.construir(a, n);

    forn(i, q){
        int tipo; cin >> tipo;
        if(tipo == 1){
            int k, u; cin >> k >> u;
            k--;
            st.modificar(k, u);
        } else{
            int a, b; cin >> a >> b;
            a--, b--;
            cout << st.query(a, b).ans << "\n";
        }
    }
    

    return 0;
}
