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
const int MOD = 1e9+7; // 998244353;
const int MAXN  = 2e5+5;

const int K = 26;
struct Vertex {
    map<string, int> next;
    int to_ignore_sons;
    int sons;
    int leaf;
	
    Vertex() {
    	next.clear();
        leaf = to_ignore_sons = sons = 0;
    }
};

vector<Vertex> trie(1);

void add_string(vector<string> s, int to_ignore) {
    int v = 0;
    for (string ch : s) {
        if (!esta(ch, trie[v].next)) {
            trie[v].next[ch] = trie.size();
            trie.emplace_back();
        }
        trie[v].to_ignore_sons += to_ignore;
        trie[v].sons++;
        v = trie[v].next[ch];
    }
	trie[v].leaf++;
    trie[v].to_ignore_sons += to_ignore;
    trie[v].sons++;
}

int cnt(int node){

	if(trie[node].to_ignore_sons == 0)
		return 0;
	if(trie[node].to_ignore_sons == trie[node].sons)
		return 1;
	if(trie[node].leaf)
		return trie[node].to_ignore_sons;
	int ans = 0;
	for(auto x: trie[node].next){
		ans += cnt(x.second);
	}
	return ans;
}


int main(){  
    FIN;

    int tc; cin >> tc;
    while(tc--){
    	int n, m; cin >> n >> m;
    	trie.clear(); trie.emplace_back();

    	forn(i, n){
    		string s; cin >> s;
    		vector<string> line;
    		string act = "";
    		for(char c: s){
    			if(c != '/') act += c;
    			else{
    				line.pb(act);
    				act = "";
    			}
    		}
    		line.pb(act);
    		add_string(line, 1);
    	}
    	forn(i, m){
    		string s; cin >> s;
    		vector<string> line;
    		string act = "";
    		for(char c: s){
    			if(c != '/') act += c;
    			else{
    				line.pb(act);
    				act = "";
    			}
    		}
    		line.pb(act);
    		add_string(line, 0);
    	}

    	int ans = 0;
    	for(auto x: trie[0].next){
    		ans += cnt(x.second);
    		// dbg(x.second, ans);
    	}
    	cout << ans << "\n";
    }

    // forn(i, trie.size()){
    // 	cerr << trie[i].sons << " "
    // }



    

    return 0;
}
