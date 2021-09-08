#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, x;
    cin >> n >> x;
    
    map<int, multiset<int>> ni;
    multiset<int> numbers;
    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        numbers.insert(a);
        ni[a].insert(i);
    }

    bool flag = false;
    for(auto it = numbers.begin() ; it != numbers.end() ; it++){
        int num = *(it);
        if(num < x){
            if(x-num == num){
                if(ni[num].size() > 1){
                    auto it = ni[num].begin();
                    cout << *(it)+1 << " ";
                    it++;
                    cout << *(it)+1;
                    flag =true;
                    break;
                }
            }
            else if(numbers.find(x-num) != numbers.end()){
                cout << *(ni[num].begin())+1 << " " << *(ni[x-num].begin())+1;
                flag = true;
                break;
            }
        }
    }
    if(!flag){
        cout << "IMPOSSIBLE";
    }

    return 0;
}