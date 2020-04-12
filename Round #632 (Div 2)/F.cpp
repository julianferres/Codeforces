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
const int N  = 5e5+5;

vi maxdiv;

void criba(int n){
    vi aa;
    maxdiv[0] = inf;
    maxdiv[1] = 1;
    forr(i,2,n+1){
        if(maxdiv[i])
            continue;
        for (int j = i; j <= n + 1; j+=i){
            aa.pb(j);
            ll a = 2 * j;
            if (maxdiv[j])
                continue;
            maxdiv[j] = j / i;
        }
    }
}

int main(){
    FIN;
    int n;
    cin >> n;
    maxdiv.assign(n + 1, 0);
    criba(n);
    sort(all(maxdiv));
    forr(i,1,n){
        cout << maxdiv[i] << ' ';
    }
    return 0;
}

