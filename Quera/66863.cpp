#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

bool numberToBase(int n,int b){
    string letters = "0123456789ABCDEF";
    string digits = "";
    while (n){
        digits = digits + letters[n%b];
        n = n / b;
    }
    return digits == string(digits.rbegin(),digits.rend()) ;
}

bool isPrime(int n){
    for(int i = 0;i<primes.size() && primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0){
            return false;
        }
    }
    primes.push_back(n);
    return true;
}

int main(){
    int n,k;
    cin >> n >> k;
    int count = 0;
    string temp, rev;

    if (numberToBase(2,k)){
        count += 1;
    }
    primes.push_back(2);

    while (1){
        int i;
        for(i = 3; count != n ; i = i+2){
            if(isPrime(i) && numberToBase(i,k)){
                count += 1;
            }
        }
        cout << i-2;
        return 0;
    }
    
}