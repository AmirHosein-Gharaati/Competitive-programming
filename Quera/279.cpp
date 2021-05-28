#include <bits/stdc++.h>

using namespace std;

int fac(int n){
    int s = 1;
    for (int i = 1; i <= n; i++){
        s *= i;
    }
    return s;
    
}

int myPow(int base,int exp){
    int summ = 1;
    if(exp == 0){
        return 1;
    }
    for (int i = 0; i < exp; i++){
        summ *= base;
    }
    return summ;
    
}
   
int main() {
    int a,x,n,sum;
    cin >> a >> x >> n;
    int fac_n = fac(n) , facc,mp1,mp2;
    sum = 0;
    for (int k = 0; k <= n; k++){
        facc = fac_n/(fac(n-k)*fac(k));
        mp1 = myPow(x,k);
        mp2 = myPow(a,n-k);
        sum += facc*mp1*mp2;
    }
    printf("%d",sum);
    return 0; 
} 