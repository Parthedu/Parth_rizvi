#include<stdio.h>
void sum(); // declaring a function

int a=10,b=20, c;

void sum() // defining function
{
c=a+b;
printf("Sum: %d", c );
}
void main()
{
sum(); // calling function
}
