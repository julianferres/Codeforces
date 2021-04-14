/*   AUTHOR: julianferres   */
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
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
const ll INF = 2e18;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

typedef double ld;


typedef double tipo; //Cambiar a long long para operar en enteros
double EPS = (double)(1e-8);

struct punto { // Puede usarse para vectores
  tipo x, y;
  inline punto const operator -(const punto &p) const {return {x-p.x,y-p.y};}
  inline punto const operator +(const punto &p) const {return {x+p.x,y+p.y};}
  inline tipo const operator *(const punto &p) const {return x*p.x + y*p.y;}
  inline tipo const operator ^(const punto &p) const {return x*p.y - y*p.x;}
  inline bool const operator == (const punto &p) const {
    return (abs(x-p.x) < EPS && abs(y-p.y) < EPS); // Para double
  }
  inline bool operator <(punto p) const {return x != p.x ? x < p.x : y < p.y;}
  inline tipo arg() {return atan2(y,x);} 
  inline tipo mod() {return sqrt(x*x + y*y);}
  inline tipo mod2() {return x*x + y*y;}
};

inline punto operator*(tipo k, const punto &p) {return {k*p.x, k*p.y};}

struct recta { // Puede usarse para segmentos ([p,p+v] o alpha = [0,1])
  punto v, p; // v -> director, p -> punto por donde pasa
  inline recta(punto p1, punto p2) { v = (p2-p1); p = p1;}
  inline recta() {}
  inline recta(tipo A, tipo B, tipo C) { // Transform Ax + By + C = 0 
    v = {-B,A}; A != 0 ? p = {-C / A,0} : p = {0,-C / B}; 
  }
  inline bool is_in(punto q){return fabs((q.x-p.x)*v.y - (q.y-p.y)*v.x) < EPS;}
  inline punto eval(double x) {return x * v + p;}
};

inline bool inter_recta(recta &r1, recta &r2, punto &ans) {
  // Retorna false si son paralelas, sino guarda el punto en ans
  if(abs(r1.v ^ r2.v) < EPS) return false;
  tipo alpha = ((r2.p - r1.p)^r2.v) / (r1.v^r2.v);
  ans = r1.p + alpha * r1.v;
  return true;
}

recta rayo_act, seg_act, rayo_max, rayo_sig, eje_y;
punto inter_act, inter_seg_act, proy_sig, ddd, ojo;

int main(){  
    FIN;

    ll n, H; cin >> n >> H;
    punto a[n+1]; 

    forn(i, n) cin >> a[i].x >> a[i].y;

    ojo = {a[n-1].x, a[n-1].y + H};
    eje_y = recta({0, -1}, {0, 1}); //TODO: mirar

    punto ultimo_seg = a[n-1] - a[n-2];
    ld ans = ultimo_seg.mod();

    punto maxy = {0, -INF};


    for(int i = n-2; i > 0; i--){
        rayo_act = recta(ojo, a[i]);
        inter_recta(eje_y, rayo_act, inter_act);

        if(inter_act.y > maxy.y) maxy = inter_act;



        rayo_sig = recta(ojo, a[i-1]);
        inter_recta(eje_y, rayo_sig, proy_sig);
        if(abs(proy_sig.y - maxy.y) <= EPS && abs(inter_act.y - proy_sig.y) <= EPS){
          ddd = a[i] - a[i-1];
          ans += ddd.mod();
          continue;
        }
        if(proy_sig.y <= maxy.y + EPS) continue;

        rayo_max = recta(ojo, maxy);
        seg_act = recta(a[i-1], a[i]);
        if(inter_recta(seg_act, rayo_max, inter_seg_act)){
          ddd = a[i-1] - inter_seg_act;
          ans += ddd.mod();
        }
        //dbg(i, ans);
    }

    
    cout << fixed << setprecision(9) << ans << "\n";

    return 0;
}
