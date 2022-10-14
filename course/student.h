 /**
 * @file student.h
 * @author Khushii Saini
 * @date 8 April 2022
 * @brief Student library for managing student records, including student type definition 
 *        and student functions.
 *
 */

/**
* Student type stores a _student with fields first_name,last_name, id, grade, num_grades.
*
*/
typedef struct _student 
{ 
  char first_name[50];/**< students's first name */
  char last_name[50];/**< students's last name */
  char id[11];/**< students's id */
  double *grades; /**< students's grades */
  int num_grades; /**< students's grades in integer format */
} Student;

void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
