/*   AUTHOR: julianferres   */
#include <bits/stdc++.h>
using namespace std;

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


class PairedMultiples{
public:
	int selectedTotal(vector<int> values, int multiple){
		vi cnt(multiple);
		ll ans = 0;

		for(int x: values) cnt[x%multiple]++;

		for(int x: values){
			if(x%multiple == 0 || 2*(x%multiple) == multiple){
				// cerr << "mitad: " << x;
				if(cnt[x%multiple] >= 2)
					ans += x;
			} else { 
				if(cnt[multiple - (x%multiple)])
					ans += x;
			}
			// cerr << "ans: " << ans << endl;
		}
		return ans;
	}
};

int main(){  
    FIN;

    PairedMultiples x;
    cout << x.selectedTotal({1, 2, 3, 4, 5}, 3) << endl;
    cout << x.selectedTotal({1, 2, 3, 4}, 2) << endl;
    cout << x.selectedTotal({1, 2, 3, 6, 10}, 10) << endl;

    return 0;
}
