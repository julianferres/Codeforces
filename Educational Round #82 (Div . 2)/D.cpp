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

ll suma(vi a)
{
    ll ans = 0;
    forn(i, a.size()) ans += a[i];
    return ans;
}
ll power(ll x)
{
    int ans = 0;
    while (x != 1)
    {
        ans++;
        x /= 2;
    }
    return ans;
}

vi a;
int main()
{
    FIN;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        a.clear();
        ll ans = 0;
        vi cnt(80, 0);

        forn(i, m)
        {
            ll ai;
            cin >> ai;
            if (ai & n)
                n -= ai;
            else
            {
                cnt[power(ai)]++;
                a.pb(ai);
            }
        }

        if (suma(a) < n)
        {
            cout << -1 << endl;
        }
        else
        {
            ll ans = 0;
            ll idx = 0;
            while (idx < 60)
            {
                //  DBG(idx);
                if ((1LL << idx) & n)
                {
                    forn(i, idx)
                    {
                        cnt[i + 1] += cnt[i] / 2;
                        cnt[i] = cnt[i] & 1;
                    }
                    if (cnt[idx])
                    {
                        n -= (1LL << idx);
                        cnt[idx]--;
                    }
                    else
                    {
                        ll j = idx + 1;
                        while (!cnt[j] && j < 80)
                            j++;
                        cnt[j]--;
                        forr(ii, idx, j)
                        {
                            ans++;
                            cnt[ii]++;
                        }
                        n -= (1LL << idx);
                        cnt[idx]--;
                    }
                }

                idx++;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
