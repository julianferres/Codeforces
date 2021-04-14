#include<algorithm>

#include<iostream>

#include<cstring>

using namespace std;

typedef long long ll;

const int maxn = 1e6+50;

int t;

int X,Y;

ll dp[35][2][2][2];// digit  x The state of  y The state of   Has it been for 0

//dp[len][sx][sy][zeros] In the length of len,sx,sy Limit 、zeros Whether the number of cases in the highest order is the highest .

// The result is consistent with the situation ( has ×log(i+j)+1). 

ll x[35],y[35];

ll mod = 1e9+7;

// The return is for the length of len Of ,sx  sy Corresponding  x y  In the case of high limit ,zeros Whether the front is all zero 

// That is this. len It's the highest level , How many situations are consistent with , The result is consistent with the situation ( has ×log(i+j)+1).

ll dfs(int len,int sx,int sy,int zeros){

    // here we are len=0 It is also in line with the meaning of the question , At this point, a situation is completed  return 1;

    if(len == -1)  return 1;

    // If this has ever been recorded dp, Go straight back to .

    if(dp[len][sx][sy][zeros] != -1) return dp[len][sx][sy][zeros];

    // If sx=0 It means that some of the previous figures are not high , At this time, most of you can get 1 sy Empathy .

    int mx = (sx?x[len]:1);

    int my = (sy?y[len]:1);

    ll ans = 0;

    // Enumerating bits 

    for(int i = 0;i <= mx;i++){

       for(int j = 0;j <= my;j++){

           if(i&j) continue;

           int cnt = 1;

           if(zeros&&(i||j)) cnt = len+1;

           // If the front is full of 0, This bit appears 1, It turns out to be the highest   log(i+j)+1 by len+1.

          ans=(ans+dfs(len1,sx&&i==mx,sy&&j==my,zeros&&!i&&!j)*cnt%mod)%mod;  

       }

    }



    return dp[len][sx][sy][zeros] = ans;

}

ll solve(){

    memset(dp,-1,sizeof(dp));

    int len = 0;

    while(X||Y){

       x[len] = (X&1);

       y[len] = (Y&1);

       X>>=1;

       Y>>=1;

       len++;

    }

    // The highest bit is len-1 position 

    return dfs(len-1,1,1,1);

}

int main(){

    cin >> t;

    while(t--){

       cin >> X >>Y;

       //i=0,j=0 Delete the case of .

       cout << (solve()-1+mod)%mod <<endl;

    }

    return 0;

}