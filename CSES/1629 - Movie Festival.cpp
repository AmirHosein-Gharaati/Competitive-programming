#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin >> n;
    vector<pair<int, int>> ranges(n);
 
    for(int i = 0 ; i < n ; i++){
        cin >> ranges[i].second >> ranges[i].first;
    }
 
    sort(ranges.begin(), ranges.end());
 
    int counter = 0;
    int curr_end = 0;

    for(auto time : ranges){
        if(time.second >= curr_end){
            counter++;
            curr_end = time.first;
        }
    }
    
    cout << counter;
 
    return 0;
}