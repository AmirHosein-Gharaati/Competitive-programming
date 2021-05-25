#include <bits/stdc++.h>

using namespace std;

int used[26], candidates[26];
int mp[26][26];
int n;
char str[26];


void dfs(int index){
    if(index == n){
        str[index] = '\0';
        puts(str);
        return;
    }

    for(int i = 0 ; i < 26 ; i++){
        if(candidates[i] == 1 && used[i] == 0){
            for(int j = 0 ; j < 26 ; j++){
                if(mp[i][j] == 1 && used[j] == 1)
                    return;
            }
            used[i] = 1;
            str[index] = i+'a';
            dfs(index+1);
            used[i] = 0;
        }
    }
}

int main(){


    stringstream sin;
    string line;
    char ch, ch2;
    int first = 1;

    while(getline(cin, line)){

        if(!first)
            puts("");

        memset(mp, 0, sizeof(mp));
        memset(used, 0, sizeof(used));
        memset(candidates, 0, sizeof(candidates));
        
        sin.clear();
        sin << line;
        n = 0;

        while(sin >> ch){
            candidates[ch-'a'] = 1;
            n++;
        }

        getline(cin, line);
        sin.clear();

        sin << line;
        while(sin >> ch >> ch2){
            mp[ch-'a'][ch2-'a'] = 1;
        }
        dfs(0);
        first = 0;

    }



    return 0;
}