#include <stdio.h>
#include <stdlib.h>

// Global vaiable
int a; // uninitalised
int b = 10; // initalised

int main(int argc, char const* argv[]) // memory is allocated during run time 
{
    int result = 0;

    int *p = NULL;
    p = (int *)malloc(sizeof(int));

    result = add(10, 20);

    printf("Addition result: %d\n", result);

    return 0;


}