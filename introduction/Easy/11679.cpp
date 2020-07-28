#include <bits/stdc++.h>

using namespace std;

int main(){
    int banks_money[20],number_of_banks,number_of_debuntures;

    while (1){
        scanf("%d %d",&number_of_banks,&number_of_debuntures);
        if (number_of_banks == 0 && number_of_debuntures == 0){
            break;
        }
        
        int i;
        for (i = 0; i < number_of_banks; i++){
            scanf("%d",&banks_money[i]);
        }

        int debtor,creditor,amount_of_money;

        for (i = 0; i < number_of_debuntures; i++){
            scanf("%d %d %d",&debtor,&creditor,&amount_of_money);
            banks_money[creditor-1] +=  amount_of_money;
            banks_money[debtor-1] -= amount_of_money;
        }
        
        int flag=1;
        for (i = 0; i < number_of_banks; i++){
            if (banks_money[i] <0){
                printf("N\n");
                flag =0;
                break;
            }
        }
        if (flag){
            printf("S\n");
        }
        
    }
    

    return 0;
}