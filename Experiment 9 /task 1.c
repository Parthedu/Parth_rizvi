#include <stdio.h>
#include <stdio.h>
// Defining the structure to hold student data
struct student_record {
   char name[50];
   int roll_number;
   float total_marks;
};

// Funtion to read student data
void input_studentdata(struct student_record students[], int n){
    for (int i=0; i < n; i++) { 
        printf("Enter details for student %d: \n", i + 1);
    
        printf("Name: ");
        getchar(); // To consume the newline left by the previous input
        gets(students[i].name);
        
        printf("Roll Number: ");
        scanf("%d", &students[i].roll_number);
        
        printf("Total Marks: ");
        scanf("%d", &students[i]total_marks);
    {
        
  } 
  //Function to find the return the index of the student with the highest marks
  int find topper_index = 0;
  for(int i= 1; < n; i++) { 
        if (students[i].total_marks > student[topper_index]. total_marks) { 
                topper_index = i;
        }
    }
    return topper_index;
}
      
