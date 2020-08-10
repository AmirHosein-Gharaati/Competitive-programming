//WA

#include <bits/stdc++.h>

using namespace std;

bool test(string str1,string str2){
    int i;
    i = 0;
    while (1){
        if (str1[i] > str2[i]){
            return true;
        }
        else if (str1[i] == '\0' && str2[i] != '\0'){
            return true;
        }
        else if (str1[i] < str2[i]){
            return false;
        }
        else if (str1[i] != '\0' && str2[i] == '\0'){
            return false;
        }
        else if(str1[i] == '\0' && str2[i] =='\0'){
            return false;
        }
        i++;
    }
}

int main(){
    int n;
    vector<string> a;
    string str;
    while (cin >> n && n){
        for (int i = 0; i < n; i++){
            cin >> str;
            a.push_back(str);
        }
        sort(a.begin(),a.end(),test);
        for(int j = a.size()-1; j>=0 ; j--){
            cout << a[j];
        }
        cout << endl;
        a.clear();
        
    }
    return 0;
}