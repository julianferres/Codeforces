/* AUTHOR: julianferres */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int MAXN  = 1e5+5;

int n, m;
vi din(MAXN), groups[MAXN], res, g[MAXN];
queue<ll> head;

struct DSU {
    int par[MAXN], sz[MAXN];
    
    DSU() {
        forn(i,MAXN) par[i] = i, sz[i] = 1;
    }
    
    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]);
        return par[x];
    }
    
    void join(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x,y);
        sz[x] += sz[y], par[y] = x;
    }
};

DSU dsu;

bool toposort(int des) {
    res.clear();
    while (head.size()) {
        ll v = head.front(); head.pop();
        res.pb(v);
        for(ll u: g[v]) {
            din[u]--;
            if (!din[u]) head.push(u);
        }
    }
    return (int) res.size() == des;
}



int main(){  
    FIN;

    cin >> n >> m;

    forn(i, m){
        int a, b; cin >> a >> b;
        dsu.join(a, b);
        din[b]++; g[a].pb(b);
    }

    forr(i, 1, n+1) groups[dsu.find(i)].pb(i);

    int ans = 0;

    forr(i, 1, n+1){
        if(groups[i].size()){
            for(ll j: groups[i])
                if(!din[j]) head.push(j);
            if(toposort((int) groups[i].size())) ans += (int) groups[i].size() - 1;
            else ans += (int) groups[i].size();
        }
    }

    
    cout << ans << endl;

    return 0;
}