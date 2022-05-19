

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Defining ‘new city housing price type’
typedef struct new_city_housing_price {
   char city_name[1024];
   int avg_price;
} cityprice;


void input_library(cityprice library[],char user_input);
void print_library(cityprice library[]);
void sort_by_avg_price(cityprice library[]);

//Defining some global variables to keep the track of length,index and buffer size resp.
int length = 0;
int j = 0; 
int dynamic_buffer = 2;

int main(void)
 {
     int i = 0;
     char user_input;
     
     cityprice *library = malloc(sizeof(char) * dynamic_buffer); //Using to allocate a block of memory
     
     //Asking for user input 
     printf("Enter the name of the city:");
     scanf("%s",library[j].city_name);
     printf("Enter the average house price:");
     scanf("%d",&library[j].avg_price);
     printf("Enter another city? (y/n)");
     scanf("%s",&user_input);
     if (user_input == 'y')
     {
         input_library (library ,'n' ); // If they wish to add more then calling the input function 
     }
    
    printf("\nList of city and prices: \n");
    print_library(library);

    sort_by_avg_price(library);
    printf("\n\nSorted: \n");
    print_library(library);
 
    printf("\n\nThe city with the highest house price : %s", library[length].city_name);
    
    free(library); //freeing the dynamically allocated array
    
    return 0;
  
}

// Below is the function for taking the user input
void input_library(cityprice library[],char user_input)
{
    int i= 0;
    
    //Incrementing length and index
    length++;
    j++;
    
    if(i+1 == dynamic_buffer) //Doing +1 because of escape character
    {
        dynamic_buffer = dynamic_buffer + 1; //Increasing the block of memory by 1
        cityprice* library = realloc(library, sizeof(char) * dynamic_buffer); //Resizing the block of memory
    }
    
    //Asking for the user input
    printf("Enter the name of the city:");
    scanf("%s",library[j].city_name);
    printf("Enter the average house price:");
    scanf("%d",&library[j].avg_price);
    printf("Enter another city? (y/n)");
    scanf("%s",&user_input);
    
    i++;
    
    if (user_input == 'y') 
    {
        input_library (library,'n'); // If they wish to add more then calling the input function again and again
        
    }  
}

// Below is the function for taking the printing the user input
void print_library(cityprice library[])
{
  for (int i = 0; i < (length+1); i++)
  {
    printf("\n");
    printf("City: %s  ", library[i].city_name);
    printf("Price: %d", library[i].avg_price);
  }
  
}

// Below is the function for sorting the data using selection sort
void sort_by_avg_price(cityprice library[])
{   
    cityprice temp; //creating a temporaray cityprice

    for (int i = 0; i < (length+1); i++) //Moving by unsorted subarray
    {
        for (int j = (i+1); j < (length+1); j++) //Finding the minimum element
        {
            if(library[i].avg_price > library[j].avg_price)
            {  
                //Swapping the minimum element with the first element
                temp = library[i];
                library[i]=library[j];
                library[j]=temp; 
            }
        }
    }
}