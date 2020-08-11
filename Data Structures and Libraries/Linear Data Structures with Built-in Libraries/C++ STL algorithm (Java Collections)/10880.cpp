//TM
#include <bits/stdc++.h>

using namespace std;

int main(){
<<<<<<< HEAD
    int n,num,arr[1000];
    int c,r,k;
=======
    int n;
    int c,r,num;
>>>>>>> 0b185f70ff1dab84a8aab1976ef501258570a6b3
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d %d",&c,&r);
        if (c == r){
            printf("Case #%d: 0\n",i+1);
            continue;
        }
        printf("Case #%d:",i+1);
        num = c - r;
<<<<<<< HEAD
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
        
=======
        for (int j = r+1; j <= int(sqrt(num/2)); j++){
            if ((num)%j == 0){
                printf(" %d",j);
            }
        }
        if (num > r+1){
            printf(" %d",num);
        }
>>>>>>> 0b185f70ff1dab84a8aab1976ef501258570a6b3
        printf("\n");
    }


    return 0;
}