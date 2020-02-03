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
#define MAXN 100005
#define INF 1e18

ll binpow(ll a, ll b, ll m)
{
    // a**b mod m, iterativa, O(log b)
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll invmod(ll a, ll m)
{
    return (binpow(a, m - 2, m) + m) % m;
}

int main()
{
    ll M = 1000000007;
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<ll> fact;
    fact.pb(1LL);
    forr(i, 1, 1000004) fact.pb((fact.back() * i) % M);

    ll n, m;
    cin >> n >> m;
    ll ans = 0LL;
    forr(k, 1, n + 1)
    {
        forr(q, k, n + 1)
        {
            ll a = m - 1 + n - q;
            ll b = m - 1;
            ll aa = k - 1 + m - 1;
            ll bb = m - 1;
            ans += ((fact[a] * invmod(fact[b], M) % M) * invmod(fact[a - b], M) % M) * ((fact[aa] * invmod(fact[bb], M) % M) * invmod(fact[aa - bb], M) % M) % M;
            ans %= M;
        }
    }
    cout << ans << endl;
    return 0;
}
