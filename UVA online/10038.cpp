#include <bits/stdc++.h>

using namespace std;

bool flags[3005];

int main(){
    int n,a1,a2;

    while (scanf("%d",&n) != EOF){
        scanf("%d",&a1);
        for(int i =1 ; i < n ; i++){
            scanf("%d",&a2);
            flags[abs(a1-a2)] = true;
            a1 = a2;
        }
        bool isJolly = true;
        for (int i = 1; i < n; i++) {
            if (!flags[i]) {
                isJolly = false;
                break;
            }
        }
        printf(isJolly ? "Jolly\n" : "Not jolly\n");
        memset(flags, false, sizeof(flags));
    }
    return 0;
}