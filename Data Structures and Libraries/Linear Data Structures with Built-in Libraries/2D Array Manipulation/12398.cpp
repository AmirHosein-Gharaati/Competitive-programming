#include <bits/stdc++.h>

using namespace std;

int square[5][5];

void changeNumber(int row,int column){
    square[row][column] =   (square[row][column]+1)%10;
    square[row-1][column] = (square[row-1][column]+1)%10 ;
    square[row][column-1] = (square[row][column-1]+1)%10 ;
    square[row+1][column] = (square[row+1][column]+1)%10 ;
    square[row][column+1] = (square[row][column+1]+1)%10 ;

}

int main(){

    int len,number=1;
    char c;
    string line;
    while (getline(cin,line)){
        fill( &square[0][0], &square[0][0] + sizeof(square), 0 );
        len = line.length();
        for (int i = len - 1; i >= 0; i--){
            c = line[i];
            switch (c){
                case 'a':
                    changeNumber(1,1);
                    break;
                case 'b':
                    changeNumber(1,2);
                    break;
                case 'c':
                    changeNumber(1,3);
                    break;
                case 'd':
                    changeNumber(2,1);
                    break;
                case 'e':
                    changeNumber(2,2);
                    break;
                case 'f':
                    changeNumber(2,3);
                    break;
                case 'g':
                    changeNumber(3,1);
                    break;
                case 'h':
                    changeNumber(3,2);
                    break;
                case 'i':
                    changeNumber(3,3);
                    break;
                
            }
        }
        printf("Case #%d:\n",number++);
        for(int i = 1; i <=3 ; i++){
            for (int j = 1; j <=3 ; j++){
                printf("%d",square[i][j]);
                if (j != 3)
                    printf(" ");
            }
            printf("\n");
        }
    }
    



    return 0;
}