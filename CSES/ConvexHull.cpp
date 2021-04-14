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


typedef long long tipo; //Cambiar a long long para operar en enteros
ll EPS = 0;

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

void convex_hull(vector<punto> &a) {
  if(a.size() == 1) return;
  sort(all(a));
  punto p1 = a[0], p2 = a.back();
  vector<punto> up, down;
  up.pb(p1); down.pb(p1);
  forr(i,1,a.size()) {
    int n = up.size(), m = down.size();
    while(n > 1 && ((up[n-1]-up[n-2])^(a[i]-up[n-1])) >  -EPS) {
      up.pop_back(); n--; 
    } up.pb(a[i]);
    while(m > 1 && ((down[m-1]-down[m-2])^(a[i]-down[m-1])) < EPS) {
      down.pop_back(); m--;
    } down.pb(a[i]);
  } // Cambiar EPS a 0 para mejor precision en enteros. 
  a.clear();
  for(punto u : up) a.pb(u);
  for(int i = down.size()-2; i > 0; i--) a.push_back(down[i]);
}

int main(){  
    FIN;

    int n; cin >> n;

    vector<punto> a(n);
    forn(i, n) cin >> a[i].x >> a[i].y;

    convex_hull(a);
    cout << a.size() << "\n";

    forn(i, a.size()){
      cout << a[i].x << " " << a[i].y << "\n";
    }

    

    return 0;
}
