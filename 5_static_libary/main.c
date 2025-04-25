/*
    ------------------------------------------
    FILE NAMES:
    1. main.c      - This file (contains main function)
    2. add.c       - Contains definition of add() function
    3. sub.c       - Contains definition of sub() function
    4. header.h    - Contains declarations of add() and sub()
    5. Makefile    - Automates compilation and linking
    ------------------------------------------

    ------------------------------------------
    EXECUTION STEPS:
    1. Compile everything using: make
    2. Run the program using:    ./main
    ------------------------------------------
*/ 

#include <stdio.h>
#include "header.h"

int main()
{
    int a, b;

    printf("Enter the two number: ");
    scanf("%d %d", &a, &b);

    printf("Addition is %d\n", add(a, b));
    printf("Subtraction is %d\n", sub(a, b));

    return 0;
}
