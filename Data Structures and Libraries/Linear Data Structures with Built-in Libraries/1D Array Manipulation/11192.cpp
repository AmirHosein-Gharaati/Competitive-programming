#include <bits/stdc++.h>

using namespace std;

int main(){

    int group_length,len,multiply;
    char str[110];
    char new_str[110];
    while ((scanf("%d",&group_length)) && group_length ){
        scanf("%s",str);
        len = strlen(str);
        multiply = len / group_length;
        int j=0,k=0;
        for(int i = 0 ; i < group_length ; i++){
            j = i*multiply + multiply -1 ;
            for(int i = 0 ; i < multiply ; i++){
                new_str[k] = str[j];
                j--;
                k++;
            }
        }
        new_str[k] = '\0';
        printf("%s\n",new_str);
    }
    




    return 0;
}