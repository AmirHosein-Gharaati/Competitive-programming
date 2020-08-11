//TM
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,num,arr[1000];
    int c,r,k;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d %d",&c,&r);
        if (c == r){
            printf("Case #%d: 0\n",i+1);
            continue;
        }
        printf("Case #%d:",i+1);
        num = c - r;
        k = 0;
        for (int j = 1; j <= int(sqrt(num)); j++){
            if ((num)%j == 0){
                if (j > r){
                    arr[k++] = j;
                }
                if (num/j != j && num/j > r){
                    arr[k++] = num/j;
                }
            }
        }
        sort(arr,arr+k);
        for (int j =0; j < k; j++){
            printf(" %d",arr[j]);
        }
        
        printf("\n");
    }


    return 0;
}