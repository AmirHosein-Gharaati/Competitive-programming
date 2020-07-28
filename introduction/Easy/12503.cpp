#include <bits/stdc++.h>

using namespace std;

int main(){

    int tt;
    int number_of_instructions;
    int array[100];
    scanf("%d",&tt);
    while(tt--)
    {
        int p = 0;
        scanf("%d",&number_of_instructions);
        for (int j = 0; j < number_of_instructions; j++)
        {
            
            char instruction[10];

            scanf("%s",instruction);

            if (strcmp(instruction,"LEFT") == 0)
            {
                p--;
                array[j] = -1;
            }
            else if (strcmp(instruction,"RIGHT") == 0)
            {
                p++;
                array[j] = 1;
            }
            else
            {
                int number;
                scanf("%s %d",instruction,&number);
                p += array[number-1];
                array[j] = array[number-1];
            }
            
        }
        printf("%d\n",p);
        
    }

    return 0;
}