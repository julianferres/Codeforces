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

typedef int ll;
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
const int MAXN  = 21;
typedef deque<int> qi;

vector<vi> childs(MAXN);
vi sz(MAXN), pos_order;
int n;

int dfs_size(int root){
    int ans = 1;
    for(int u: childs[root]) ans += dfs_size(u);
    pos_order.pb(root);
    return sz[root] = ans;
}

qi join(qi a1, qi a2, int shift){
    if(a1.size() == 0) return a2;
    qi ans;
    forn(i, a1.size()){
        if(i&1){ // al reves
            for(int j = a2.size()-1; j >= 0; j--)
                ans.pb((a1[i] << shift) | a2[j]);
        } else {
            forn(j, a2.size()) ans.pb((a1[i] << shift) | a2[j]);
        }
    }

    return ans;
}

qi solve(int root){ // 1 rojo
    if(childs[root].size() == 0) return {0, 1};
    qi states;

    for(int u: childs[root])
        states = join(states, solve(u), sz[u]);
    
    forn(i, states.size()) states[i] = 2*states[i] + 1;
    
    states.push_front(0);
    return states;
}

int give_change(int mask, int next_mask){
    //dbg(mask, next_mask, mask ^ next_mask);
    return pos_order[n - 1 -__builtin_ctz(mask^next_mask)];
}

int main(){  
    FIN;

    cin >> n;

    vi parent(n-1); forn(i, n-1) cin >> parent[i];

    forn(i, n-1){
        childs[parent[i]].pb(i+2);
    }
    dfs_size(1);

    qi ans = solve(1);
    ans.pop_front();

    //forn(i, ans.size()-1) dbg(__builtin_popcount(ans[i] ^ ans[i+1]));

    cout << ans.size() - 1 << "\n";
    forn(i, ans.size() - 1){
        cout << give_change(ans[i], ans[i+1]) << " ";
    }


    
    

    return 0;
}
