// SELF DESCRIBING
// COURSE CODE: CSC 235
// NAME: OLUWADAMILARE IYANUOLUWA SAMUEL
// MATRIC NUMBER: 222505

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

// Checks how many times a digit appears in the given number
int digit_checker(int num, int digit)
{
    int count = 0;
    while (num > 0)
    {
        if (num % 10 == digit)
        {
            count++;
        }
        num /= 10;
    }
    return count;
}


int main()
{
    // File opening and reading   
    FILE * fpointer = fopen("self.in.txt", "r");
    FILE * buffer = fopen ("standard_output.txt", "w+");
    int num, new, counter;
    int verify_self_describing = 0;

    // Getting the number of trials from the file
    fscanf(fpointer, "%d", &num);

    while (counter != num)
    {
        fscanf(fpointer, "%d", &new);
        char str_num[100];
        
        // Converting the integer to a string so as to check string length
        sprintf(str_num ,"%d" , new);
        // Finding the length of the string 
        int length = strlen(str_num);
        
        for (int i = 0; i < length; i++)
        {
            // Self describing check
            if (digit_checker(new, i) == str_num[i]- '0')
            {
                verify_self_describing++;
                if (verify_self_describing == length)
                {
                    fprintf(buffer, "It is Self-describing\n");
                    printf("Self describing\n");
                    verify_self_describing = 0;
                    break;
                }      
            }
            else
            {
                fprintf(buffer, "It is not Self-describing\n");
                printf("Not Self Describing\n");
                break;
            }              
       }
    counter++;
    }
   
}