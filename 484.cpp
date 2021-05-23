#include <bits/stdc++.h>

using namespace std;

map<int,int> m;
vector<int> v;

int main(){
    int number;
    while (scanf("%d",&number) != EOF){
        if(m.find(number) == m.end()){
            v.push_back(number);
        }
        m[number] += 1;
    }
    for(auto x: v){
        printf("%d %d\n",x,m[x]);
    }

    return 0;
}