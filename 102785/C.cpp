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


#define FIN ios::sync_with_stdio(0);cout.tie(0);cin.tie(0)
#define forr(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define forn(i,n) forr(i,0,n)
#define pb push_back
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "============================" << endl
#define all(c) (c).begin(),(c).end()

map<string,int> solve(int l, int r, string &pal, int level) {
  map<string,int> mapa;
  int ant = -1;
  forr(i,l,r+1) {
    //~ DBG(i);
    if(pal[i] == '(') {
      int cont = 1, pos = -1;
      forr(j,i+1,r+1) {
        if(pal[j] == '(') cont++;
        else if(pal[j] == ')') cont--;
        if(cont == 0) {pos = j; break;}
      }
      //~ DBG(i+1); DBG(pos-1); RAYA;
      if(ant == -1) {
        mapa = solve(i+1,pos-1,pal,level);
      }
      else if(ant == 0) {
        map<string,int> aux = solve(i+1,pos-1,pal,level);
        for(auto u : aux) {
          mapa[u.first] += u.second;
        }
      }
      else if(ant == 1) {
        map<string,int> aux = solve(i+1,pos-1,pal,level);
        for(auto u : aux) {
          mapa[u.first] -= u.second;
        }
      }
      i = pos; continue;
    }
    else if(pal[i] == '/') {
      ant = 1; continue;
      //~ DBG(i); RAYA;
    }
    else if(pal[i] == '*') {
      ant = 0; continue;
    }
    else {
      string aux;
      while(i < pal.size() && pal[i] != '(' && pal[i] != ')' && pal[i] != '*' && pal[i] != '/') {
        aux += pal[i];
        i++;
      }
      if(ant == 0 || ant == -1) mapa[aux]++;
      else mapa[aux]--;
      i--;
      //~ DBG(aux); DBG(i); RAYA;
    }
  }
  return mapa;
}

struct parejas {
  string s; int cont;
};

bool compare(parejas a, parejas b) {
  forn(i,min(a.s.size(),b.s.size())) {
    if(a.s[i] != b.s[i]) {
      char x, y;
      a.s[i] < 'a' ? x = a.s[i] - 'A' + 'a' : x = a.s[i];
      b.s[i] < 'a' ? y = b.s[i] - 'A' + 'a' : y = b.s[i];
      if(x != y) return x < y;
      else if(a.s[i] < 'a') return true;
      else return false;
    }
  }
  return a.s.size() < b.s.size();
}

int main() {
  FIN;

  string pal; cin >> pal;
  map <string,int> mapa = solve(0,pal.size()-1,pal,0);
  //~ for(auto u : mapa) cout << u.first << " " << u.second << "\n";
  //~ string num, den;
  vector <parejas> v;
  for(auto u : mapa) {
    v.pb({u.first,u.second});
  }
  sort(all(v),compare);
  //~ for(auto u : v) cout << u.s << " " << u.cont << "\n";
  string num, den;
  for(auto u : v) {
    if(u.cont > 0) forn(_, abs(u.cont)) num += "*" + u.s;
    if(u.cont < 0) forn(_, abs(u.cont)) den += "*" + u.s;
  }
  dbg(num, den);
  num.size()==0 ? cout << "1\n" : cout << num.substr(1,num.size()-1) << "\n";
  den.size()==0 ? cout << "1\n" : cout << den.substr(1,den.size()-1) << "\n";

  return 0;
}
