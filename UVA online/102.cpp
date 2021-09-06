#include <bits/stdc++.h>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int b[3], g[3], c[3];

    while(cin >> b[0] >> g[0] >> c[0] >> b[1] >> g[1] >> c[1] >> b[2] >> g[2] >> c[2]){
        int mini = INT_MAX, res =0;
        string ans;

        //BCG
        res = g[0] + c[0] + g[1] + b[1] + b[2] + c[2];
        if(res < mini){
            ans = "BCG";
            mini = res;
        }

        //BGC
        res = g[0] + c[0] + c[1] + b[1] + b[2] + g[2];
        if(res < mini){
            ans = "BGC";
            mini = res;
        }

        //CBG
        res = b[0] + g[0] + c[1] + g[1] + b[2] + c[2];
        if(res < mini){
            ans = "CBG";
            mini = res;
        }

        //CGB
        res = b[0] + g[0] + b[1] + c[1] + g[2] + c[2];
        if(res < mini){
            ans = "CGB";
            mini = res;
        }

        //GBC
        res = c[0] + b[0] + c[1] + g[1] + b[2] + g[2];
        if(res < mini){
            ans = "GBC";
            mini = res;
        }


        //GCB
        res = b[0] + c[0] + g[1] + b[1] + c[2] + g[2];
        if(res < mini){
            ans = "GCB";
            mini = res;
        } 
        

        cout << ans << " " << mini << endl;
        
    }





    return 0;
}