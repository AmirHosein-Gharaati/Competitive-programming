#include <bits/stdc++.h>
using namespace std;

multiset<int> tickets;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        int h;
        cin >> h;
        tickets.insert(h);
    }

    for(int i = 0 ; i < m ;i++){
        int price;
        cin >> price;
        auto it = tickets.upper_bound(price);
        if(it == tickets.begin()){
            cout << -1 << endl;
        }
        else{
            cout << *(--it) << endl;
            tickets.erase(it);
        }
    }
        
    


    return 0;
}