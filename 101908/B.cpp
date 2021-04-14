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
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

const int GRUNDY_GRANDE = 1000;

vector<vector<int>> grundy(105, vector<int>(105));

int mex(int r, int c){
    unordered_set<int> mex_set;
    forn(i, r) mex_set.insert(grundy[i][c]);
    forn(i, c) mex_set.insert(grundy[r][i]);
    forr(i, 1, min(r, c)) //Diagonales
        mex_set.insert(grundy[r-i][c-i]);

    forn(i, GRUNDY_GRANDE + 1)
        if(!esta(i, mex_set)) return i;
}

int main(){
    FIN;

    forn(i, 104){
        grundy[i][0] = grundy[i][i] = grundy[0][i] = GRUNDY_GRANDE;
    }

    forr(i, 1, 101){
        forr(j, 1, 101)
            if(i != j) grundy[i][j] = mex(i, j);
    }


    int n; cin >> n;
    int resultado_final = 0;
    forn(i, n){
        int ri, ci; cin >> ri >> ci;
        if(grundy[ri][ci] == GRUNDY_GRANDE){
            cout << "Y\n"; // YA directamente gana
            return 0;
        }
        resultado_final ^= grundy[ri][ci]; // Cada ficha juega individualmente
    }

    cout << (resultado_final ? "Y" : "N") << "\n";

    return 0;
}
