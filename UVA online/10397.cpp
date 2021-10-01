#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    map<string, int> exists;
    vector<string> words;
    int counter = 0;

    while(cin >> str){
        exists[str] = 1;
        words.push_back(str);
        counter++;
    }

    vector<string> found;

    for(int i = 0 ; i < counter ; i++){
        int len = words[i].length();
        for(int j = 0 ; j < len; j++){
            string a = words[i].substr(0, j);
            string b = words[i].substr(j,len);
            if(exists[a] && exists[b]){
                found.push_back(words[i]);
                break;
            }
        }
    }

    sort(found.begin(), found.end());

    for(auto word : found)
        cout << word << endl;


    return 0;
}