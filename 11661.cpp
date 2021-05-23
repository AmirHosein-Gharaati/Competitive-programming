#include <bits/stdc++.h>

using namespace std;

char locations[2000005];

int init_saved(char* saved){
    int i =0;
    while (locations[i] != 'R' && locations[i] != 'Z' && locations[i] != 'D'){
        i++;
    }

    *saved = locations[i];
    return i;
}

int main(){
    int n,i,saved_index,distance;
    char saved;
    while (scanf("%d",&n) && n){
        scanf("%s",locations);

        i = init_saved(&saved);
        saved_index = i;
        distance = INT_MAX;

        for(i ; i < n ; i++){
            if(locations[i] == 'Z'){
                distance = 0;
                break;
            }
            else if (locations[i] == saved)
                saved_index = i;
            
            else if (locations[i] != saved && locations[i] != '.'){
                if(i - saved_index < distance)
                    distance = i - saved_index;
                saved = locations[i];
                saved_index = i;
            }
        }
        printf("%d\n",distance);
    }
    return 0;
}