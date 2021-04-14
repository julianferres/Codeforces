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
    	bool pos = false;

    	vi zeroes; forn(i, n) if(s[i] == '0') zeroes.pb(i);
    	vi ones; forn(i, n) if(s[i] == '1') ones.pb(i);

    	bool all_zeroes = true;
    	forn(i, zeroes.size() - 1){
    		if(zeroes[i] + 1 == zeroes[i+1]){
    			all_zeroes = false;
    		}
    	}

    	bool all_ones = true;
    	forn(i, ones.size() - 1){
    		if(ones[i] + 1 == ones[i+1]){
    			all_ones = false;
    		}
    	}

    	if(ones.size() == 0 || zeroes.size() == 0 || all_zeroes || all_ones){
    		cout << "YES\n";
    		continue;
    	}

    	for(auto last_zero : zeroes){
    		if(pos){ break; }
    		vi to_delete;
    		forn(i, n){
    			if(i < last_zero && s[i] == '1'){
    				to_delete.pb(i);
    			} 
    			if(i > last_zero && s[i] == '0'){
    				to_delete.pb(i);
    			}
    		}
    		bool act = true;
    		forn(i, to_delete.size() - 1){
	    		if(to_delete[i] + 1 == to_delete[i+1]){
	    			act = false;
	    		}
    		}
    		pos |= act;
    	}

    	for(auto first_one: ones){
    		if(pos){ break; }
    		vi to_delete;
    		forn(i, n){
    			if(i < first_one && s[i] == '1'){
    				to_delete.pb(i);
    			} 
    			if(i > first_one && s[i] == '0'){
    				to_delete.pb(i);
    			}
    		}
    		bool act = true;
    		forn(i, to_delete.size() - 1){
	    		if(to_delete[i] + 1 == to_delete[i+1]){
	    			act = false;
	    		}
    		}
    		pos |= act;
    	}

    	cout << (pos ? "YES": "NO") << "\n";
    }

    

    return 0;
}
