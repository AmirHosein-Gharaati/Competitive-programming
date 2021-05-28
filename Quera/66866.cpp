#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> nodes;

int main(){

    int n;
    cin >> n;
    nodes.resize(100010);
    int number;
    int counter = 0;

    for(int i = 1 ; i <= n ;i++){
        cin >> number;
        nodes[number].push_back(i);
        
        counter += nodes[number-1].size();
        counter += nodes[number+1].size();
    }

    cout << counter;



    return 0;
}