#include <bits/stdc++.h>

using namespace std;

int matrix[105][105];

bool checker(int n){
    int row_sum=0,column_sum=0;
    for (int i = 0; i < n; i++){
        for(int j = 0 ; j < n ; j++){
            row_sum += matrix[i][j];
            column_sum += matrix[j][i];
        }
        if (row_sum%2 != 0 || column_sum%2 != 0){
        return false;
        }
    }
    return true;
}

int finder(int size){
    int row,column,rr=0,cc=0,sr,sc;
    int j , i;
    for (i = 0; i < size; i++){
        sc = 0;
        sr=0;
        for (j = 0; j < size; j++){
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
    else{
        return 0;
    }
}

int main(){

    int size;
    while (scanf("%d",&size) && size){

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                scanf("%d",&matrix[i][j]);
            }
        }

        if (checker(size)){
            printf("OK\n");
            continue;
        }
        else{
            int result = finder(size);
            if(result == 0){
                printf("Corrupt\n");
            }
        }
    }
    return 0;
}