#include <stdio.h>


int main() {

    long long num;
    scanf("%lld", &num);

    double result = (double) num / (double) 4;

    printf("%.2lf", result);

    return 0;
}