#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int ways[n+1];
    ways[0] = 1;
    for(int i  = 1;i<=n;i++){
        int sum = 0;
        if(i-1>=0){
            sum+=ways[i-1];
        }
        if(i-2>=0){
            sum+=ways[i-2];
        }
        ways[i] = sum;
    }
    cout<<ways[n];
    return 0;
}