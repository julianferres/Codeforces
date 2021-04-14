/*   AUTHOR: julianferres   */
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
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
int MOD;
const int MAXN  = 2e5+5;


using namespace __gnu_pbds;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main(){  
    FIN;

    int n, k; cin >> n >> k;

    indexed_set s; forr(i, 1, n+1) s.insert(i);

    int pt = 0;
    vi ans;


    forn(i, n){
        pt = (pt + k)%(n - i);
        auto it = s.find_by_order(pt);
        ans.pb(*it);
        s.erase(it);
    }

    forn(i, n) cout << ans[i] << " \n"[i == n-1];

    return 0;
}
