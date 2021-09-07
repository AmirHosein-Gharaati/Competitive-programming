#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, x;
    cin >> n >> x;

    vector<int> children(n);
    for(int i = 0 ; i < n ; i++)
        cin >> children[i];

    sort(children.begin(), children.end());

    int counter = 0;
    int i = 0;
    int j = n-1;

    while(i <= j){
        
        if(children[i] + children[j] <= x){
            j--;
            i++;
        }else{
            j--;
        }

        counter++;
    }

    cout << counter;

    return 0;
}