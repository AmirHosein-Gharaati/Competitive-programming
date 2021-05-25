#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, t;
    cin >> n >> t;
    int number;
    int total=0, counter=0;
    while(n--){
        cin >> number;
        
        if(total + number <= t){
            counter++;
            total += number;
        }
        else
            break;
    }

    cout << counter;
    
    return 0;
}