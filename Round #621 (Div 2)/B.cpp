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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        forn(i, n) cin >> v[i];
        set<int> s;
        forn(i, n) s.insert(v[i]);
        int maxi = 0;
        int ans = 1e9 + 5;
        forn(i, n)
        {
            maxi = v[i];
            if (maxi > x)
            {
                ans = min(ans, 2);
                continue;
            }
            if (x % maxi == 0)
                ans = min(ans, x / maxi);
            else
                ans = min(ans, x / maxi + 1);
        }
        cout << ans << "\n";
    }
}