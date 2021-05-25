#include <bits/stdc++.h>

using namespace std;

int main(){
    set<int> s;
    int jill,jack;
    int title;
    while(scanf("%d %d",&jill,&jack) && jill && jack){
        s.clear();
        for (int i = 0; i < jill+jack; i++){
            scanf("%d",&title);
            s.insert(title);
        }
        int size = s.size();
        cout << (jill+jack) -size  << endl;
    }
    return 0;
}