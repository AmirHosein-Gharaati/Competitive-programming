#include <bits/stdc++.h>

using namespace std;

vector<int> v;


int main(){

    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int number;
        cin >> number;
        v.push_back(number);
    }

    int counter = 1;
    int maxx = 1;

    for(int i = 1 ; i < n ; i++){
        if(v[i] >= v[i-1]){
            counter++;
            maxx = max(maxx, counter);
        }
        else{
            counter = 1;
        }
    }

    cout << maxx;



    return 0;
}