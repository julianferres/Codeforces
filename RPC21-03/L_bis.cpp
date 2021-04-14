#include <bits/stdc++.h>
using namespace std;
//template <class T> int size(const T &x) { return x.size(); }
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

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



const double pi = acos(-1.0);

#include <complex>
typedef complex<long double> cpx;
// NOTE: n must be a power of two
void fft(cpx *x, int n, bool inv=false) {
  for (int i = 0, j = 0; i < n; i++) {
    if (i < j) swap(x[i], x[j]);
    int m = n>>1;
    while (1 <= m && m <= j) j -= m, m >>= 1;
    j += m; }
  for (int mx = 1; mx < n; mx <<= 1) {
    cpx wp = exp(cpx(0, (inv ? -1 : 1) * pi / mx)), w = 1;
    for (int m = 0; m < mx; m++, w *= wp) {
      for (int i = m; i < n; i += mx << 1) {
        cpx t = x[i + mx] * w;
        x[i + mx] = x[i] - t;
        x[i] += t; } } }
  if (inv) rep(i,0,n) x[i] /= cpx(n); }

vi read(int n) {
    vi arr(n);
    rep(i,0,n) {
        string s;
        cin >> s;
        if (s == "?") {
            arr[i] = 0;
            continue;
        }

        int k;
        cin >> k;
        k *= 4;
        if (s == "n") k += 0;
        if (s == "w") k += 1;
        if (s == "e") k += 2;
        if (s == "s") k += 3;

        arr[i] = k;
    }
    return std::move(arr);
}

const int BOUND = 28;

int both_set[500000],
    match_sum[500000];

int main() {
    cin.sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vi a = read(n),
       b = read(m);

    int len = 2*n+1;
    while (len & (len-1)) len++;

    dbg(a, b, len);

    

    cpx *A = new cpx[len],
    *B = new cpx[len];

    vector<bool> fits(n-m+1, true);
    for (int bit = 0; (1<<bit) <= BOUND; bit++) {

        memset(A,0,len*sizeof(cpx));
        memset(B,0,len*sizeof(cpx));

        rep(i,0,n) {
            if (a[i] == 0) {
                A[n-i-1] = 0;
            } else {
                if (a[i] & (1<<bit)) {
                    A[n-i-1] = 1;
                } else {
                    A[n-i-1] = -1;
                }
            }
        }
        rep(i,0,m) {
            if (b[i] == 0) {
                B[i] = 0;
            } else {
                if (b[i] & (1<<bit)) {
                    B[i] = 1;
                } else {
                    B[i] = -1;
                }
            }
        }

        // rep(i,0,n) {
        //     cout << real(A[i]) << " ";
        // }
        // cout << endl;
        // rep(i,0,n) {
        //     cout << real(B[i]) << " ";
        // }
        // cout << endl;
        rep(i, 0, len) cerr << real(A[i]) << " " << real(B[i]) << endl;

        fft(A, len);
        fft(B, len);
        rep(i,0,len) A[i] *= B[i];
        fft(A, len, true);

        // rep(i, 0, len) cout << real(A[i]) << " " << imag(A[i]) << endl;

        // rep(i,0,n-m+1) {
        //     cout << round(real(A[n-1-i])) << " ";
        // }
        // cout << endl;

        rep(i,0,n-m+1) {
            match_sum[i] = static_cast<int>(round(real(A[n-1-i])) + 1e-9);
        }

        // dbg("--------", bit);
        // rep(i, 0, 20) cout << match_sum[i] << " \n"[i == 19];


        // rep(i,0,n) {
        //     cout << match_sum[i] << " ";
        // }
        // cout << endl;


        memset(A,0,len*sizeof(cpx));
        memset(B,0,len*sizeof(cpx));

        rep(i,0,n) {
            if (a[i] == 0) {
                A[n-i-1] = 0;
            } else {
                A[n-i-1] = 1;
            }
        }
        rep(i,0,m) {
            if (b[i] == 0) {
                B[i] = 0;
            } else {
                B[i] = 1;
            }
        }

        fft(A, len);
        fft(B, len);
        rep(i,0,len) A[i] *= B[i];
        fft(A, len, true);

        rep(i,0,n-m+1) {
            both_set[i] = static_cast<int>(round(real(A[n-1-i])) + 1e-9);
        }

        rep(i,0,n-m+1) {
            fits[i] = fits[i] && match_sum[i] == both_set[i];
        }
    }

    int r = 0;
    rep(i,0,n-m+1) {
        if (fits[i]) {
            //cout << i+1 << " ";
            r++;
        }
    }
    cout << r << endl;

    return 0;
}

