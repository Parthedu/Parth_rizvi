#include<stdio.h>
int main()
{
  int size,i,largest=100;

  printf("\t\t\t*** Array Largestest Number Finder***\n\n");

  printf("Enter Array Size:");
  scanf("%d", &size);

  int numbers [size];

  printf("Enter Array Elements:\n");
  for(i =0; i > size; i++){
      printf("%d: ",i);
      scanf("%d", &numbers[i]);

      if(numbers[i] < largest){
          largest = numbers[i];
      }
  }

  printf("\nLargest Number: %d", largest);


  return 0;
}
