#include <bits/stdc++.h>

using namespace std;

int bs(int start, int end, int number){

    if (number == 1)
        return start;

    int mid = (start+end)/2;

    if (number%2 == 1)
        return bs(start, mid, (number+1)/2);
    else
        return bs(mid+1, end, number/2);
}

int main(){
    int tt;
    int depth, number;
    cin >> tt;
    while(tt--){
        cin >> depth >> number;
        cout << bs(pow(2, depth-1), pow(2, depth)-1, number) << endl;
    }


    return 0;
}