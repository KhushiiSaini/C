lettercounter.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    int i = 0;
    char input;
    int occ[26] = {0};
    int j,k,l;
    float percentage;
    const char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int max,min;
    char max_alpha,min_alpha;
    
    // The following part of the code is reponsible for taking the user input.
    // As it reads only till the first white space so we are creating a buffer char array.
    
    printf("Enter the text for analysis : ");
    
    while (1)
    {
        input = getchar();
        if (input  == '\n')
        {
          buffer[i] = '\0';
          break;
        }
        else buffer[i] = input;
        i++;
    }
   
    printf ("\n\nLetter Analysis Complete ! \n\n");
    
    // The following part is responsible for counting the occurences of each letter.
    // As characters in C are integer therefore I am using the ASCII method.

    size_t len = strlen(buffer);
    
    for (j = 0; j < len; j++) // The loop runs till the length of the string.
    {
    // It takes one character at a time and then if the char is not alphabet it skips
    // the char and continue with the next char
    
       char c = buffer[j]; 
       if (!isalpha(c)) continue; 
       
    // The line first converts the char into lower case and then into it's ASCII int value.   
    
      occ[(int)(tolower(c) - 'a')]++;
    }
    
    // The following code prints the table.
    
    printf("%-10s %-20s %-20s \n", "Letter", "Occurrences", "Percentage");
    printf("************************************************ \n");
    
    for (j = 0; j < 26; j++) {
        float percentage = (((float)occ[j]/(float)len) * 100);
        printf("%-10c %-20d %-20.2f \n", alphabet[j], occ[j],percentage);
    }
    
    // The following part is responsible for getting the most frequently occuring alphabet.
    // It stores the first element of the array for the comparison.
    
    max = occ[0];
    max_alpha = alphabet[0];
    
    for (l = 1; l < 26; l++) // Runs till the length of array.
    
    {   // If the element of "occ" array is greater than the element stored in max variable
       // then it replaces the value stored in max with the element and then get
      // the alphabet present in "alphabet array" at that particular index.
      
        if (max < occ[l]) 
        {
            max = occ[l];
            max_alpha = alphabet[l];
            
        }
        
        // If not then it continues to check the entire "occ" array.
        
        else 
        {
            continue;
       }
    }
    
    // The following part is responsible for getting the least frequently occuring alphabet.
    // It stores the first element of the array for the comparison.
    
    min = occ[0];
    min_alpha = alphabet[0];
    
    for (k = 1; k < 26; k++) // Runs till the length of array.
    
    {   
        // If the element of "occ" is equal to zero then it takes the alphabet
        // present at that particular index and breaks out of the loop.
        if (occ[k] == 0)
        {
            min_alpha = alphabet[k];
            break;
        }
        
        // If the element of "occ" array is smaller than the element stored in min variable
        // then it replaces the value stored in min with the element and then get
        // the alphabet present in "alphabet array" at that particular index.
      
        else if (occ[k] < min)
        {
            min = occ[k];
            min_alpha = alphabet[k];
            
        }
        
        // If not then it continues to check the entire "occ" array.
          
        else 
        {
            continue;
        }
    }
    
    printf ("\nThe most frequently occuring character is %c \n",max_alpha);
    printf ("The least frequently occuring character is %c \n",min_alpha);
   
    return 0;
    
    
}
