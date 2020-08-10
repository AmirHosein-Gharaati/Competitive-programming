//TM
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int c,r,num;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d %d",&c,&r);
        if (c == r){
            printf("Case #%d: 0\n",i+1);
            continue;
        }
        printf("Case #%d:",i+1);
        num = c - r;
        for (int j = r+1; j <= int(sqrt(num/2)); j++){
            if ((num)%j == 0){
                printf(" %d",j);
            }
        }
        if (num > r+1){
            printf(" %d",num);
        }
        printf("\n");
    }


    return 0;
}