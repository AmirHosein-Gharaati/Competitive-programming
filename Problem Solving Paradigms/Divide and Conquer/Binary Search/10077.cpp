#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

ii final;

void bs(ii left, ii right, ii myPoint){
    if(myPoint.first == final.first && myPoint.second == final.second){
        cout << endl;
        return;
    }
    
    ii temp;
    
    if (final.first * myPoint.second < final.second * myPoint.first){
        cout << "L";
        temp.first = myPoint.first;
        temp.second = myPoint.second;

        myPoint.first += left.first;
        myPoint.second += left.second;
        bs(left, temp, myPoint);
    }
    else{
        cout << "R";
        temp.first = myPoint.first;
        temp.second = myPoint.second;

        myPoint.first += right.first;
        myPoint.second += right.second;
        bs(temp, right, myPoint);
    }
}

int main(){
    
    
    int top, down;

    while(1){
        cin >> final.first >> final.second;
        if (final.first == 1 && final.second == 1) break;
        bs(ii(0,1), ii(1,0), ii(1,1));

    }
    return 0;
}