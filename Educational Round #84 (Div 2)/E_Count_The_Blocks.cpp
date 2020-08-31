/******************************************
*    AUTHOR:         julianferres         *
******************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int INF = 2000000000;
#define MOD 998244353
#define MAXN 200005

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    FIN;
    int n;
    cin >> n;
    vi ans(n+1, 0);
    ans[n] = 10;
    ll resta = 0, suf = 0;
    suf  = 10;
    for (int i = n - 1; i > 0;i--){
        //DBG(resta);
        //DBG(suf);
        resta += ans[i + 1] + suf;
        resta %= MOD;
        ans[i] = (((n - i + 1) * binpow(10, n - i + 1, MOD) % MOD) - resta + MOD) % MOD;
        suf += ans[i];
        suf %= MOD;
    }
    forr(i, 1, n+1) cout << ans[i]%MOD << " ";
    cout << endl;
    return 0;
}

