#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAX = 1e12;


signed main(){


    int a, b;
    while(scanf("%lld %lld", &a, &b) && a+b != 0){

        map<int, int> ma;

        int step = 1;
        int i;
        for(i = a ; i != 1 ; step++ ){
            ma[i] = step;

            if(i % 2 == 0) i = i/2;
            else i = (3*i)+1;
        }
        ma[i] = step;

        step = 1;
        for(i = b ; i != 1 ; step++ ){
            if(ma[i] != 0){
                break;
            }
            else{
                if(i % 2 == 0) i = i/2;
                else i = (3*i)+1;
            }
        }
        
        printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", a, ma[i]-1, b, step-1, i);
    }


    return 0;
}