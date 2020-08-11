#include <bits/stdc++.h>

using namespace std;

map <string,int> trees;
vector<string> tree_names;

int main(){

    int tt;
    long long int counts;
    string line;
    cin >> tt;
    getline(cin,line);
    cin.ignore();
    for (int i = 0; i < tt; i++){
        counts = 0;
        tree_names.clear();
        trees.clear();
        while (getline(cin,line)){
            if (line.size() == 0){
                break;
            }
            trees[line] += 1;
            counts++;
            if (trees.find(line) == trees.end()){
                tree_names.push_back(line);
            }   
        }
        sort(tree_names.begin(),tree_names.end());
        for (auto x : tree_names){
            cout << x << " "<< trees[x]*1.0/1.0*counts << endl;
        }
    }
    


    return 0;
}