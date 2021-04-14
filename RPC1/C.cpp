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
const int MAXN  = 2e5+5;


int main(){  
    FIN;

    int n, m; cin >> m >> n;
    while(!(n == 0 && m == 0)){
    	vi a(m); forn(i, m) cin >> a[i];
    	vi b(n); forn(i, n) cin >> b[i];
        sort(all(a)); sort(all(b));

        int i = 0, j = 0;
        ll ans = 0;
        while(i < m && j < n){
            if(a[i] < b[j]) i++;
            else if(a[i] > b[j]) j++;
            else{
                assert(a[i] == b[j]);
                ans++;
                // dbg(a[i]);
                i++; j++;
            }
        }
        // dbg(ans);

   		cout << m - ans << " " << ans << " " << n - ans << " " <<  n + m - ans << "\n";
   		cin >> m >> n;

    }


    return 0;
}
