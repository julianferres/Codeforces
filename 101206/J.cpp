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


int weekday(int y, int m, int d) {
    if(m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return w;//0->monday
}


int segundo_domingo(int y, int m, int day_max){
    int domingos_vistos = 0;
    forr(i, 1, day_max+1){
        if(weekday(y, m, i) == 6){
            domingos_vistos++;
        }
        if(domingos_vistos == 2){
            return i;
        }
    }
    assert(false); // Nunca llega
    return -1;
}


int main(){  

    vector<string> anses = {"PST", "PDT", "Both", "Neither"};
    int tc; scanf("%d", &tc);
    forr(este_test, 1, tc+1){
        int ans = 0;
        int year, month, day, hour, minute, second;
        scanf("%d-%d-%d %d:%d:%d",&year, &month, &day, &hour, &minute, &second);
        

        if(month == 3){ // Marzo
            int day_segundo_domingo = segundo_domingo(year, month, 31);
            if(day == day_segundo_domingo){
                if(hour < 2) ans = 1;
                else if(hour >= 3) ans = 2;
                else ans = 4;
            }
            else if (day < day_segundo_domingo) {
                ans = 1;
            } else{
                ans = 2;
            }
        }
        else if(month == 11){ // Nov
            int day_segundo_domingo = segundo_domingo(year, month, 30);
            if(day == day_segundo_domingo){
                if(hour < 1) ans = 2;
                else if(hour >= 2) ans = 1;
                else ans = 3;
            }
            else if (day < day_segundo_domingo) {
                ans = 2;
            } else{
                ans = 1;
            }

        }


        // Entre medio
        else if(month > 3 && month < 11) ans = 2;
        // Por afuera
        else ans = 1; // if(month < 3 || month > 11) ans = 1;

        printf("Case #%d ", este_test);
        cout << anses[ans-1] << "\n";
    }

    return 0;
}
