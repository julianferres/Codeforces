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
const int MAXN  = 1e6 + 5;
typedef tuple<int, int, int> iii;

iii tree[MAXN];
int n; 

iii combine(iii a, iii b){
    int a0, a1, a2, b0, b1, b2;
    tie(a0, a1, a2) = a;
    tie(b0, b1, b2) = b;
    int t = min(a1, b2);
    return {a0 + b0 + t, a1 + b1 - t, a2 + b2 - t};
}

void init(){
    for(int i = n - 1; i >= 0; i--){
        tree[i] = combine(tree[i << 1], tree[(i<<1)|1]);
}


int main(){  
    FIN;

    

    return 0;
}

//# 223 (Div 1)
 
//class SegmentTreeGeneric:
    //"""Generic Segment Tree. f es una funcion asociativa"""
 
    //def __init__(self, array, f):
        //self.n = len(array)
        //self.t = [0]*self.n + array
        //self.f = f #Me guardo la funcion aca para los otros métodos
 
        //for i in range(self.n-1, 0, -1):
            //self.t[i] = self.f(self.t[i<<1],self.t[(i<<1)|1])
 
    //def query(self, l, r):
 
        //l+=self.n ; r+=self.n
        //res_l, res_r = 0,0
        //if(r<=l):
            //return res_l
        //while(l<=r):
            //if(l&1):
                //if(res_l==0):
                    //res_l = self.t[l]
                //else:
                    //res_l = self.f(res_l,self.t[l])
                //l+=1
            //if(not r&1):
                //if(res_r==0):
                    //res_r = self.t[r]
                //else:
                    //res_r = self.f(self.t[r],res_r)
                //r-=1
            //l>>=1; r>>=1
        //if(res_l ==0 and res_r==0):
            //return 0
        //if(res_l==0):
            //return 2*res_r[0]
        //if(res_r==0):
            //return 2*res_l[0]
        //return 2*self.f(res_l,res_r)[0]
 
 
//s = input()
//aux = []
//for c in s:
	//if(c=='('):
		//aux.append((0,1,0))
	//else:
		//aux.append((0,0,1))
 
//def f(u,v):
	//t = min(u[1],v[2])
	//return (u[0]+v[0]+t, u[1]+v[1]-t, u[2]+v[2]-t)
 
//tree = SegmentTreeGeneric(aux,f)
//Q = int(input())
//for _ in range(Q):
	//l, r = map(int, input().split())
	//print(tree.query(l-1,r-1))
