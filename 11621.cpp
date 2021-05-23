#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;


int main(){

    int min ;

    int a = 0, b = 0;
    int number;
    while(scanf("%d", &number) && number != 0){
        while(pow(2, a) < number) a++;
        while(pow(3, b) < number) b++;

        int current;
        min = INT_MAX;
        for(int i = 0 ; i <= a ; i++){
            for(int j = 0 ; j <= b ; j++){
                current = pow(2, i) * pow(3, j);
                if (current >= number && current < min) min = current;
            }
        }

        cout << min << endl;
    }



    return 0;
}