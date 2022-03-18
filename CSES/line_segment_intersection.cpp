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
const int MAXN  = 2e5+5;

typedef long double tipo; //Cambiar a long long para operar en enteros
double EPS = (double)(1e-10);
 
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
  bool is_in(punto q) {
     tipo alpha = v.x != 0 ? (q.x-p.x)/v.x : (q.y-p.y)/v.y;
    return (abs((q.x-p.x)*v.y - (q.y-p.y)*v.x) < EPS & (alpha >= -EPS) & (alpha <= 1 + EPS));
  }
  punto eval(double x) {return x * v + p;}
};
 
bool inter_seg(recta &r1, recta &r2, punto &ans) {
  if(r1.p == r2.p || r1.p == r2.p+r2.v) {ans = r1.p; return true;}
  if(r1.p+r1.v == r2.p || r1.p+r1.v == r2.p+r2.v) { 
    ans = r1.p+r1.v; return true; } //Casos que coincidan extremos
  if(abs(r1.v ^ r2.v) < EPS) return false; // son paralelos
  tipo alpha = tipo((r2.p - r1.p)^r2.v) / tipo(r1.v^r2.v);
  tipo beta = tipo((r1.p - r2.p)^r1.v) / tipo(r2.v^r1.v);
  //~ cout << fixed << setprecision(10) << alpha << " " << beta << "\n";
  if(alpha < -EPS || beta < -EPS) return false;
  if(alpha > 1.0+EPS || beta > 1.0+EPS) return false;
  ans = r1.p + alpha * r1.v; return true;
} 

int main(){
    FIN;

    int tc; cin >> tc;
    while(tc--){
        vector<punto> a(4);
        cin >> a[0] >> a[1] >> a[2] >> a[3];

        recta r1 = recta(a[0], a[1]);
        recta r2 = recta(a[2], a[3]);
        punto ans;
        if(r1.is_in(a[2]) || r1.is_in(a[3]) || r2.is_in(a[0]) || r2.is_in(a[1])){
          cout << "YES\n";
          continue;
        }
        cout << (inter_seg(r1, r2, ans) ? "YES" : "NO") << "\n";


    }


    return 0;
}
