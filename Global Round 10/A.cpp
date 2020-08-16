/*    AUTHOR: julianferres, dom 16 ago 2020 11:40:29 -03 */
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

int main(){  
    FIN;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vi a(n); forn(i, n) cin >> a[i];
        ll m=a[0],M=a[0];
        forn(i,n){
            m = min(m, a[i]);
            M = max(M, a[i]);
        }
        if(m!=M) cout << "1\n";
        else cout << n << "\n";
    }
    
    return 0;
}
