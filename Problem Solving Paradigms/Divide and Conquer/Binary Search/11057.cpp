#include <bits/stdc++.h>

using namespace std;

#define MAX 10010
int prices[MAX];
int indexSave;

int bs(int start, int end, int number){

    if(end >= start){
        int mid = (start+end)/2;

        if(prices[mid] == number && mid != indexSave)
            return 1;
        else if(number > prices[mid])
            return bs(mid+1, end, number);
        else if(number < prices[mid])
            return bs(start, mid-1, number);
    }

    return -1;
}

int main(){

    int numberOfBooks;
    int money;
    while(scanf("%d", &numberOfBooks) != EOF){
        for(int i = 0 ; i < numberOfBooks ; i++){
            scanf("%d",&prices[i]);
        }

        sort(prices, prices+numberOfBooks);
        scanf("%d", &money);
        int a, b;
        int minn = 1000001;
        int i;
        for( i = 0 ; i < numberOfBooks ; i++){
            int result;
            int a2, b2;
            if(money-prices[i] > 0){
                a2 = prices[i];
                b2 = money - prices[i];
                indexSave = i;
                result = bs(0, numberOfBooks-1, b2);
            } else{
                continue;
            }

            if(result == 1){
                if(minn > abs(a2 - b2)){
                    a = a2;
                    b = b2;
                    minn = abs(a2-b2);
                }
            }
        }
        if(a > b){
            swap(a, b);
        }
        cout << "Peter should buy books whose prices are " << a << " and " << b << "." << endl << endl;
    }


    return 0;
}