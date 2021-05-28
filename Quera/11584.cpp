#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    long long int arr[n+1];
    long long int que[n+1];
    for(int r = 1;r<=n;r++){
        scanf("%lld",arr+r);

        long long int sum = 0;
        for(int i = 1;i<=r;i++){
            sum+=(arr[i] ^ (r-i));
        }
        que[r] = sum;
    }
    while(q--){
        int r;
        scanf("%d",&r);
        printf("%lld\n",que[r]);
    }
    return 0;
}