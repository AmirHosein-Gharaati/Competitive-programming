//TM
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int c,r;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d %d",&c,&r);
        if (c == r){
            printf("Case #%d: 0\n",i+1);
            continue;
        }
        printf("Case #%d:",i+1);
        for (int j = r+1; j <= c; j++){
            if ((c-r)%j == 0){
                printf(" %d",j);
            }
        }
        printf("\n");
    }


    return 0;
}