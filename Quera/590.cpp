#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a,long long int b){
    if (a == 0){
        return b;
    }
    else{
        return gcd(b%a,a);
    }

}

long long int lcm(long long int a,long long int b,long long int gcdd){
    return (a*b) / gcdd;
}

int main(){
    long long int m,n;
    cin >> m >> n;
    long long int gcdd = gcd(m,n);
    long long int lcmm = lcm(m,n,gcdd);
    cout << gcdd << " "<< lcmm;

    return 0;
}