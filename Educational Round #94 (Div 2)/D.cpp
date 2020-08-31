/*    AUTHOR: julianferres, mar 25 ago 2020 02:36:01 -03 */
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
const int MAXN  = 2e5+5;

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
  for (t[p += tam] += value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
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

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int>a(n); forn(i, n) cin >> a[i];
        
        vector<pair<int, int>> pares;
        forn(i, n)
            forr(j, i+1,n)
                if(a[i] == a[j]) pares.pb({i,j});
        sort(all(pares));

        ll ans = 0;
        vi v(n+10); build(v, n+10);
        vi cnt(n+10);

        for(pair<int, int> par: pares){
            ans += query(par.first,par.second) - cnt[par.second] - cnt[par.first];
            cnt[par.second]++;
            modify(par.second, 1);
            modify(par.first, -1);
        }
        cout << ans << "\n";
    }

    return 0;
}
