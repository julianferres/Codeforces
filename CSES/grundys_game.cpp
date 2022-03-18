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
const int MAX_NEG  = 1222; //Ultimo con grundy[i] = 0

void FIRST(){ cout << "first\n"; }
void SECOND(){ cout << "second\n"; }

vector<int> grundy(MAX_NEG + 1);
int mex(int n){
    unordered_set<int> seen;
    forr(i, 1, n){
        if(i != n - i) seen.insert(grundy[i] ^ grundy[n-i]);
    }
    int ans = 0;
    while(esta(ans, seen)) ans++;
    return ans;
}

int main(){  
    FIN;
    
    forr(i, 3, MAX_NEG+1){ grundy[i] = mex(i); }
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        if(n > MAX_NEG) FIRST();
        else{
            (grundy[n] ? FIRST() : SECOND());
        }
    }

    return 0;
}
