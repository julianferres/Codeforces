/******************************************
*    AUTHOR:         julianferres         *
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
#define MOD 1000000007
#define MAXN 200005
#define INF 1e18

int main()
{
    FIN;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll x = n - m;
        if (x < (n + 1) / 2)
            cout << n * (n + 1) / 2 - x << endl;
        else
        {
            ll cadagrupo = x / (m + 1);
            ll sobran = x % (m + 1);
            ll cum = 0;
            cum += sobran * (cadagrupo + 1) * (cadagrupo + 2) / 2;
            cum += (m + 1 - sobran) * (cadagrupo) * (cadagrupo + 1) / 2;
            cout << n * (n + 1) / 2 - cum << endl;
        }
    }

    return 0;
}
