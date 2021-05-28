#include <stdio.h>
int lis[10][10];
int f(int l,int row,int column){
	int k;
	for (k=0;k<9;k++){
		if (lis[row][k] == l || lis[k][column] == l){
			return -1;
		}
	}
	int r,c;
	if (row >= 0 && row<= 2){
		r =0;
	}
	else if (row >= 3 && row<= 5){
		r =3;
	}
	else if (row >= 6 && row<= 8){
		r =6;
	}
	
	
	if (column >= 0 && column<= 2){
		c =0;
	}
	else if (column >= 3 && column<= 5){
		c =3;
	}
	else if (column >= 6 && column<= 8){
		c =6;
	}
	
	int i,j;
	for (i=r;i<r+3;i++){
		for (j=c;j<c+3;j++){
			if (lis[i][j] == l){
				return -1;
			}
		}
	}
	return 1;
}




int checker(int row,int column){
	int i,result;
	for (i=1;i<10;i++){
		if (f(i,row,column) == 1){
			lis[row][column] = i;
			if (column == 8 && row == 8){
				return 1;
			}
			else{
				result = solver(0,0);
			}
			if (result == -1){
				lis[row][column] = 0;
			}
			else{
				return 1;
			}
		}
	}
	return -1;
}


int solver(int row,int column){
	int i,j,res;
	for (i=row;i<9;i++){
		for (j=column;j<9;j++){
			if (lis[i][j] == 0){
				res = checker(i,j);
				if (res == -1){
					return -1;
				}
				return 1;
			}
		}
	}
}

int main(){
	int j,i;
	for(i=0;i<9;i++){
		for (j=0;j<9;j++){
			scanf("%d",&lis[i][j]);
		}
	}
	int result;
	result = solver(0,0);
	
	for (i=0;i<9;i++){
		for (j=0;j<9;j++){
			printf("%d ",lis[i][j]);
		}
		printf("\n");
	}
	
	
	
	
	return 0;
}
