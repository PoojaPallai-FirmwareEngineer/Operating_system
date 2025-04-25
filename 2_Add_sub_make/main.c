#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;

    printf("Enter the two numbers: ");
    scanf("%d %d", &a, &b);
    
    printf("Addition Result: %d\n", add(a, b));
    printf("Subtraction Result: %d\n", sub(a, b));

    return 0;
}