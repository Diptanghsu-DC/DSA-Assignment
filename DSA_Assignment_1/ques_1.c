#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *adder(char *num1, char *num2, char *ans)
{
    int total;
    int sum = 0;
    int carry = 0;
    int num1_length = strlen(num1);
    int num2_length = strlen(num2);
    int i = num1_length - 1;
    int k = 1024;

    for (int j = num2_length - 1; j >= 0; i--, j--, k--)
    {
        total = num1[i] + num2[j] + carry;
        sum = (total % 10);
        carry = total / 10;
        ans[k] = sum;
    }
    i--;
    k--;
    for (; i >= 0; i--, k--)
    {
        total = num1[i] + carry;
        sum = (total % 10);
        carry = total / 10;
        ans[k] = sum;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    char num1[1025];
    char num2[1025];
    char ans[1025];

    scanf("%s", &num1);
    scanf("%s", &num2);


    printf("%s \n", adder(num1, num2, ans));

    return 0;
}