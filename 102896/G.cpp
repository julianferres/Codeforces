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
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e6+5;
typedef long double ld;

typedef ld tipo; //Cambiar a long long para operar en enteros
long double EPS = (long double)1e-12;

struct punto { // Puede usarse para vectores
  tipo x, y;
  punto const operator -(const punto &p) const {return {x-p.x,y-p.y};}
  punto const operator +(const punto &p) const {return {x+p.x,y+p.y};}
  tipo const operator *(const punto &p) const {return x*p.x + y*p.y;}
  tipo const operator ^(const punto &p) const {return x*p.y - y*p.x;}
  bool const operator == (const punto &p) const {
    return (abs(x-p.x) < EPS && abs(y-p.y) < EPS); // Para double
  }
  bool operator <(punto p) const {return x != p.x ? x < p.x : y < p.y;}
  tipo arg() {return atan2(y,x);} 
  tipo mod() {return sqrtl(x*x + y*y);}
  tipo mod2() {return x*x + y*y;}
};

punto operator*(tipo k, const punto &p) {return {k*p.x, k*p.y};}

ostream &operator << (ostream &os, const punto &p) { //Para imprimir
  return os << "(" << p.x << "," << p.y << ")";
}

istream &operator >> (istream &is, punto &p) { //Para leer
  return is >> p.x >> p.y;
}


struct recta { // Puede usarse para segmentos ([p,p+v] o alpha = [0,1])
  punto v, p; // v -> director, p -> punto por donde pasa
  recta(punto p1, punto p2) { v = (p2-p1); p = p1;}
  recta() {}
  recta(tipo A, tipo B, tipo C) { // Transform Ax + By + C = 0 
    v = {-B,A}; A != 0 ? p = {-C / A,0} : p = {0,-C / B}; 
  }
  bool is_in(punto q){return fabs((q.x-p.x)*v.y - (q.y-p.y)*v.x) < EPS;}
  punto eval(double x) {return x * v + p;}
};

bool inter_recta(recta &r1, recta &r2, punto &ans) {
  // Retorna false si son paralelas, sino guarda el punto en ans
  if(abs(r1.v ^ r2.v) < EPS) return false;
  tipo alpha = tipo((r2.p - r1.p)^r2.v) / tipo(r1.v^r2.v);
  ans = r1.p + alpha * r1.v;
  return true;
}

bool inter_seg(recta &r1, recta &r2, punto &ans) {
  if(r1.p == r2.p || r1.p == r2.p+r2.v) {ans = r1.p; return true;}
  if(r1.p+r1.v == r2.p || r1.p+r1.v == r2.p+r2.v) { 
    ans = r1.p+r1.v; return true; } //Casos que coincidan extremos
  if(abs(r1.v ^ r2.v) < EPS) return false; // son paralelos
  tipo alpha = tipo((r2.p - r1.p)^r2.v) / tipo(r1.v^r2.v);
  tipo beta = tipo((r1.p - r2.p)^r1.v) / tipo(r2.v^r1.v);
  if(alpha < -EPS || beta < -EPS) return false;
  if(alpha > 1.0+EPS || beta > 1.0+EPS) return false;
  ans = r1.p + alpha * r1.v; return true;
} 


vector <ll> f;

ll be(ll x, ll y, ll m) {
    if (y == 0) return 1;
    ll p = be(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}

ll inv_mod(ll x, ll m) {return be(x,m-2,m);}

void factorial() { // O(N)
	f.pb(1); forn(i,MAXN) f.pb((f.back()*(ll)(i+1)) % MOD);
}

ll combinatorio(ll n, ll m) {
	// Retorna n tomados de a m en O(Log N)
	ll ans = 1; ans *= f[n];
	ans *= inv_mod(f[m],MOD); ans %= MOD;
	ans *= inv_mod(f[n-m],MOD); ans %= MOD;
	return ans;
}



int to_pascal_l(int x, int i){ return (x + i + 1)/2; }  //x + i <= 2*k;
int to_pascal_r(int x, int i){ return (x + i)/2; }  //x + i <= 2*k;

void solve(){
    ld xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    vector<punto> tri = {{xa, ya}, {xb, yb}, {xc, yc}};

    int maxy = max(ya, max(yb, yc));   
    ll ans = 0;

    forn(i, maxy+1){
        recta r1 = recta({(ld) -i, (ld) -i}, {(ld) i, (ld) i}); //Segmento horizontal

        int l = INF, r = -INF;

        if(tri[0].y == tri[1].y && tri[0].y == i){
            l = ceil(max((int) (min(tri[0].x, tri[1].x) + EPS), -i) - EPS);
            r = (int) (min((int) (max(tri[0].x, tri[1].x) + EPS), i)+ EPS);
            
        }
        else if(tri[1].y == tri[2].y && tri[1].y == i){
            l = ceil(max((int) (min(tri[1].x, tri[2].x) + EPS), -i) - EPS);
            r = (int) (min((int) (max(tri[1].x, tri[2].x) + EPS), i) + EPS);
            
        }
        else if(tri[2].y == tri[0].y && tri[2].y == i){
            l = ceil(max((int) (min(tri[2].x, tri[0].x) + EPS), -i) - EPS);
            r = (int) (min((int) (max(tri[2].x, tri[0].x) + EPS), i)+ EPS);
        }
        else{
            punto int1, int2, int3;
            recta r2 = recta(tri[0], tri[1]); recta r3 = recta(tri[1], tri[2]); recta r4 = recta(tri[2], tri[0]);
            vector<ld> puntos;
            if(inter_seg(r1, r2, int1)){
               puntos.pb(int1.x);
            }
            if(inter_seg(r1, r3, int2)){
                puntos.pb(int2.x);
            }
            if(inter_seg(r1, r4, int3)){
               puntos.pb(int3.x);
            }
            if(puntos.size() == 2){
                l = min(puntos[0], puntos[1]);
                r = max(puntos[0], puntos[1]);
            }
            if(puntos.size() == 1) l = r = puntos[0];
        } 

        //Tengo el comienzo y final de la interseccion
        l = to_pascal_l(l, i);
        r = to_pascal_r(r, i);
        if(r > l) continue;
        if(l == r){
          ans += combinatorio(i, l);
          ans = ((ans % MOD) + MOD)%MOD;
        }

    }

    ans = ((ans%MOD) + MOD) %MOD;
    cout << ans << endl;
}

int main(){
    FIN;

    factorial();

    int tc; cin >> tc;
    while(tc--) solve();

    return 0;    
}
