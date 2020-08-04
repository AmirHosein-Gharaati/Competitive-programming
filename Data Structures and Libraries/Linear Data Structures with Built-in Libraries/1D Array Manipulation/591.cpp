#include <bits/stdc++.h>

int stacks[51];

using namespace std;

int main(){

    int n,sum,height,j=1;
    while (scanf("%d",&n) && n){
        sum = 0;
        for(int i =0 ; i < n ;i++){
            scanf("%d",&stacks[i]);
            sum += stacks[i];
        }
        height = sum / n;
        sum = 0;
        for(int i =0 ; i < n ;i++){
            sum += abs(stacks[i] - height);
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",j++,sum/2);
    }
    return 0;
}