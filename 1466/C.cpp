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

    int tc; cin >> tc;
    while(tc--){
    	string s; cin >> s;
    	int n = (int) s.size();

    	// int cnt = 1;
    	// vi grupos;
    	// while(i < n){
    	// 	int j = i+1;
    	// 	while(j < n && s[j] == s[i]) j++;
    	// 	grupos.pb(j - i);
    	// 	i = j, cnt = 1;
    	// }
    	ll ans = 0;

    	forn(i, n){
    		if(i == 0) continue;
    		if(s[i] == s[i-1]){
    			forn(j, 26){
    				char act = (char)(j + 'a');
    				if((i-2 >= 0 && s[i-2] == act) || (i-1 >= 0 && s[i-1] == act)) continue;
          			if((i+1 < n && s[i+1] == act) || (i+2 < n && s[i+2] == act)) continue;
          			s[i] = act; ans++;
          			break;
    			}
    		}
    		if(i-2 >= 0 && s[i-2] == s[i]) {
		        forn(j,26) {
					char act = (char)(j + 'a');
					if((i-2 >= 0 && s[i-2] == act) || (i-1 >= 0 && s[i-1] == act)) continue;
					if((i+1 < n && s[i+1] == act) || (i+2 < n && s[i+2] == act)) continue;
					s[i] = act; ans++;
					break;
		        }
      		}
    	}



    	cout << ans << "\n";
    }

    

    return 0;
}


