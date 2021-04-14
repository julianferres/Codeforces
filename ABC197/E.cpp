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
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;


int main(){  
    FIN;

    vi colores[MAXN];

    int n; cin >> n;

    forn(i, n){
    	int xi, ci; cin >> xi >> ci;
    	colores[ci].pb(xi);
    }
    colores[0].pb(0), colores[n+1].pb(0);
    forn(i, MAXN) sort(all(colores[i]));

    vi dp_l(n+2), dp_r(n+2);
    int arranco1 = 0, arranco2 = 0;

    forr(i, 1, n+2){
    	if(!colores[i].size()){
    		dp_l[i] = dp_l[i-1];
    		dp_r[i] = dp_r[i-1];
    	} else {

    		dp_r[i] = dp_r[i-1] + abs(arranco2 - colores[i][0]) + abs(colores[i][colores[i].size()-1] - colores[i][0]);
    		dp_r[i] = min(dp_r[i], dp_l[i-1] + abs(arranco1 - colores[i][0]) + abs(colores[i][colores[i].size()-1] - colores[i][0]));
    		dp_l[i] = dp_r[i-1] + abs(arranco2 - colores[i][colores[i].size()-1]) + abs(colores[i][colores[i].size()-1] - colores[i][0]);
    		dp_l[i] = min(dp_l[i], dp_l[i-1] + abs(arranco1 - colores[i][colores[i].size()-1]) + abs(colores[i][colores[i].size()-1] - colores[i][0]));

    		arranco1 = colores[i][0];
    		arranco2 = colores[i][colores[i].size() - 1];
    	}
    }

    cout << dp_l[n+1] << "\n";

    // forn(i, n+2){
    // 	dbg(dp_l[i], dp_r[i]);
    // }

    return 0;
}

