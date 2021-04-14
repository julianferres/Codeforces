/*   AUTHOR: julianferres   */
#include <bits/stdc++.h>
#include <queue>
using namespace std;

// neal Debugger
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#define pb push_back
#define fst first
#define snd second
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1e9+15; // const ll INF = 2e18;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

ii extendedEuclid (ll a, ll b){ //a * x + b * y = gcd(a,b)
    ll x,y;
    if (b==0) return mp(1,0);
    auto p=extendedEuclid(b,a%b);
    x=p.snd;
    y=p.fst-(a/b)*x;
    if(a*x+b*y==-__gcd(a,b)) x=-x, y=-y;
    return mp(x,y);
}
pair<ii, ii> diophantine(ll a,ll b, ll r) {
    //a*x+b*y=r where r is multiple of gcd(a,b);
    ll d=__gcd(a,b);
    a/=d; b/=d; r/=d;
    auto p = extendedEuclid(a,b);
    p.fst*=r; p.snd*=r;
    assert(a*p.fst+b*p.snd==r);
    return mp(p,mp(-b,a)); // solutions: p+t*ans.snd
}
ll inv(ll a, ll mod) { //inverse of a modulo mod
    assert(__gcd(a,mod)==1);
    ii sol = extendedEuclid(a,mod);
    return ((sol.fst%mod)+mod)%mod;
}
#define mod(a,m) (((a)%m+m)%m)
pair<ll,ll> sol(tuple<ll,ll,ll> c){ //requires inv, diophantine
    ll a=get<0>(c), x1=get<1>(c), m=get<2>(c), d=__gcd(a,m);
    if(d==1) return mp(mod(x1*inv(a,m),m), m);
    else return x1%d ? mp(-1LL,-1LL) : sol(make_tuple(a/d,x1/d,m/d));
}
pair<ll,ll> crt(vector< tuple<ll,ll,ll> > cond) { // returns: (sol, lcm)
    ll x1=0,m1=1,x2,m2;
    for(auto t:cond){
        tie(x2,m2)=sol(t);
        if((x1-x2)%__gcd(m1,m2))return mp(-1,-1);
        if(m1==m2)continue;
        ll k=diophantine(m2,-m1,x1-x2).fst.snd,l=m1*(m2/__gcd(m1,m2));
        x1=mod((__int128)m1*k+x1,l);m1=l;
    }
    return sol(make_tuple(1,x1,m1));
} //cond[i]={ai,bi,mi} ai*xi=bi (mi); assumes lcm fits in ll


int main(){  
    FIN;

    ll a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d >> e >> f >> g;

    vi vols;

    forr(delta, 1, a){
        if(2*delta >= a || 2*delta >= b) continue;
        vols.pb((a-2*delta)*(b-2*delta)*delta);
    }
    sort(all(vols));
    reverse(all(vols));
    ll v1 = vols[0], v2 = vols[1], v3 = vols[2];

    ii aux = crt({{1, c, v1}, {1, d, v2}, {1, e, v3}});
    ll ans = aux.fst, lcm_ = aux.snd;
    
    if(ans < f){
        dbg("entro f");
        ll to_sum = (f-ans)/lcm_;
        ans += lcm_ * (to_sum + 1);
    }
    dbg(ans);
    if(ans > g){
        dbg("entro g");
        ll to_subtract = (ans - g)/lcm_;
        ans -= lcm_ * (to_subtract + 1);
    }
    dbg(ans);
    assert(f <= ans && ans <= g);
    cout << ans << endl;    

    return 0;
}
