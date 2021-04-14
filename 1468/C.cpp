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
const int MAXN  = 5e5+5;


int main(){  
    FIN;

    int q; cin >> q;

    int nro_cliente = 1;
    vi a(MAXN);
    vector<deque<int>> m(MAXN);
    multiset<int> ms;
    set<int> clientes_restantes;

    forn(_, q){
        int tipo; cin >> tipo;

        if(tipo == 1){
            int mm; cin >> mm;
            a[nro_cliente] = mm;
            m[mm].push_back(nro_cliente);
            ms.insert(mm);
            clientes_restantes.insert(nro_cliente);
            nro_cliente++;
        } else if(tipo == 2){
            int ans = *(clientes_restantes.begin());
            clientes_restantes.erase(ans);
            m[a[ans]].pop_front();
            
            ms.erase(ms.lower_bound(a[ans]));

            cout << ans << " ";
        } else {
            int max_value = *(--ms.end());
            int ans = m[max_value].front();
            clientes_restantes.erase(ans);

            m[max_value].pop_front();

            ms.erase(ms.lower_bound(max_value));

            cout << ans << " ";
        }
        //dbg(ms);
    }
    

    return 0;
}
