/**
 * @file course.c
 * @author Khushii Saini
 * @date 8 April 2022
 * @brief Course library for managing course, including definitions of course
 *        function.
 *
 */
#include "course.h"
#include <stdlib.h>
#include <stdio.h>
 
/** 
 * Used to insert the value in course array of total number of students enrolled in the course
 * calloc and realloc are used to create a dynamically allocate array to increase the size by one
 * 
 * @param course a pointer to course in the course array.
 * @param student a pointer to student in the student array.
 * @return nothing
 */

void enroll_student(Course *course, Student *student)
{
  course->total_students++;
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }
  course->students[course->total_students - 1] = *student;
}

/** 
 * Prints all courses in the library in a list incl. Name, Code, Total students.
 * 
 * @param course a pointer to course in the course array.
 * @return nothing
 */

void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/** 
 * Used to find a student with the highest average.
 * It uses a for loop to iterate over, at first it takes the student at index 0 with highes average
 * if the next student has the larger average than the current stored value it replaces.
 * 
 * @param course a pointer to course in the course array.
 * @return pointer to student array.
 */

Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL;
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  return student;
}

/** 
 * Used to find students who passed the course.
 * It uses a for loop to iterate over, and if the average is more than 50
 * it addes that student to the array
 * 
 * @param course a pointer to course in the course array.
 * @param total_passing integer.
 * @return pointer to student array who passed the course.
 */

Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  
  passing = calloc(count, sizeof(Student));

  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}