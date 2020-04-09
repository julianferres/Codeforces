/*****************************************
*        AUTHOR: julianferres            *
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
#define esta(x, c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MAXN 200005

set<int> s;
vi g[MAXN];

int main()
{
    FIN;
    int n, m, k;
    cin >> n >> m >> k;
    forn(i, k)
    {
        int special;
        cin >> special;
        special--;
        s.insert(special);
    }
    bool flag = false; //Hay edge entre specials
    forn(i, m)
    {
        int a, b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
        if (esta(a, s) && esta(b, s))
            flag = true;
    }

    return 0;
}