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
const int MOD = 1e9+7; // 998244353;
const int MAXN  = 2e5+5;


int main(){  
    FIN;

    int tc; cin >> tc;
    while(tc--){
        ll n, k; cin >> n >> k;
        ll a[k+1], b[k+1];
        forr(i, 1, k+1) cin >> a[i];
        forr(i, 1, k+1) cin >> b[i];
        ii d[k+10];

        sort(a+1, a+k+1), sort(b+1, b+k+1);

        ll ans = INF;

        forr(offset, 1, k+1){
            ll aux = INF, max_atras = 0;

            forr(i, 1, k+1){
                d[i].first = (a[i] - b[(i + offset)%k + 1] + n) % n;
                d[i].second = n - d[i].first; // Pego la vuelta por el otro lado 
                max_atras = max(max_atras, d[i].second);
            }
            aux = min(aux, max_atras);
            sort(d+1, d+k+1); // Voy viendo que me conviene para cada dist
            d[k+1] = {0, 0};

            forr(i, 1, k+1){
                aux = min(aux, d[i].first * 2 + d[i + 1].second);
                aux = min(aux, d[i].first + d[i + 1].second * 2);
            }
            ans = min(ans, aux);
        }
        cout << ans << "\n";

    }
    

    return 0;
}
