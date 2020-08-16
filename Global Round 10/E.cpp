/*    AUTHOR: julianferres, dom 16 ago 2020 13:05:46 -03 */
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

ll giveGrid(vector<vi> a){
    int n = (int) a.size(); 
    forn(i, n){
        forn(j, a[i].size()) cout << a[i][j] << " ";
        cout << "\n";
    }

    cout.flush();
    ll q; cin >> q;
    return q;
}

int main(){  
    FIN;

    int n; cin >> n;
    vector<vi> g(n, vi(n));

    forr(j,1, n){
        g[0][j] = (1LL<<(j-1));
        forr(i, 1, n)
            g[i][j] = g[i-1][j]<<1;
    }
    forn(j,n) forn(i, n) if(!(j&1)) g[i][j] = 0;

    ll q = giveGrid(g);

    forn(iiiii, q){
        ll suma; cin >> suma;
        vii path;
        ll acti = 0, actj = 0;
        
        forn(i, 2*n-1){ 
            path.pb({acti, actj});
            if((actj&1)){ //0 der
                if((suma&1)){
                    acti++;
                }
                else{
                    actj++;
                }
            }
            else{ //0 down
                if((suma&1)){
                    actj++;
                }
                else{
                    acti++;
                }
            } 
            suma>>=1;
        }
        forn(i, path.size()){
            cout << path[i].first+1 << " " << path[i].second+1 << "\n";
            cout.flush();
        }

    }


    return 0;
}
