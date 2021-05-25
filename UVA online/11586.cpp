#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,M_counts,F_counts,count_woods;
    cin >> n;
    cin.ignore();
    string line,temp;
    
    for(int i = 0; i < n ; i++){
        M_counts = 0;
        F_counts = 0;
        count_woods = 0;
        getline(cin,line);
        stringstream l(line);
        while(l >> temp){
            if (temp[0] == 'M' || temp[1] == 'M')
                M_counts++;

            if (temp[0] == 'F' || temp[1] == 'F')
                F_counts++;
            count_woods++;
        }
        if(M_counts == F_counts && count_woods != 1){
            cout << "LOOP" << endl;
        }
        else{
            cout << "NO LOOP" << endl;
        }
    }



    return 0;
}