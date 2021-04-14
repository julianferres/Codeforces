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
const ll INF = 2e14;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

string to_base_9(ll n){
	string s = "";
	while(n){
		s += (n%9) + '0';
		n /= 9;
	}
	reverse(all(s));
	return s;
}

vector <int> to_str(ll n) {
  vector <int> ans;
  while(n) {
    ans.pb(n%10);
    n /= 10;
  }
  reverse(all(ans));
  return ans;
}

ll check(ll n) {
  vector <int> num = to_str(n);
  //~ for(int u : num) cout << u; cout << "\n";
  int tam = num.size();
  ll total = 0, aux = 9;
  forn(i,tam-1) {
    total += aux;
    aux = aux*9;
  }

  aux = 1;
  forn(i,tam-1) aux *= 9;
  ll z = 1;
  for(int u : num) {
    if(u == 0) {z = 0; break;}
    forr(i,1,u) {
      total += aux;
    }
    aux /= 9;
  }
  total += z;
  
  return total;
}

ll solve_zero(ll n) {
  ll a = 0, b = INF;
    while(b-a > 1) {
       ll mid = (a+b)/2;
       ll z = check(mid);
       if(z >= n) b = mid;
       else a = mid;
    } 
  return b;
  
}


void solve_non_zero(ll n, ll k){
	assert(k != 0);
	string ans = to_base_9(n);
	// dbg(ans);
	forn(i, ans.size()){
		if(ans[i] - '0' >= k) ans[i]++;
	}

	cout << ans << "\n";

}


int main(){  
    FIN;

    ll n, k; cin >> n >> k;

    if(k == 0){
    	cout << solve_zero(n) << endl; 
    } else {
    	solve_non_zero(n, k);
    }

    return 0;
}
