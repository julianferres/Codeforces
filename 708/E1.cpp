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

int square_free_number(int n){
    int d = 2;
    int ans = 1;
    while(d*d <= n){
        int aux = 0;
        while(n%d == 0){
            aux++;
            n /= d;
        }
        if(aux > 0 && aux & 1) ans *= d;
        d++;
    }
    if(n > 1) ans *= n;
    return ans;    
}

int main(){  
    FIN;

    int tc; cin >> tc;
    while(tc--){
        int n, k; cin >> n >> k;
        vi a(n); forn(i, n) cin >> a[i];
        vi sq_free;
        forn(i, n) sq_free.pb(square_free_number(a[i]));
        int ans = 1;

        unordered_set<int> seen; seen.insert(sq_free[0]);

        forr(i, 1, n){
            if(esta(sq_free[i], seen)){
                ans++;
                seen.clear();
            }
            seen.insert(sq_free[i]);
        }

        cout << ans << "\n";

    }
    

    return 0;
}