#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,number,k,v,count,index,flag;
    vector<int> vec;
    while (cin >> n >> m){
        for(int i = 0 ; i < n ; i++){
            cin >> number;
            vec.push_back(number);
        }
        for(int i = 0 ; i< m ; i++){
            count = 0;
            index = 0;
            flag = 0;
            cin >> k >> v;
            for(auto a: vec){
                index++;
                if(a == v){
                    count++;
                }
                if(count == k){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                cout << index << endl;
            }
            else{
                cout << "0" << endl;
            }
        }
    }
    
    return 0;
}