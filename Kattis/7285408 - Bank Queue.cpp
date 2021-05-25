#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

bool compare(ii a, ii b){
    
    if(a.first > b.first)
        return true;

    return false;
}



int main(){

    int n, t;
    cin >> n >> t;
    vector<ii> pairs;
    ii temp;
    int arr[50];
    for(int i = 0 ; i < 50 ;i++) arr[i] = -1;

    for(int i = 0 ; i < n ; i++){
        cin >> temp.first >> temp.second;
        pairs.push_back(temp);
    }

    sort(pairs.begin(), pairs.end(), compare);

    int time = 0;
    int index = 0;
    long long money = 0;
    
    for(int i = 0 ; i < n ; i++){
        ii temp = pairs.at(i);
        index = temp.second;

        while(index >= 0 && arr[index] != -1)
            index--;

        if(index != -1){
            arr[index] = 1;
            // cout << index << endl;
            money += temp.first;
        }
        
    }

    cout << money;

    return 0;
}