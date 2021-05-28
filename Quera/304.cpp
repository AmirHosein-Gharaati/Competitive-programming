#include <bits/stdc++.h>

using namespace std;

long double myPow(long double base,unsigned int exp){
    if (base == 1){
        return 1;
    }
    if (base == 0){
        return 0;
    }
    if (exp == 1){
        return base;
    }
    if (exp == 0){
        return 1;
    }
    return base * myPow(base,exp-1);
}

int main() {
    long double base;
    unsigned int exp;
    scanf("%Lf %u",&base,&exp);
    printf("%.3Lf",myPow(base,exp));
    return 0;
} 