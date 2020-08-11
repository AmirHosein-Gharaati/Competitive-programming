#include <bits/stdc++.h>

using namespace std;

int main(){

    queue<int> q;
    int n,d;
    while (scanf("%d",&n) && n){
        for (int i = 1; i <= n; i++){
            q.push(i);
        }

        printf("Discarded cards:");
        bool first = true;
        while (q.size() > 1){
            d = q.front();
            if(first){
                printf(" %d",d);
                first = false;
            }
            else{
                printf(", %d",d);
            }
            q.pop();
            d = q.front();
            q.pop();
            q.push(d);
        }
        printf("\nRemaining card: %d\n",q.front());
        q.pop();
        
        
    }
    



    return 0;
}