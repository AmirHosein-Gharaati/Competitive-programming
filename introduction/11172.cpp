#include <bits/stdc++.h>

using namespace std;

int main(){
    int nt;
    long long int a , b;

    cin >> nt;
    while (nt--)
    {
        cin >> a >> b;
        if (a > b){
            cout << ">" << endl;
        }
        else if (a < b){
            cout << "<" << endl;
        }
        else{
            cout << "=" << endl;
        }
        
    }
    



    return 0;
}