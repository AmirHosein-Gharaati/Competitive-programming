#include <bits/stdc++.h>

using namespace std;

int numbers[22];
int n;

int cal(int sum){
    int result = 0;
    for(int i = 0 ; i < n ; i++){
        result += numbers[i] * (sum-numbers[i]);
    }
    return result;

}

int sumOfDigits(int number,int length){
    int sum = 0;
    while(number > 0){
        sum += pow((number%10),length);
        number = number / 10;
    }
    return sum;

}



int main(){
    int sum=0,number;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> number;
        sum += number;
        numbers[i] = number;
    }
    int EndInterval = cal(sum);
    for (int i = 100 ; i <= EndInterval ; i++){
        if (sumOfDigits(i,to_string(i).length()) == i){
            cout << i << endl;
        }
    }
    
    return 0;
}