# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>


int check_digit(int num, int digit)
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
    
    FILE * fpointer = fopen("self.in.txt", "r");
    FILE * buffer = fopen ("standard_output.txt", "w+");
    int num, new, counter;
    int valid = 0;
    fscanf(fpointer, "%d", &num);

    while (counter != num)
    {
        fscanf(fpointer, "%d", &new);
        char str_num[100];
        
        /* Converting the integer to a string. */
        sprintf(str_num ,"%d" , new);
        int length = strlen(str_num);
        
        for (int i = 0; i < length; i++)
        {
            /* This is checking if the number of times a digit appears in the number is equal to the
            digit itself. */
            if (check_digit(new, i) == str_num[i]- '0')
            {
                valid++;
                if (valid == length)
                {
                    fprintf(buffer, "It is Self-describing\n");
                    printf("Self describing\n");
                    valid = 0;
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