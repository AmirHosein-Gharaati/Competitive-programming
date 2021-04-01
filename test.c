#include <stdio.h>

int conversion_to_integer(int input)
{
    int digit, output;
    int negative = 0;
    output = 0;

    while ((input = getchar()) != EOF)
    {
        if (input == '-')
            negative = 1;
        else
        {
            digit = input - '0';
            output = output*10 + digit;
        }
    }

    if (negative == 1)
        output = -1*output;

    return output;
}


int main()
{
    int input;
    printf("%d", conversion_to_integer(input));
}