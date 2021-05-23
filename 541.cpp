#include <bits/stdc++.h>

using namespace std;

int matrix[105][105];

int checker(int n){
    int row,column,rr=0,cc=0,sr,sc;
    int i , j;
    for (int i = 0; i < n; i++){
        sc =0;
        sr =0;
        for(int j = 0 ; j < n ; j++){
            sc += matrix[i][j];
            sr += matrix[j][i];
        }
        if(sc%2!=0){
            cc++;
            column = i;
        }
        
        if(sr%2 != 0){
            rr++;
            row = i;
        }
    }

    if (rr == 1 && cc == 1){
        printf("Change bit (%d,%d)\n",column+1,row+1);
        return 1;
    }
    else if (rr == 0 && cc == 0){
        printf("OK\n");
    }
    else{
        printf("Corrupt\n");
    }
    return true;
}

int main(){

    int size;
    while (scanf("%d",&size) && size){

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                scanf("%d",&matrix[i][j]);
            }
        }

        checker(size);
    }
    return 0;
}