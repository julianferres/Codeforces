/******************************************
*    AUTHOR:         JULIAN FERRES        *
*    INSTITUITION:   FIUBA                *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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
#define DBGV(v, n)                  \
    forn(i, n) cout << v[i] << " "; \
    cout << endl
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MOD 1000000007
#define MAXN 300005
#define INF 1e18

int n, m;
ll masks[1 << 10];
ll a[MAXN][10];

pair<bool, ii> solve(ll x, int m)
{
    forn(i, 1 << m) masks[i] = -1;

    forn(i, n)
    {
        int mask = 0;
        for (int j = m - 1; j >= 0; --j)
            mask += (1 << (m - 1 - j)) * (a[i][j] >= x);
        masks[mask] = i;
    }
    forn(j, 1 << m)
    {
        if (masks[j] == -1)
            continue;
        forn(i, 1 << m)
        {
            if (masks[i] != -1 && ((j | i) == (1 << m) - 1))
                return mp(true, mp(masks[i], masks[j]));
        }
    }
    return mp(false, mp(-1, -1));
}

int main()
{
    FIN;
    cin >> n >> m;
    ll maxA = 0LL;
    forn(i, n) forn(j, m)
    {
        cin >> a[i][j];
        maxA = max(maxA, a[i][j]);
    }
    ll l = 0, r = maxA;
    while (l <= r)
    {
        /*DBG(l);
        DBG(r);*/
        ll med = (l + r) / 2;
        pair<bool, ii> res = solve(med, m);
        /*DBG(med);
        DBG(res.first);*/
        if (res.first)
        {
            pair<bool, ii> res1 = solve(med + 1, m);
            //DBG(med);
            if (!res1.first)
            {
                cout << res.second.first + 1 << " " << res.second.second + 1 << endl;
                return 0;
            }
            l = med + 1;
        }
        else
            r = med - 1;
    }
    return 0;
}
