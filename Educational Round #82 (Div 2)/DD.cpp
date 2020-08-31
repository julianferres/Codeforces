#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

typedef long long ll;
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

int funcion(ll x)
{
    int ans = 0;
    while (x != 1)
    {
        ans++;
        x /= 2;
    }
    return ans;
}

int main()
{
    FIN;
#ifdef input
    freopen("test1.txt", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        int m;
        cin >> n >> m;
        vector<ll> v(m);
        forn(i, m) cin >> v[i];
        vector<int> cont(100, 0);
        ll suma = 0;
        forn(i, m) suma += v[i];
        if (suma < n)
        {
            cout << "-1\n";
            continue;
        }
        forn(i, m)
        {
            int aux = funcion(v[i]);
            cont[aux]++;
        }
        ll pot = 0, aux = 1;
        int ans = 0;
        while (n)
        {
            //DBG(n);
            if (n % 2 == 1 && cont[pot] > 0)
            {
                cont[pot]--;
                pot++;
                aux *= 2;
                n /= 2;
                continue;
            }
            if (n % 2 == 1)
            {
                forn(i, pot)
                {
                    int aux = cont[i] / 2;
                    cont[i] %= 2;
                    cont[i + 1] += aux;
                }
                if (cont[pot] > 0)
                {
                    cont[pot]--;
                    pot++;
                    aux *= 2;
                    n /= 2;
                    continue;
                }
                else
                {
                    int pos = pot;
                    while (cont[pos] == 0)
                        pos++;
                    //DBG(pos); DBG(pot);
                    for (int i = pos; i > pot; i--)
                    {
                        cont[i]--;
                        cont[i - 1] += 2;
                    }
                    ans += pos - pot;
                    cont[pot]--;
                    pot++;
                    aux *= 2;
                    n /= 2;
                    continue;
                }
            }
            n /= 2;
            pot++;
            aux *= 2;
        }
        cout << ans << "\n";
    }

    return 0;
}