#include <bits/stdc++.h>

using namespace std;

int arr[150];

int main(){

    int w, p;
    vector<int> v;
    cin >> w >> p;
    v.push_back(0);
    int temp;
    for(int i = 0 ; i < p; i++){
        cin >> temp;
        v.push_back(temp);
    }
    v.push_back(w);

    set<int> s;

    for(int i = 0 ; i < p+2 ; i++){

        for(int j = i+1 ; j < p+2; j++){
            s.insert(v[j]-v[i]);
        }
    }

    for(int num : s){
        cout << num << " ";
    }



    return 0;
}