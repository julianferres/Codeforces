/*    AUTHOR: julianferres, dom 16 ago 2020 12:25:37 -03 */
#include <bits/stdc++.h>
using namespace std;
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
#define DBG(x) cerr << #x << " = " << (x) << endl
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 1<<30; // const ll INF = 1LL<<60;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

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


int main(){  
    FIN;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        bool todos_iguales = true;
        forn(i, n) if(s[i] != s[(i+1)%n]) todos_iguales = false;
        if(todos_iguales){
            cout << (n-1)/3+1 << "\n";
        }
        else{
            vi bloques;
            ll act = 1;
            ll i = 1;
            while(i<n){
                if(s[i]!=s[i-1]){
                    bloques.pb(act);
                    act = 1;
                }
                else
                   act++;
                i++;
            }
            if(s[n-1] == s[0]) bloques[0] += act;
            else bloques.pb(act);

            debug() << imie(bloques);

            ll ans = 0;
            forn(i, bloques.size()) ans += bloques[i]/3;
            cout << ans << "\n";
        }
    }
        

    return 0;
}
