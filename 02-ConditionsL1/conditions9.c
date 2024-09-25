#include <stdio.h>
#include <math.h>

/**
* main - entrée du program
* 
* Description: donner une mention a la note
*
* Return: Toujours 0 (succès)
*/

int main()
{
    char str[50];
    //int month_number;
    char month_in_char;

    //char months[] = ["janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout", "septembre", "novembre", "decembre"]
    printf("entrez une date ?\n");
    scanf("%s", &str);
    printf("str = %s", str);
    month_in_char = strtok(str,'/');
    printf(" month_in char%s\n", month_in_char);
    return (0);

}