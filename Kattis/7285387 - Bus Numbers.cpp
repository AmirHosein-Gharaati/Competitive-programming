#include <bits/stdc++.h>

using namespace std;

int main(){

    int tt;
    cin >> tt;
    int nums[1010];

    for(int i = 0 ; i < tt ; i++){
        cin >> nums[i];
    }

    sort(nums, nums+tt);

    int number, firstNum, lastNum;
    int i = 0;
    while(i < tt){
        number = nums[i];

        int j = i+1;
        int len = 1;
        firstNum = number;
        lastNum = number;
        while(j < tt && nums[j] == lastNum+1){
            lastNum = nums[j];
            j++;
            len++;
        }


        if(len > 2){
            cout << firstNum << "-" << lastNum << " ";
            i = j;
        }
        
        else{
            cout << number << " ";
            i++;
        }
    }



    return 0;
}