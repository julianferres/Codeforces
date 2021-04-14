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
const int MAXN  = 7;

void solve_test(int tc){
	int n, c; cin >> n >> c;
    int copia_costo = c;
    
    if(c < n-1 || c > n * (n+1)/2 - 1){
        cout << "Case #" << tc << ": IMPOSSIBLE\n";
        return;
    }


    vi a; forr(i, 1, n+1) a.pb(i);
    bool girado = false;
    int l = 0, r = n-1;

    while(l < r - 1){
        int costo_sacar = r - l + 1;
        if(r - l - 1 <= c - costo_sacar){
            // dbg(respuesta"Entro");
            reverse(a.begin() + l, a.begin() + r + 1);
            girado ^= 1;
            c -= costo_sacar;
            // r--;
            if(girado) r--;
            else l++;
        } else {
            // l++;
            if(girado) r--;
            else l++;
            c--;
        }
    }

    if(cost(a) != copia_costo){
        cout << "Case #" << tc << ": IMPOSSIBLE\n";
    } else{
        cout << "Case #" << tc << ": ";
        for(auto x: a) cout << x << " ";
        cout << "\n";
    }

}


int main(){  
    FIN;

    int t; cin >> t;
    forr(tc, 1, t+1){
    	solve_test(tc);
    }

    return 0;
}


