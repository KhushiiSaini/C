/**
 * @file course.h
 * @author Khushii Saini
 * @date 8 April 2022
 * @brief course library for managing courses, including course type definition 
 *        and course functions.
 *
 */

#include "student.h"
#include <stdbool.h>
 
/**
* Course type stores a _course with fields name, code, students, total_students.
*
*/
typedef struct _course 
{
  char name[100];/**< the course's name */
  char code[10];/**< the course's code */
  Student *students;/**< the array of student */
  int total_students;/**< total number of students */
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


