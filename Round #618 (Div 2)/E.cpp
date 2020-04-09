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
#define DBGV(v,n) forn(i,n) cout << v[i] << " "; cout << endl
#define esta(x,c) ((c).find(x) != (c).end())
#define RAYA cerr << "===============================" << endl
#define MOD 1000000007
#define INF 1e18

vector<ii> d;

ii join(ii x1,ii x2){
    ll s1=x1.first,c1=x1.second,s2=x2.first,c2=x2.second;
    return mp(s1+s2,c1+c2);
}
bool conviene(ii x1,ii x2){
    ll s1=x1.first,c1=x1.second,s2=x2.first,c2=x2.second;
    return (s1+s2)*c1<(c1+c2)*s1;
}

int main(){
    FIN;
    int n; cin >> n;
    ll a[n+5];
    forn(i,n) cin >> a[i];
    forn(i,n){
        ii aux = {a[i],1};
        while(d.size() && conviene(d.back(),aux)){
            aux = join(d.back(),aux);
            d.pop_back();
        }
        d.pb(aux);
    }
    for(auto x: d)
        forn(i,x.second) printf("%.10Lf\n", (long double)x.first/x.second);

    return 0;
}

