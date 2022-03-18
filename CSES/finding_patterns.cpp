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

#define RB(x) (x<n?r[x]:0)
void csort(vector<int>& sa, vector<int>& r, int k){
	int n=sa.size();
	vector<int> f(max(255,n),0),t(n);
	forr(i,0,n)f[RB(i+k)]++;
	int sum=0;
	forr(i,0,max(255,n))f[i]=(sum+=f[i])-f[i];
	forr(i,0,n)t[f[RB(sa[i]+k)]++]=sa[i];
	sa=t;
}

vector<int> suffix_array(string& s){ // O(n logn)
	s += '$';
  int n=s.size(),rank;
	vector<int> sa(n),r(n),t(n);
	forr(i,0,n)sa[i]=i,r[i]=s[i];
	for(int k=1;k<n;k*=2){
		csort(sa,r,k);csort(sa,r,0);
		t[sa[0]]=rank=0;
		forr(i,1,n){
			if(r[sa[i]]!=r[sa[i-1]]||RB(sa[i]+k)!=RB(sa[i-1]+k))rank++;
			t[sa[i]]=rank;
		}
		r=t;
		if(r[sa[n-1]]==n-1)break;
	}
	return sa;
}

bool substr_search(string &text, string &pal, vector <int> &sa) {
	int n = text.size(), a = -1, b = n-1;
	while(b-a > 1) {
		int med = (a+b)/2, pos = sa[med]; bool d = false;
    int tam = min((int)pal.size(),int(n-sa[med]));
		string check = text.substr(sa[med],tam);
		if(check < pal) a=med;
		else b = med;
	}
  int tam = min(int(pal.size()),int(n-sa[b]));
	string fin = text.substr(sa[b],tam);
	return fin == pal ? true : false;
}

int main(){  
    FIN;

    string text; cin >> text;
    vector<int> sa = suffix_array(text);

    int tc; cin >> tc;
    while(tc--){
    	string s; cin >> s;
    	cout << (substr_search(text, s, sa) ? "YES\n" : "NO\n");
    }

    return 0;
}
