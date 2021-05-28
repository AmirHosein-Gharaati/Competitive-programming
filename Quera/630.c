#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char arr[1010][1010];
char temp[1010];

int myStrcmp(char arr1[],char arr2[]){
	int i=0;
	char a1,a2,tt=2;
	while(tt--){
        a1 = arr1[i];
    
        a2 = arr2[i];

        if (abs(a1-a2) != 32){
            if (a1 >= 'A' && a1 <= 'Z'){
                a1 = a1 - 'A' + 'a';
            }
            if (a2 >= 'A' && a2 <= 'Z'){
                a2 = a2 - 'A' + 'a';
            }
        }
		
		if (a1 < a2){
			return 1;
		}
		if (a1 > a2){
			return -1;
		}
		if (a1 == a2 && a1 == '\0'){
			return 0;
		}
		i++;
	}
    return 0;
	
}
void mySort(char arr[][1010],int n){
	int i,j,flag;
	
	for (i=0;i<n;i++){
		flag=0;
		for (j=0;j<n-1;j++){
			if (myStrcmp(arr[j],arr[j+1]) < 0){
				strcpy(temp,arr[j]);
				strcpy(arr[j],arr[j+1]);
				strcpy(arr[j+1],temp);
				flag =1;
			}
		}
		if (flag == 0){
			break;
		}
	}
}

int main(){
	int i;
    i=0;

    while (1){
        scanf("%s",arr[i]);
        if(strcmp(arr[i],"0") == 0){
            break;
        }
        i++;
    }
    
    mySort(arr,i);
    
    for (int k = 0; k < i; k++){
        printf("%s ",arr[k]);
    }
	
	return 0;
}
