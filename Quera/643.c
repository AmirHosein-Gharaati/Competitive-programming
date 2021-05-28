#include <stdio.h>
#include <stdlib.h>

int numbers[500010];

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main(){
    int index=0;
    while (scanf("%d",&numbers[index]) != EOF){
        index++;
    }
    qsort(numbers,index,sizeof(int),cmpfunc);

    for (int i = 0; i < index; i++){
        printf("%d ",numbers[i]);
    }
    return 0;
}