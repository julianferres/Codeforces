/* AUTHOR: julianferres */
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1e9+10; // const ll INF = 1e18+10;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

vi depth, hsh;
vi g[MAXN];
map<int, vi>lvl;

void dfs(int v, int p){
    for(int u: g[v]){
        if(u == p) continue;
        dfs(u, v);
        depth[v] = max(depth[v], depth[u] + 1);

    }
    lvl[depth[v]].pb(v);
}


int main(){  
    FIN;

    int tc; cin >> tc;
    while(tc--){

        depth.clear(), hsh.clear();
        forn(i, MAXN) g[i].clear();

        int n; cin >> n;

        forn(i, n-1){
            int a, b; cin >> a >> b;
            g[a].pb(b); g[b].pb(a);
        }
        forn(i, n-1){
            int a, b; cin >> a >> b;
            a += n; b += n;
            g[a].pb(b); g[b].pb(a);
        }

        g[0] = {1, n+1};
        depth.resize(2*n+1);
        hsh.resize(2*n+1);
        lvl.clear();

        dfs(0, -1);

        if(depth[1] != depth[n+1]){
            cout << "NO\n";
            continue;
        }

        for(auto nivel: lvl){
           map<vector<ll>, int> mapa;
            for(int i: nivel.second){
                vector<ll> cur;
                for(int j: g[i]) cur.push_back((ll) 7*n*depth[j]+hsh[j]);
                sort(all(cur));
                if (!esta(cur, mapa)){
                    int s= (int) mapa.size();
                    mapa[cur]=s;
                }
                hsh[i]=mapa[cur];
            } 
        }


        if(hsh[1] == hsh[n+1]){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    

    return 0;
}
