#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int difs[s.size()];
    int out[10][10];

    int dist[10][10][10];

    for(int i=0; i<10;i++){
        for(int j=0; j<10;j++){
            for(int d=0; d<10;d++){
                if(d==0){
                    dist[i][j][d]=0;
                    continue;
                }
                int ijd = 100;
                for(int x=0; x<10;x++){
                    for(int y=0; y<10;y++){

                        if(((d-(i*x+j*y))/10)*10 -(d-(i*x+j*y)) == 0)
                            ijd = min(ijd,x+y-1);
                    }
                }
                if(ijd == 100)
                    dist[i][j][d] = -1;
                else
                    dist[i][j][d] = ijd;
            }
        }
    }

    for(int i=1;i<s.size();i++){
        difs[i-1]= ((s[i]-'0')-(s[i-1]-'0'));
        if(difs[i-1]<0)
            difs[i-1]+=10;
    }



    for(int i=0; i<10;i++){
        for(int j=0; j<10;j++){
            int cum = 0;
            for(int d=0; d<s.size()-1;d++){
                if(dist[i][j][d]==-1){
                    cum = -1;
                    break;
                }
                cum += dist[i][j][d];
            }
            out[i][j] = cum;

        }
    }

    for(int i=0 ; i<10 ; i++){
        for(int j=0 ; j<10 ; j++)
            cout<<out[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
