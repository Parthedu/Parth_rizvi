 Expt 5 - Task 1
    Module 2 : Iterative Function & Recursive Function
    Aim: WAP to find the factorial of a number using iterative function.

#include<stdio.h>

int factorialIterative(int num){
    int prod = 1;
    for(int i=1; i <= num; i++){
        prod *= i;
    }

    return prod;
}


int main(){
    int num;

    printf("\t\t\t *** Iterative Factorial Function *** \n\n");

    printf("Enter Number:");
    scanf("%d", &num);

    printf("Factorial of %d is %d", num, factorialIterative(num));

    return 0;
}
