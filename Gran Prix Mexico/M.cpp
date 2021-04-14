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

    string s; cin >> s;
    int n = (int) s.size();

    vi borrar(10); forr(i, 1, 10) cin >> borrar[i];
    vi cnt(10); forn(i, n) cnt[s[i] - '0']++;

    string ans;

    forr(j, 1, 10) // Hago limpieza previa
		if(borrar[j] == cnt[j]){
			string new_s;
			forn(k, s.size()) if(s[k] - '0' != j) new_s += s[k];
			s = new_s;
			borrar[j] = cnt[j] = 0;
		}

    while(s.size()){
    	int max_alcanzable = 0;
    	vi prefix(10);
    	prefix[s[0] - '0']++;
    	forr(j, 1, s.size()){
    		bool possible = true; 
    		// dbg(prefix, borrar);
    		forr(k, 1, 10){
    			if(prefix[k] > borrar[k]) possible = 0;
    		}
    		// dbg(possible);
    		if(possible && s[j] > s[max_alcanzable]) max_alcanzable = j;
    		prefix[s[j] - '0']++;

    	}
    	forn(j, max_alcanzable) cnt[s[j] - '0']--, borrar[s[j] - '0']--;
    	cnt[s[max_alcanzable]- '0']--;
    	ans += s[max_alcanzable];
    	dbg(max_alcanzable, s);
    	s = s.substr(max_alcanzable + 1, (n - max_alcanzable));
    	

    	forr(j, 1, 10) // Hago limpieza previa
    		if(borrar[j] == cnt[j]){
    			string new_s;
    			forn(k, s.size()) if(s[k] - '0' != j) new_s += s[k];
    			s = new_s;
    			borrar[j] = cnt[j] = 0;
    		}
    	dbg(s, cnt, borrar);
    }

    cout << ans << endl;    

    return 0;
}
