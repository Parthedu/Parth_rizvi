 
   Expt 6 - Task 1
    Module 2 : Storage Classes
    Aim: WAP to define a counter function to print how
        many times the function is called. use storage classes.

#include<stdio.h>

void counter(){
    static int count = 0;
    count++;

    printf("Counter Function Called : %d\n", count);
}


int main(){

    printf("\t\t\t *** Storage Class *** \n\n");

    counter();
    counter();
    counter();
    counter();

    return 0;
}
