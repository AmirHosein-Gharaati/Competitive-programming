#include <bits/stdc++.h>

using namespace std;

int q;
int marbles[10010];

int bs(int start, int end){
    
    if (end >= start){
        int mid = (start + end)/2;

        if (marbles[mid] == q){
            while(marbles[mid-1] == q) mid--;
            return mid;
        }
        else if (q > marbles[mid])
            return bs(mid+1, end);
        else if (q < marbles[mid])
            return bs(start, mid-1);
    }

    return -1;
    
    
}

int main(){

    int number, query;
    int counter = 1;
    while(1){
        cin >> number >> query;
        if (number == 0 && query == 0) break;

        for(int i = 0 ; i < number ; i++) cin >> marbles[i];

        sort(marbles, marbles+number);

        cout << "CASE# " << counter << ":" << endl;
        for(int i = 0 ; i < query ; i++){
            cin >> q;
            
            int result = bs(0, number-1);

            result!=-1
                ? cout << q << " found at " << result+1 << endl
                : cout << q << " not found" << endl;
        }
        counter++;
    }



    return 0;
}