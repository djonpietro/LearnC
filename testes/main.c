#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char str1[20], str2[20];

    printf("Enter the first string: ");
    fgets(str1, 20, stdin);

    printf("Enter the second string: ");
    fgets(str2, 20, stdin);

    printf("%s\n", str1);
    printf("%s", str2);

    return 0;
}