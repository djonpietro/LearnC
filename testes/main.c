#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str1[20], str2[20];

    printf("Enter the first string: ");
    gets(str1);

    printf("Enter the second string: ");
    gets(str2);

    printf("%s\n", str1);
    printf("%s", str2);

    return 0;
}