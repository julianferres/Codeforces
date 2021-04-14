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
const long double EPS = (long double)(1e-7);

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

bool inside(punto p, punto a, punto b){
  punto ap = p - a, pb = b - p, ab = b - a;
  return fabs(ap.mod() + pb.mod() - ab.mod()) < EPS;
}

bool point_in_poly(vector <punto> &v, punto p) { // O(n) for convex
  unsigned i, j, mi, mj, c = 0;
  for(i = 0, j = v.size()-1; i < v.size(); j = i++) {
    if((v[i].y <= p.y && p.y < v[j].y) || (v[j].y <= p.y && p.y < v[i].y)) {
      mi = i; mj = j; if(v[mi].y > v[mj].y) swap(mi,mj);
      if(((p-v[mi]) ^ (v[mj]-v[mi])) < 0 ) c ^= 1;
    }
  }
  return c;
}



int main(){
    FIN;

    int n, m; cin >> n >> m;
    vector<punto> a(n); forn(i, n) cin >> a[i];

    forn(i, m){
        punto p; cin >> p;
        bool boundary = 0;
        forn(i, n){
          if(inside(p, a[i], a[(i+1)%n])){
            cout << "BOUNDARY";
            boundary = 1;
            break;
          }
        }
        if(!boundary){
          int inside = point_in_poly(a, p);
          cout << (inside ? "INSIDE" : "OUTSIDE");
        }
        cout << "\n";
    }


    return 0;
}
