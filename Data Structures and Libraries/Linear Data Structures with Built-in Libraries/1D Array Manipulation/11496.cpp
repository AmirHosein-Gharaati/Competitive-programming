#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int numbers[10010];
    int counts;
    while ((scanf("%d",&n)) && n){
        for(int i = 1 ; i <= n ; i++){
            scanf("%d",&numbers[i]);
        }
        counts = 0;
        numbers[0] = numbers[n];
        numbers[n+1] = numbers[1];
        for(int i = 1 ; i <= n; i++){
            if (numbers[i] > numbers[i-1] && numbers[i] > numbers[i+1]){
                counts++;
            }
            if (numbers[i] < numbers[i-1] && numbers[i] < numbers[i+1]){
                counts++;
            }
        }
        printf("%d\n",counts);
    }
    


    return 0;
}