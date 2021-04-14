/*   AUTHOR: julianferres   */
#include <bits/stdc++.h>
using namespace std;

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
const int MAXN  = 1e6;
const long double EPS = 1e-9;


#include<complex>
typedef complex<long double> complejo;
const double pi = acos(-1.0);

void fft(complejo *x, int n, bool inv=false) {
  for (int i = 0, j = 0; i < n; i++) {
    if (i < j) swap(x[i], x[j]);
    int m = n>>1;
    while (1 <= m && m <= j) j -= m, m >>= 1;
    j += m; }
  for (int mx = 1; mx < n; mx <<= 1) {
    complejo wp = exp(complejo(0, (inv ? -1 : 1) * pi / mx)), w = 1;
    for (int m = 0; m < mx; m++, w *= wp) {
      for (int i = m; i < n; i += mx << 1) {
        complejo t = x[i + mx] * w;
        x[i + mx] = x[i] - t;
        x[i] += t; } } }
  if (inv) forn(i, n) x[i] /= complejo(n);
}

const int BORDE = 28;
int ambos[500000], suma_matches[500000];
int a[MAXN], b[MAXN];

int main(){  
    cin.sync_with_stdio(false);

    int n, m; cin >> n >> m;

    forn(i, n){
        char s; cin >> s;
        if (s == '?') {
            a[i] = 0;
            continue;
        }

        int k; cin >> k; k *= 4;
        if (s == 'n') k += 0;
        if (s == 'w') k += 1;
        if (s == 'e') k += 2;
        if (s == 's') k += 3;

        a[i] = k;
    }
    forn(i, m){
        char s; cin >> s;
        if (s == '?') {
            b[i] = 0;
            continue;
        }

        int k; cin >> k; k *= 4;
        if (s == 'n') k += 0;
        if (s == 'w') k += 1;
        if (s == 'e') k += 2;
        if (s == 's') k += 3;

        b[i] = k;
    }
  
    int len = 2*n + 1;
    while (len & (len-1)) len++;

    complejo *A = new complejo[len], *B = new complejo[len];

    vb matches(n - m + 1, true);

    for(int bit = 0; bit <= 4; bit++){
        memset(A,0,len*sizeof(complejo));
        memset(B,0,len*sizeof(complejo));


        forn(i, n){
            if (a[i] == 0) A[n-i-1] = 0;
            else A[n-i-1] = ((a[i] & (1<<bit)) ? 1 : -1);
        }
        forn(i, m){
            if (b[i] == 0) B[i] = 0;
            else B[i] = ((b[i] & (1<<bit)) ? 1 : -1);
        }
        //FFT
        // forn(i, len) cerr << real(A[i]) << " " << real(B[i]) << endl;

        fft(A, len); fft(B, len);
        forn(i, len) A[i] *= B[i];
        fft(A, len, true);


        forn(i,n-m+1) {
            suma_matches[i] = (int) (round(real(A[n-1-i])) + EPS);
        }

        // dbg("--------", bit);
        // forn(i, 20) cout << suma_matches[i] << " \n"[i == 19];

        memset(A,0,len*sizeof(complejo));
        memset(B,0,len*sizeof(complejo));

        forn(i, n) A[n-1-i] = (a[i] != 0);
        forn(i, m) B[i] = (b[i] != 0);

        fft(A, len);
        fft(B, len);
        forn(i, len) A[i] *= B[i];
        fft(A, len, true);

        forn(i, n-m+1)
            ambos[i] = (int) (round(real(A[n-1-i])) + EPS);

        forn(i, n-m+1)
            matches[i] = matches[i] && suma_matches[i] == ambos[i];

    }

    //Fatality
    int ans = 0;
    forn(i, n-m+1){
        if(matches[i]) ans++;
    }

    cout << ans << endl;

    return 0;
}
