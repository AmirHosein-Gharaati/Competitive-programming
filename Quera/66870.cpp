#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> ip;

map<int, int> mp;
vector<int> numbers;
vector<ip> arr;

bool func(ip n1, ip n2){
    if(n1.first < n2.first) return true;
    else if(n1.first == n2.first){
        if(n1.second.first < n2.second.first) return true;
        else return false;
    }
    return false;
}

int main(){

    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        if(mp[num] == 0){
            numbers.push_back(num);
            mp[num]++;
        }
    }

    int a, b;
    for(int i = 0 ; i < numbers.size(); i++){
        for(int j = i+1 ; j < numbers.size(); j++){
            a = numbers[i];
            b = numbers[j];
            
            if(b < a) swap(a, b);

            arr.push_back(make_pair(abs(a-b), make_pair(a, b)));
        }
    }

    // cout << arr.size();

    sort(arr.begin(), arr.end(), func);

    for(int i = 0 ; i < arr.size(); i++){
        cout << "[" << arr[i].second.first << ", " << arr[i].second.second << "]" << endl;
    }

    return 0;
}