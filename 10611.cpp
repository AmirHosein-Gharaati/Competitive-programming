#include <bits/stdc++.h>

using namespace std;

#define MAX 50010
int heights[MAX];
int tests[MAX/2];
int number;
int n;

int bs(int start, int end){

    int mid = (start+end)/2;

    if(heights[mid] == number){
        for(int i = mid ; i >= 0 ; i--){
            if (heights[i] < number) return i;
        }
        return -1;
    }
    
    if(start >= end){
        for(int i = start ; i >=0 ; i--){
            if(heights[i] < number) return i;
        }
        return -1;
    }

    if(number > heights[mid])
        return bs(mid+1, end);
    else
        return bs(start, mid-1);
}

int binary(int start, int end){
    int mid = (start+end)/2;
    
    if(heights[mid] == number){
        for(int i = mid ; i < n ; i++){
            if (heights[i] > number) return i;
        }
        return -1;
    }
    
    if(start >= end){
        for(int i = start ; i < n ; i++){
            if (heights[i] > number) return i;
        }
        return -1;
    }

    if(number > heights[mid])
        return binary(mid+1, end);
    else
        return binary(start, mid-1);
}

int main(){
    
    cin >> n;
    for(int i = 0 ; i < n ;i++) cin >> heights[i];

    int height;
    cin >> height;
    int a, b;

    for(int i = 0 ; i < height ;i++){
        cin >> number;
        a= -1;
        b = -1;


        a = bs(0, n-1);
        b = binary(0 ,n-1);

        if(a == -1) cout << "X ";
        else cout << heights[a] << " ";

        if(b == -1) cout << "X" << endl;
        else cout << heights[b] << endl;
    }   



    return 0;
}