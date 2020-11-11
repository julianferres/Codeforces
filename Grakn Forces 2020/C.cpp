/*    AUTHOR: julianferres   */
#include <bits/stdc++.h>
using namespace std;

// DEBUGGER
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
//END DEBUGGER

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;
typedef long double ld;
const ld EPS = 1e-7;

int main(){  
    FIN;

    int tc; cin >> tc;
    while(tc--) {
        int n;
        ld lll;
        cin >> n >> lll;
        vector<ld> arr(n+2); arr[0] = 0; arr[n+1] = lll; forn(i,n) cin >> arr[i+1];
        ld l = 0, r = (ld) INF;
        while(r-l > EPS) {
            ld med = (l+r)/2;
            ld distl = 0, distr = 0; ld sl = 1, sr = 1; ld acuml = 0, acumr = 0;
            forr(i,1,n+2) {
                if((arr[i]-arr[i-1])/sl + acuml < med) {
                    acuml += (arr[i]-arr[i-1])/sl;
                    sl += 1.0; distl += arr[i] - arr[i-1];
                }
                else {
                    distl += sl * (med-acuml);
                    break;
                }
            }
            for(int i = n; i>=0; i--) {
                if((arr[i+1]-arr[i])/sr + acumr < med) {
                    acumr += (arr[i+1]-arr[i])/sr;
                    sr += 1.0; distr += arr[i+1] - arr[i];
                }
                else {
                    distr += sr * (med-acumr); break;
                }
            }

            if(distr >= lll - distl) 
                r = med;
            else
                l = med;
        }
        cout << fixed << setprecision(11) << r << "\n";
    }
    return 0;
}
