#include <bits/stdc++.h>

using namespace std;

#define MAX 10010

int nums[MAX];
int maxSeq[MAX];

int main(){

    int tt;
    while(scanf("%d", &tt) && tt != 0){
        for(int i = 0 ; i < tt ; i++){
            cin >> nums[i];
        }

        for(int i = 0 ; i < tt ; i++) maxSeq[i] = 0;
        maxSeq[0] = nums[0];
        int max = 0;
        for(int i = 1 ; i < tt ; i++){
            if(maxSeq[i-1] > 0){
                maxSeq[i] = nums[i] + maxSeq[i-1];
                if(maxSeq[i] > max) max = maxSeq[i];
            }
            else{
                maxSeq[i] = nums[i];
            }
        }
        if(max > 0)
            cout << "The maximum winning streak is " << max << "." << endl;
        else
            cout << "Losing streak." << endl;

    }


    return 0;
}