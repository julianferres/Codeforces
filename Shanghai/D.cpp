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
const int INF = 2e9+15; // const ll INF = 2e18;
const int MOD = 1e9+7; // 998244353;
const int MAXN  = 2e5+5;
typedef long double ld;
const ld EPS = 1e-7;

ld n, p1, v1, p2, v2;

ld caso1(ld p1, ld v1, ld mid){
	if(mid == p1) return p1/v1;
	else{
		return (2*(min(mid-p1, p1)) + (max(mid-p1, p1)))/v1;
	}
}

ld caso2(ld p2, ld v2, ld mid){
	if(mid == p2) return (n-p2)/v2;
	else{
		return (2*(min(n-p2, p2-mid)) + (max(n-p2, p2-mid)))/ v2;
	}
}

ld caso3(ld p, ld v){
	return (2*min(p, n-p) + max(p, n-p))/v;
}

int main(){  
    FIN;

    int tc; cin >> tc;
    cout << fixed << setprecision(10);
    while(tc--){
    	cin >> n >> p1 >> v1 >> p2 >> v2;
    	if(p1 > p2){
    		swap(p1, p2);
    		swap(v1, v2);
    	}

    	ld l = p1, r = p2;
    	ld ans = INF;
    	// dbg(ans);
    	ans = min(ans, max((n-p1)/v1, p2/v2));
    	ans = min(ans, min(caso3(p1, v1), caso3(p2, v2)));

    	while(fabs(r - l) > EPS){
    		ld mid = (l + r)/2.0;
    		ld t1 = caso1(p1, v1, mid), t2 = caso2(p2, v2, mid);
    		ans = min(ans, max(t1, t2));
    		if(t1 > t2) r = mid;
    		else l = mid;
    	}
    	cout << ans << "\n";

    }

    

    return 0;
}
