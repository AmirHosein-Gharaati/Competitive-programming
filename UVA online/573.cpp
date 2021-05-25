#include <bits/stdc++.h>

using namespace std;

int main(){
    int height,climb,slide,percent,i;
    double minus,result,day;
    while (scanf("%d %d %d %d",&height,&climb,&slide,&percent) && height && climb && slide && percent){
        minus = 1.0*climb * percent / 100.0;
        result = 0;
        day = 0;
        i = 0;
        while(1){
            day = 1.0*(climb-(1.0*i*minus));
            if (day >=0)
                result += day;
            
            i++;
            if (result > height){
                printf("success on day %d\n",i);
                break;
            }
            result -= 1.0*slide;
            if (result < 0){
                printf("failure on day %d\n",i);
                break;
            }
        }
    }
    return 0;
}