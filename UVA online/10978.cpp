#include <bits/stdc++.h>

using namespace std;


int main(){
    bool pos[55];
    string chars,names;
    string places[55];
    int n,place,mod,len;
    while (scanf("%d",&n) && n){
        memset(pos , 0,sizeof(pos));
        mod = n;
        place = -1;
        for(int i = 0 ; i < n ; i++){
            cin >> chars >> names;
            len = names.size();
            while (len--) {
                do {
                    place = (place + 1) % n;
                } while (pos[place]);
            }
            places[place] = chars;
            pos[place] = true;
        }
        for(int i = 0 ; i < n ; i++){
            if (i) cout << " ";
            cout << places[i];
        }
        cout << endl;    
    }
    return 0;
}