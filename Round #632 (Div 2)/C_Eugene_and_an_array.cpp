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
#define show(v,n) cerr << #v << " = "; forn(i,n) cerr << v[i] << " "; cerr << endl;
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
const int inf = 1<<30; // const ll inf = 1LL<<62;
const int mod = 1e9+7; // 998244353
const int N  = 2e5+5;

ll solve(vi A)
{
    ll n = A.size();
    ll ans = 0;
    map<ll, ll> lastSeen;
    lastSeen[A[0]] = 0;
    ll l = 0;
    forr(i, 1, n)
    {
        if (!esta(A[i], lastSeen))
            ans += max(0LL, i - l);

        else
        {
            l = max(l, lastSeen[A[i]] + 1);
            ans += max(0LL, i - l);
        }
        lastSeen[A[i]] = i;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vi a(n);
    forn(i,n) cin >> a[i];
    vi cum(n, 0);
    cum[0] = a[0];
    forr(i,1,n){
        cum[i] = cum[i - 1] + a[i];
    }

    ll ans = solve(cum);

    map<ll, ll> seen;
    forn(i, n)
    {
        if (cum[i] == 0)
            break;
        else if (!esta(cum[i], seen))
            ans += (int) (cum[i]!=0);
        else
            break;
        seen[cum[i]] = 1;
    }

    cout << ans << endl;
}