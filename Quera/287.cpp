#include <bits/stdc++.h>

using namespace std;

bool isPrime(int number){
    for (int i = 2; i <= int(sqrt(number)); i++){
        if(number % i == 0){
            return false;
        }
    }
    
    return true;
}

int sumOfPrimes(int number){
    int sum = 0;
    for (int i = 2; i <= number; i++){
        if(isPrime(i) && number%i == 0){
            sum += i;
        }
    }
    return sum;
}

int sumOfDigits(int number){
    int sum = 0;
    while (number > 0){
        sum += number%10;
        number = int(number /10);
    }
    return sum;
}

int main() {
    int tt;
    int number;
    int sum,flag;
    scanf("%d",&tt);
    while (tt--){
        scanf("%d",&number);
        sum =0;
        flag =0;
        for (int i = 2; i < number; i++){
            if (sumOfDigits(i) + sumOfPrimes(i) + i == number){
                printf("Yes");
                flag =1;
                break;
            }
        }
        if(flag == 0){
            printf("No");
        }
        if(tt != 0){
            printf("\n");
        }
    }
    
    return 0;
} 