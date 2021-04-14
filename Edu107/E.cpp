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
const int MOD = 998244353;
const int MAXN  = 3e5+5;

// Template de benq para enteros que tienen que ser tomados MOD
// se define un tipo mi como "typedef modular<ll> mi" 
template<class T> struct modular {
    T val;
    explicit operator T() const { return val; }
    modular() { val = 0; }
    template<class U> modular(const U& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }
    
    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular be(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { return be(a,MOD-2); }
    // inv is equivalent to return be(b,b.mod-2) if prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};


typedef modular<ll> mi;

vector<mi> pre(MAXN);

int main(){  
    FIN;

    forr(i, 1, MAXN){
        pre[i+1] = (mi) ((3*i+1)*be((mi) 2, i) - be((mi) -1, i))/9;
    }


    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));

    mi ans = 0;
    ll blancas = 0;

    forn(i, n){
        forn(j, m){
            char c; cin >> c;
            a[i][j] = (int) c == 'o';
            blancas += a[i][j];
        }
    }

    forn(i, n){
        int act = 0;

        forn(j, m){
            if(a[i][j]) act++;
            else{
                if(act >= 2)
                    ans += pre[act]* be((mi)2, blancas - act);
                act = 0;
            }
        }
        if(act >= 2) ans += pre[act]* be((mi)2, blancas - act);
    }




    forn(j, m){
        int act = 0;
        forn(i, n){
            if(a[i][j]) act++;
            else{
                if(act >= 2){
                    ans += pre[act] * be((mi)2, blancas - act);
                }
                // dbg(act, pre[act], be((mi)2, blancas - act));
                act = 0;
            }
        }
        if(act >= 2) ans += pre[act]*be((mi)2, blancas - act);
    }

    cout << ans << "\n";

    return 0;
}
