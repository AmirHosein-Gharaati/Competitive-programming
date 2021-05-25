#include <bits/stdc++.h>

using namespace std;

int main(){
    int tt;
    int front[10],right[10];
    bool pos[10];
    scanf("%d",&tt);
    while (tt--){
        fill(pos,pos+10,false);
        int sizee;
        scanf("%d",&sizee);
        for(int i = 0 ; i < sizee ; i ++){
            scanf("%d",&front[i]);
        }
        for(int i = 0 ; i < sizee ; i ++){
            scanf("%d",&right[i]);
        }
        int mini = 0;
        int maxi = 0;
        for (int i = 0; i < sizee; i++){
            mini += front[i];
            for (int j = 0; j < sizee; j++){
                if (front[i] == right[j] && !pos[j]){
                    pos[j] = true;
                    break;
                }
            }
        }
        for (int i = 0; i < sizee; i++){
            if(!pos[i]){
                mini += right[i];
            }
        }

        for (int i = 0; i < sizee; i++){
            for (int j = 0; j < sizee; j++){
                maxi += min(front[i],right[j]);
            }
            
        }
        printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n",mini,maxi-mini);
    }
    return 0;
}