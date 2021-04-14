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


int main(){  
    FIN;

    int n; cin >> n;
    string s; cin >> s;

    vi dp(26,-1), apertura(26, -1), padre(n, -1), mejor_a(26, -1);

    apertura[s[0] - 'a'] = 0; // Se puede abrir desde s[0]
    mejor_a[s[0] - 'a'] = 0;

    forr(i, 1, n){
    	if(apertura[s[i]-'a'] == -1){ // Primero que abre
    		apertura[s[i]-'a'] = dp[s[i-1]-'a'];
    		mejor_a[s[i] - 'a'] = i;
    	} else {
    		ll aux = apertura[s[i] - 'a'];
    		padre[i] = mejor_a[s[i] - 'a'];
    		if(apertura[s[i]-'a'] < dp[s[i-1]-'a']){
    			mejor_a[s[i]-'a'] = i;
    		}
    		apertura[s[i] - 'a'] = max(dp[s[i-1]-'a'], apertura[s[i]-'a']);
    		dp[s[i]-'a'] = aux + 1;
    	}
    } 
    // dbg(padre);
    vi bloques; 
    int act = n-1;
    while(act > 0){
    	bloques.pb(act - padre[act] + 1);
    	act = padre[act]-1;
    }
    reverse(all(bloques));
    
    ll ans = dp[s[n-1]-'a'];
    cout << ans << "\n";
    if(ans != -1){
	    for(ll x: bloques) cout << x << " ";
   		 cout << "\n";
    }


    return 0;
}
