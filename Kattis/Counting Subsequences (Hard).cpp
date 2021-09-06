#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int tt;
    scanf("%d", &tt);
    while(tt--){

        int n;
        scanf("%d" ,&n);

        if(n > 0){
            ll counter = 0;
            unordered_map<ll, int> occurrences;
            occurrences[0] = 1;
    
            ll last=0, current=0;
            for(int i = 0 ; i < n ; i++ ){
                scanf("%lld", &current);
                current += last;
                ll key = current - 47;
                if (occurrences.find(key) != occurrences.end())
                    counter += occurrences[key];

                if (occurrences.find(current) == occurrences.end()) 
                    occurrences[current] = 0;
                
                
                occurrences[current]++;
                last = current;

            }
            printf("%lld\n", counter);
        }
        else
            printf("0\n");
    }


    return 0;
}