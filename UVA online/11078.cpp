#include <bits/stdc++.h>

using namespace std;


int main(){


    int n;
    int tt;
    scanf("%d", &tt);
    while(tt--){
        scanf("%d", &n);
        vector<int> numbers;
        numbers.clear();
        for(int i = 0 ; i < n ; i++){
            int a;
            scanf("%d", &a);
            numbers.push_back(a);
        }

        int maxx_num = numbers[0];
        int max_diff = -1;

        for(int i = 1 ; i < n ; i++){
            if(maxx_num - numbers[i] > 0){
                max_diff = max(max_diff, maxx_num - numbers[i]);
            }
            maxx_num = max(maxx_num, numbers[i]);
        }

        cout << max_diff << endl;        
        
    }



    return 0;
}