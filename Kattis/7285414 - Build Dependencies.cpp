#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
map<int, string> mp1;
map<string, int> mp2;
vector<bool> visited;
vector<string> ans;
int n;

void dfs(int u){
    visited[u] = true;

    for(int num : adj[u]){
        if(!visited[num])
            dfs(num);
    }

    ans.push_back(mp1[u]);
}



int main(){

    cin >> n;
    adj.resize(n+1);
    visited.assign(n+1, false);
    string line;
    stringstream sin;
    int number = 0 ;
    cin.ignore(256, '\n');

    for(int i = 0 ; i < n ; i++){
        getline(cin, line);
        sin.clear();
        sin << line;

        string first;
        sin >> first;

        int index = first.find(":");
        first = first.substr(0, index);

        // cout << first << " ";

        if(mp2.find(first) == mp2.end()){
            mp2[first] = number;
            mp1[number] = first;
            number++;
        }
        int num1 = mp2[first];

        string word;
        while(sin >> word){
            // cout << word << " ";
            if(mp2.find(word) == mp2.end()){
                mp2[word] = number;
                mp1[number] = word;
                number++;
            }

            int num2 = mp2[word];
            adj[num2].push_back(num1);
        }
        // cout << endl;

    }


    string startingPoint;

    cin >> startingPoint;
    int ind = mp2[startingPoint];
    dfs(ind);
    reverse(ans.begin(), ans.end());
    for(string s : ans)
        cout << s << endl;


    return 0;
}