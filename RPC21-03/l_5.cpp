#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define forr(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "===========================" << endl

#define SZ(x) (int)(x.size())

typedef long long tipo;

struct CD{
	double r,i;
	CD(double r=0,double i=0):r(r),i(i){}
	double real()const{return r;}
	void operator /=(const tipo c){r/=c; i/=c;}
};
CD operator*(const CD& a, const CD& b){return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1);
const tipo MAXN=1<<21;
CD cp1[MAXN+9],cp2[MAXN+9];
tipo R[MAXN+9];


void dft(CD* a, tipo n, bool inv){
	forr(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv?-1:1);
		CD wi=CD(cos(z),sin(z));
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k]; CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)forr(i,0,n) a[i]/=n;
}
vector<tipo> multiply(vector<tipo> &p1, vector<tipo> &p2){
	tipo n=SZ(p1)+SZ(p2)+1;
	tipo m=1,cnt=0;
	while(m<=n) m+=m,cnt++;
	forr(i,0,m){R[i]=0;forr(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	forr(i,0,m) cp1[i]=cp2[i]=0;
	forr(i,0,SZ(p1))cp1[i]=p1[i];
	forr(i,0,SZ(p2))cp2[i]=p2[i];
	dft(cp1,m,0); dft(cp2,m,0);
	forr(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,1);
	vector<tipo> res;
	n-=2;
	forr(i,0,n)res.pb((ll)floor(cp1[i].real()+.5));
	return res;
}

int main() {
  FIN;
  
  int n, m;
  cin >> n >> m;
  vector <pair<char,int> > a(n), b(m);
  forn(i,n) {
    cin >> a[i].first;
    if(a[i].first != '?') {
      cin >> a[i].second;
    }
  }
  forn(i,m) {
    cin >> b[i].first;
    if(b[i].first != '?') {  
      cin >> b[i].second;
    }
  }
  
  vector <int> poli(n+m);
  
  for(char u : {'n','s','e','w'}) {
    forr(w,1,8) {
      vector <tipo> pola(n,0), polb(m,0);
      forn(i,n) {
        if((a[i].first == u && a[i].second == w)) {
          pola[i] = 1;
        }
      }
      for(int j = m-1; j >= 0; j--) {
        if((b[j].first == u && b[j].second == w)) {
          polb[j] = 1;
        }
      }
      //~ DBG(u); DBG(w); 
      //~ for(int u : pola) cout << u << " "; cout << "\n";
      //~ for(int u : polb) cout << u << " "; cout << "\n";
      //~ RAYA;
      vector <tipo> ans = multiply(pola,polb);
      forn(i,ans.size()) poli[i] += ans[i];
    }
  }
  
  vector <tipo> pola(n,0), polb(m,0), todoa(n,1), todob(m,1);
  forn(i,n) {
    if(a[i].first == '?') {
      pola[i] = 1;
    }
  }
  for(int j = m-1; j >= 0; j--) {
    if(b[j].first == '?') {
      polb[j] = 1;
    }
  }
  
  
  
  vector <tipo> auxa = multiply(pola,todob);
  vector <tipo> auxb = multiply(polb,todoa);
  vector <tipo> auxc = multiply(pola,polb);
  
  //~ for(int u : auxa) cout << u << " "; cout << "\n";
  //~ for(int u : auxb) cout << u << " "; cout << "\n";
  
  forn(i,auxa.size()) {
    poli[i] += auxa[i] + auxb[i] - auxc[i];
  }
  
  //~ for(int u : poli) cout << u << " "; cout << "\n";
  
  int ans = 0;
  
  for(int u : poli) {
    if(u == m) ans++;
  }
  
  cout << ans << "\n";
  
  return 0;
}
