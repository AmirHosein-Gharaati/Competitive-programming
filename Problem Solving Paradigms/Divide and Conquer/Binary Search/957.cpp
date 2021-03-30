#include <bits/stdc++.h>

using namespace std;

#define MAX 100010

int number;
int numbers[100010];

int bs(int start, int end){

    int mid = (start+end) /2;

    if(numbers[mid] == number){
        while(numbers[mid+1] == number) mid++;
        return mid;
    }

    if(start >= end){
        while(numbers[start] > number) start--;
        return start;
    }

    if(numbers[mid] > number)
        return bs(start, mid-1);
    if(numbers[mid] < number)
        return bs(mid+1, end);
}

int main(){

    int range;
    
    while(scanf("%d", &range) != EOF){
        int tt;
        cin >> tt;
        for(int i = 0 ; i < tt ; i++){
            cin >> numbers[i];
        }
        int low, high;
        

        int mainLow , mainHigh;
        int diff = 0;
        for(int i = 0 ; i < tt ; i++){
            low = i;

            number = numbers[i]+range-1;
            high = bs(0, tt-1);

            if(abs(high - low + 1) > diff){
                mainLow = numbers[low];
                mainHigh = numbers[high];
                diff = abs(high-low+1);
            }

            // cout << diff << " " << low << " " << numbers[high] << endl;
        }
        cout << diff << " " << mainLow << " " << mainHigh << endl;
    }

    return 0;
}