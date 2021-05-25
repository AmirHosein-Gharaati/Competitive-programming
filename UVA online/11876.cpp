#include <bits/stdc++.h>

using namespace std;

#define MAX 1000010

bool numbers[MAX];
int numberCounts[MAX];

int getDivisorsCount(int number){
    int count = 0;
    int i;
    for(i = 1; i*i < number ; i++){
        if(number%i == 0)
            count += 2;
    }
    if(i*i == number)
        count++;
    
    return count;
    
}

void init(){
    for(int i = 0 ; i < MAX-1 ; i++) numbers[i] = false;
    numbers[0] = false;
    numbers[1] = true;
    int base = 1;
    int newNumber;
    while(base < MAX-1){
        newNumber = base + getDivisorsCount(base);
        numbers[newNumber] = true;
        base = newNumber;
    }

    numberCounts[0] = 0;
    for(int i = 1 ; i < MAX-1 ; i++){
        if(numbers[i])
            numberCounts[i] = numberCounts[i-1] + 1;
        else
            numberCounts[i] = numberCounts[i-1];
    }
}

int main(){
    init();
    int tt;
    cin >> tt;
    int low, high;
    int count;

    for(int i = 0 ; i < tt ; i++){
        cin >> low >> high;
        cout << "Case " << i+1 << ": " << numberCounts[high] - numberCounts[low-1] << endl;
    }


    return 0;
}