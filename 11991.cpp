#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k,v,count;
    cin >> n >> m;
    cin.ignore();
    string line;
    int temp,flag,index;
    getline(cin,line);
    cin.ignore();
    stringstream ss;
    for (int i = 0; i < m; i++){
        flag = 0;
        cin >> k >> v;
        ss << line;
        count = 0;
        index = 0;
        while (ss >> temp){
            index++;
            if(temp == v){
                count++;
            }
            if(count == k){
                flag = 1;
                break;
            }
        }
        if(flag){
            cout << index << endl;;
        }
        else{
            cout << "0" << endl;
        }

    }
    return 0;
}