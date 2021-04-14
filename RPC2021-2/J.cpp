/*   AUTHOR: julianferres   */
#include <bits/stdc++.h>
#include <queue>
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
const ll INF = 2e18;
const int MOD = 1e9+7; // 998244353
const int MAXN  = 2e5+5;

vii books;

int n, m;

bool ok(ll mid){
    priority_queue<ii> pq;
    ll cum_pages = 0, bad = 0;

    for(auto j: books){
        pq.push(j);
        cum_pages += j.first;

        if((cum_pages + mid - 1)/mid > j.second){
            bad++;
            if(bad > m) return false;
            ii toRemove = pq.top(); pq.pop();
            cum_pages -= toRemove.first;
        }
    }

    return bad <= m;
}

int cmp_deadline(ii a, ii b){
    return a.second < b.second;
}

int main(){  
    FIN;

    cin >> n >> m;
    books.resize(n);
    forn(i, n) cin >> books[i].first >> books[i].second;
    sort(all(books), cmp_deadline);

    ll l = 1, r = INF, ans = INF;

    while(l <= r){
        ll mid = l + (r-l)/2;
        if(ok(mid)){
            r = mid-1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
