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
#define MAXN 100005
#define INF 1e18

ll maxSubArraySum(ll a[], ll size)
{
    ll max_so_far = INT_MIN, max_ending_here = 0;

    forn(i, size)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{
    FIN;
    ll t;
    cin >> t;
    forn(i, t)
    {
        ll n;
        cin >> n;
        ll a[n + 5];
        ll sum = 0LL;
        bool hay_pre_or_suf = false;
        forn(i, n)
        {
            cin >> a[i];
            sum += a[i];
            if (i > 0 && sum == 0)
                hay_pre_or_suf = true;
        }
        ll suf[n + 5];
        suf[n - 1] = a[n - 1];
        for (ll i = n - 2; i >= 0; i--)
        {
            suf[i] = suf[i + 1] + a[i];
        }
        forn(i, n) if (suf[i] == 0) hay_pre_or_suf = true;
        /*DBG(sum);
        DBG(hay_pre_or_suf);
        cout << maxSubArraySum(a, n);*/
        if ((sum > maxSubArraySum(a, n)) || (sum == maxSubArraySum(a, n) && !hay_pre_or_suf))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}