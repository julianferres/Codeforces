/*   AUTHOR: julianferres   */
#include <bits/stdc++.h>
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
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1e9+15; // const ll INF = 2e18;
const int MOD = 1e9+7;  // const int MOD = 998244353;

#define SZ(x) (int)(x.size())

typedef long long tipo;

struct CD{
    double r,i;
    CD(double r=0,double i=0):r(r),i(i){}
    double real()const{return r;}
    void operator /=(const tipo c){r/=c; i/=c;}
};
CD operator*(const CD& a, const CD& b){return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1);
const tipo MAXN=1<<21;
CD cp1[MAXN+9],cp2[MAXN+9];
tipo R[MAXN+9];

void dft(CD* a, tipo n, bool inv){
    forr(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
    for(int m=2;m<=n;m*=2){
        double z=2*pi/m*(inv?-1:1);
        CD wi=CD(cos(z),sin(z));
        for(int j=0;j<n;j+=m){
            CD w(1);
            for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
                CD u=a[k]; CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
            }
        }
    }
    if(inv)forr(i,0,n) a[i]/=n;
}
vector<tipo> multiply(vector<tipo> &p1, vector<tipo> &p2){
    tipo n=SZ(p1)+SZ(p2)+1;
    tipo m=1,cnt=0;
    while(m<=n) m+=m,cnt++;
    forr(i,0,m){R[i]=0;forr(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
    forr(i,0,m) cp1[i]=cp2[i]=0;
    forr(i,0,SZ(p1))cp1[i]=p1[i];
    forr(i,0,SZ(p2))cp2[i]=p2[i];
    dft(cp1,m,0); dft(cp2,m,0);
    forr(i,0,m)cp1[i]=cp1[i]*cp2[i];
    dft(cp1,m,1);
    vector<tipo> res;
    n-=2;
    forr(i,0,n)res.pb((ll)floor(cp1[i].real()+.5));
    return res;
}



int main(){  
    FIN;

    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    reverse(all(t));
    vi a(n), b(n), inv_a(n), inv_b(n);

    forn(i, n) (s[i] == '0'? a: inv_a)[i] = 1;
    forn(i, m) (t[i] == '0'? b: inv_b)[i] = 1;

    vi c = multiply(a, inv_b);
    vi d = multiply(inv_a, b);


    ll ans = INF;
    forr(i, m-1, n){
        ans = min(ans, c[i] + d[i]);
    }

    cout << ans << "\n";



    return 0;
}
