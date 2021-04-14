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
const int MAXN  = 505;

vector <int> link, sz, borde, grem;
void init(int n) {
    link.resize(n); sz.resize(n);
    grem.resize(n); borde.resize(n);
    forn(i, n) link[i]=i, sz[i]=1;
}
int find(int x) {
	if(x==link[x]) return x;
	return link[x]=find(link[x]);
}
void join(int a, int b) {
	a=find(a); b=find(b);
	if(sz[a]<sz[b]) swap(a,b);
	sz[a]+=sz[b];
    borde[a] = max(borde[a], borde[b]);
    grem[a] = max(grem[a], grem[b]);
	link[b]=a;
}

bool esta_en_borde(ii pos, int n){
    return pos.first == 0 || pos.first == n-1 || pos.second == 0 || pos.second == n-1;
}
bool esta_en_borde(int hsh, int n){
    ii pos = {hsh/n, hsh%n};
    return esta_en_borde(pos, n);
}
int hashear(ii pos, int n){ return pos.first * n + pos.second; }
vector<vb> apagado;

int main(){
    FIN;

    int n, m, k; cin >> n >> m >> k;
    apagado.resize(n, vb(n));

    vii gremlins(m);
    forn(i, m) cin >> gremlins[i].first >> gremlins[i].second;
    vii luces(k);
    forn(i, k) cin >> luces[i].first >> luces[i].second;

    init(n * n);
    forn(i, m){ grem[hashear(gremlins[i], n)] = 1; apagado[gremlins[i].first][gremlins[i].second] = 1; }
    forn(i, n*n){ if(esta_en_borde(i, n)) borde[i] = 1; }

    forn(j, m){
        int actx = gremlins[j].first, acty = gremlins[j].second;
        if(actx > 0 && apagado[actx-1][acty]) join(hashear({actx, acty}, n), hashear({actx-1, acty}, n));
        if(actx < n-1 && apagado[actx+1][acty]) join(hashear({actx, acty}, n), hashear({actx+1, acty}, n));
        if(acty > 0 && apagado[actx][acty-1]) join(hashear({actx, acty}, n), hashear({actx, acty-1}, n));
        if(acty < n-1 && apagado[actx][acty+1]) join(hashear({actx, acty}, n), hashear({actx, acty+1}, n));
    }

    forn(i, n*n){
        if(grem[i] && borde[i]){
            cout << 0 << endl;
            return 0;
        }
    }

    forn(i, k){
        int actx = luces[i].first , acty = luces[i].second;
        apagado[actx][acty] = 1;

            // if(apagado[i][acty]) join(hashear({actx, acty}, n), hashear({i, acty}, n));
            // if(apagado[actx][i]) join(hashear({actx, acty}, n), hashear({actx, i}, n));
            if(actx > 0 && apagado[actx-1][acty]) join(hashear({actx, acty}, n), hashear({actx-1, acty}, n));
            if(actx < n-1 && apagado[actx+1][acty]) join(hashear({actx, acty}, n), hashear({actx+1, acty}, n));
            if(acty > 0 && apagado[actx][acty-1]) join(hashear({actx, acty}, n), hashear({actx, acty-1}, n));
            if(acty < n-1 && apagado[actx][acty+1]) join(hashear({actx, acty}, n), hashear({actx, acty+1}, n));

        int par_act = find(hashear({actx, acty}, n));
        if(grem[par_act] && borde[par_act]){
            cout << i + 1 << endl;
            return 0;
        }
    }

    return 0;
}
