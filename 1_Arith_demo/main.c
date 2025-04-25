#include <stdio.h>

int main(int argc, char const *argv[])
{
    int result = 0;
    printf("Arith demo\n");
    
    result = add(10, 20);
    printf("Addition Result: %d\n", result);
    return 0;
}