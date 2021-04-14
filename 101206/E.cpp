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

struct intervalo{
    int l, r;
    
    bool operator <(const intervalo &other) const{
        return r > other.r;
    }
};

int cmp_l(intervalo a, intervalo b){
    if(a.l == b.l) return a.r > b.r;
    return a.l < b.l;
}

int main(){  
    FIN;

    int tc; cin >> tc;
    forr(test_case, 1, tc+1){
        cout << "Case #" << test_case << ": ";

        int n, m; cin >> n >> m;
        vector<intervalo> a(n); 
        forn(i, n) cin >> a[i].l >> a[i].r;
        vi b(m); forn(i, m) cin >> b[i];

        sort(all(a), cmp_l);
        sort(all(b));

        priority_queue<intervalo>q;

        int ans = 0, i = 0;

        forn(j, m){
            while(i < n && a[i].l <= b[j]){
                q.push(a[i++]);
            } // Greedy
            while(!q.empty() && q.top().r < b[j]) q.pop();
            int cantidad = (int) q.size();
            ans = max(ans, n - cantidad + 1);
            if(ans > n) break;
            q.pop();
        }
        
        if(ans > n){
            cout << "IMPOSSIBLE!\n";
        } else{
            cout << ans << "\n";
        }

    }


    return 0;
}

