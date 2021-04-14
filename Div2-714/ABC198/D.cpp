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

void NO(){ cout << "UNSOLVABLE\n"; }

int main(){  
    FIN;

    string s1, s2, s3; cin >> s1 >> s2 >> s3;

    set<char> alphabet;
    for(char c: s1) alphabet.insert(c);
    for(char c: s2) alphabet.insert(c);
    for(char c: s3) alphabet.insert(c);
    
    if(alphabet.size() >= 11){
    	NO();
    	return 0;
    }

    vi letras; for(char c: alphabet) letras.pb(c);

    vi permutation(10); iota(all(permutation), 0);

    while(next_permutation(all(permutation))){
    	map<char, int> m;
    	forn(i, letras.size()) m[letras[i]] = permutation[i];


    	if(m[s1[0]] == 0 || m[s2[0]] == 0 || m[s3[0]] == 0)
    		continue;

    	ll n1 = 0, n2 = 0, n3 = 0;

    	forn(i, s1.size()) n1 = 10*n1 + m[s1[i]];
    	forn(i, s2.size()) n2 = 10*n2 + m[s2[i]];
    	forn(i, s3.size()) n3 = 10*n3 + m[s3[i]];

    	// if(permutation[0] == 1 && permutation[1] == 2 && permutation[2] == 3)
    	// 	dbg("Hola");

    	if(n1 + n2 == n3){
    		cout << n1 << endl << n2 << endl << n3;
    		return 0;
    	}

    }
    NO();

    return 0;
}
