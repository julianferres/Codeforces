/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> ii;
#define FIN                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
#define forr(i, a, b) for (int i = (a); i < (int)(b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MAXN 2005
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

vi g[MAXN];
vi ans(MAXN), c(MAXN, 0),size(MAXN,0);
bool pos = true;
vector<bool> vis(MAXN, false);
indexed_set s;
void dfs_size(int v)
{
    vis[v] = true;
    size[v] = 1;
    for (auto u : g[v])
    {
        if (vis[u])
            continue;
        dfs_size(u);
        size[v] += size[u];
    }
}

void dfs(int v)
{
    vis[v] = true;
    if (size[v] < c[v] + 1)
    {
        pos = false;
        return;
    }
    ans[v] = *s.find_by_order(c[v]);
    s.erase(s.find_by_order(s.order_of_key(ans[v])));
    for (auto u : g[v])
    {
        if (vis[u])
            continue;
        dfs(u);
    }
}

int main()
{
    FIN;
    int n;
    cin >> n;
    int root = -1;
    forr(i, 1, n + 1)
    {
        int pi;
        cin >> pi;
        if(pi!=0) g[pi].pb(i), g[i].pb(pi);
        else root = i;
        cin >> c[i];
    }
    forr(i,1,n+1) s.insert(i);
    dfs_size(root);
    forn(i,n+1) vis[i] = false;
    dfs(root);
    if (!pos)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        forr(i, 1, n + 1) cout << ans[i] << " \n"[i == n];
    }
    return 0;
}
