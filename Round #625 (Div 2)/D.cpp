/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
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
const int INF = 2000000000;
#define MOD 1000000007
#define MAXN 200005

vii g[MAXN], gt[MAXN];
int n, m;
vi path, d(MAXN, INF), p(MAXN, -1);

void dijkstra(int s)
{
    d.assign(n, INF);
    d[s] = 0;
    priority_queue<ii> q;
    q.push({0, s});
    while (!q.empty())
    {
        int v = q.top().second;
        q.pop();
        for (auto edge : gt[v])
        {
            int to = edge.first;
            ll w = edge.second;

            if (d[v] + w < d[to])
            {
                d[to] = d[v] + w;
                p[to] = 1;
                q.push({-d[to], to});
            }
            else if (d[v] + w == d[to])
                p[to]++;
        }
    }
}

int main()
{
    FIN;
    cin >> n >> m;
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb({b, 1});
        gt[b].pb({a, 1});
    }
    int k;
    cin >> k;
    forn(i, k)
    {
        int ki;
        cin >> ki;
        ki--;
        path.pb(ki);
    }
    int s = path[0], t = path[k - 1];
    dijkstra(t);
    ll minimo = 0, maximo = 0;
    forr(i, 1, path.size()) if (d[path[i]] - d[path[i - 1]] > -1) minimo++;
    forn(i, path.size() - 1) if (p[path[i]] > 1 || d[path[i + 1]] - d[path[i]] > -1) maximo++;

    // forn(i, n) cout << d[i] << " \n"[i == n - 1];
    cout << minimo << " " << maximo << endl;

    return 0;
}
