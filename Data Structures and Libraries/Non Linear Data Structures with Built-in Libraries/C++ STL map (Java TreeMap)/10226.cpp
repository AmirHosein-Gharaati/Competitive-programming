#include <bits/stdc++.h>

using namespace std;


vector<string> tree_names;

int main(){

    int tt;
    int counts;
    string line;
    cin >> tt;
    cin.ignore();
    getline(cin,line);
    
    while(tt--){
        map <string,int> trees;
        counts = 0;
        while (getline(cin,line)){
            if (line.length() == 0){
                break;
            }
            counts++;
            if (trees.find(line) == trees.end()){
                trees[line] = 1;
            }
            else{
                trees[line] += 1;
            }  
        }
        for (auto x = trees.begin();x != trees.end();x++){
            if(x!=trees.begin()) printf("\n");
            cout << x->first;
            printf(" %.4f\n",double(x->second)*100/counts);
        }
        if(tt) cout<<endl<<endl; else cout<<endl;
    }
    


    return 0;
}