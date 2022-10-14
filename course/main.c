/**
 * @mainpage Student and Course function demonstration
 *  
 * The book function demonstration shows how multiple functions in the book 
 * library work, including:
 * - enrolling students in course MATH101
 * - generating 8 random students in course MATH101
 * - printing library of course
 * - finding the student with highest average
 * - printing the array fo student with highest average
 * - finding the students who passed the course MATH101
 * - printing the names of students who passed the course.
 * 
 * @file main.c
 * @author Khushii Saini
 * @date 8 April 2022
 * @brief Runs demonstration code for student and course library methods.
 * 
 */ 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

/**
 * Creates a library of students and courses represented as an array,  
 * and tests library methods for printing, generating and finding. 
 * 
 */
int main()
{
  srand((unsigned) time(NULL));

  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  
  print_course(MATH101);

  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}