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
const int MAXSHOWS = 1005;
const int N = 11;

vii dp[(1<<N)+1];

struct show {
    int i, f, o;

    bool operator <(const show &other) const { return f < other.f; }
    friend ostream& operator<<(ostream& os, const show& a) { return os << a.i << a.f << a.o; }

};


int main(){
    FIN;

    int n; cin >> n;
    vector<vector<show>> stages(n);

    vii events;
    forn(i, n){
        int m; cin >> m;
        stages[i].resize(m);
        forn(j, m){
            int i_i, f_i, o_i; cin >> i_i >> f_i >> o_i;
            stages[i][j] = {i_i, f_i, o_i};
            events.pb({f_i, i});
        }
        sort(all(stages[i])); reverse(all(stages[i]));
    }
    sort(all(events)); reverse(all(events));
    dbg(events); dbg(stages);
    int MAXMASK = (1<<n);

    dp[0].pb({0, 0}); // Caso base

    while(events.size() > 0){
        int aux = events.back().second; events.pop_back();

        forr(i, 1, MAXMASK){
            if((i &(1 << aux)) == 0) continue; // Ya lo vi

            show &s = stages[aux].back();
            int ans = -INF;

            if(dp[i].size()){
                for(auto ev: dp[i]){
                    if(ev.first <= s.i) ans = max(ans, (int) ev.second + s.o);
                }
            }

            if(dp[i ^ (1 << aux)].size()){ // Hay algo en esa mascara ya
                for(ii ev : dp[i ^ (1 << aux)])
                    if(ev.first <= s.i)
                        ans = max(ans, (int) ev.second + s.o);
            }
            if(ans != -INF) dp[i].pb({s.f, ans});


        }
        stages[aux].pop_back();
    }

    int ans = -INF;

    if(dp[MAXMASK - 1].size()){
        for(ii ev: dp[MAXMASK - 1])
            ans = max(ans, (int)ev.second);
    }
    // dbg(ans, dp);

    cout << (ans == -INF ? -1 : ans) << "\n";

    return 0;
}
