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

int A, B;
vi dp, val, parent;
int ceil(int a, int b){ return (a + b - 1)/b; } 

int fill(int sum){
    if(dp[sum] != -1) return dp[sum];
    
    int ans = INF;
    ans = min(ans, 1 + fill((sum - 1)/2) + fill(ceil(sum-1, 2)));
    ans = min(ans, fill((sum - 2)/2) + fill(ceil(sum - 2, 2)));

    return dp[sum] = ans;
}

vi ans_w, ans_l, ans_r;

void build(int nodo, int c1, int c2){
    dbg(nodo);
    int suma = c1 + 2 * c2; 

    if(c1 >= 1 + dp[(suma - 1)/2] + dp[ceil(suma-1, 2)]){
        ans_w[nodo] = 1;
        if((suma - 1)/2 == 0) ans_l[nodo] = 0;
        else{
            build(2*nodo + 1, dp[(suma-1)/2], ((suma-1)/2 - dp[(suma-1)/2])/2);
        }
        if(ceil(suma - 1, 2) == 0) ans_r[nodo] = 0;
        else{
            build(2*nodo + 2, c1-1-dp[(suma-1)/2], c2-((suma-1)/2 - dp[(suma-1)/2])/2);
        }
    }
    else{
        ans_w[nodo] = 2;
        if((suma - 2)/2 == 0) ans_l[nodo] = 0;
        else{
            build(2*nodo + 1, dp[(suma-2)/2], ((suma-2)/2 - dp[(suma-2)/2])/2);
        }
        if(ceil(suma - 1, 2) == 0) ans_r[nodo] = 0;
        else{
            build(2*nodo + 2, c1-dp[(suma-2)/2], c2-1-((suma-2)/2 - dp[(suma-2)/2])/2);
        }
    }
}


int main(){  
    FIN;

    cin >> A >> B;
    dp.resize(A + 2*B + 1, -1);
    dp[0] = 0; dp[2] = 0; dp[1] = 1;

    fill(A + 2*B);

    if(dp[A + 2*B] > A){
        cout << "-1\n";
        return 0;
    }

    ans_w.resize(A + B + 1);
    ans_l.resize(A + B + 1);
    ans_r.resize(A + B + 1);
    //build(1, A, B);

    ans_w.resize(1e6);
    ans_l.resize(1e6);
    ans_r.resize(1e6);
    build(1, A, B);

    dbg(ans_w);
    dbg(ans_l);
    dbg(ans_r);




    return 0;
}
