#include <bits/stdc++.h>

using namespace std;

int main(){

    int tt;
    cin >> tt;
    int number, counter =0;
    while(tt--){
        cin >> number;
        if (number < 0) counter++;
    }

    cout << counter;



    return 0;
}