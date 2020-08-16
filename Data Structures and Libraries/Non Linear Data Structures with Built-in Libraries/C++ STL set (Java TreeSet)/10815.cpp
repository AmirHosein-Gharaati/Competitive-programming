#include <bits/stdc++.h>

using namespace std;

bool isAlpha(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

int main(){
    char c;
    string text;
    set<string> pq;
    while((c=getchar())!= EOF){
        if(isAlpha(c)){
            text.push_back(tolower(c));
        }
        else{
            text.push_back(' ');
        }
    }
    stringstream ss(text);
    string tmp;
    while(ss >> tmp){
        pq.insert(tmp);
    }
    for(auto word: pq){
        cout << word << endl;
    }
    return 0;
}