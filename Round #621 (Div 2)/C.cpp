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

    string ss;
    cin >> ss;
    ll n = ss.size();
    ll matriz[30][30];
    memset(matriz, 0, sizeof(matriz));
    vector<ll> cont(30, 0);
    cont[ss[0] - 'a']++;
    //DBG(cont[0]);
    forr(i, 1, n)
    {
        forn(j, 28)
            matriz[ss[i] - 'a'][j] += cont[j];
        cont[ss[i] - 'a']++;
    }
    ll ans = 0;
    forn(i, 28) ans = max(ans, cont[i]);
    forn(i, 28)
        forn(j, 28)
            ans = max(ans, matriz[i][j]);
    cout << ans << "\n";
}