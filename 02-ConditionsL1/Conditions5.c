#include <stdio.h>
#include <math.h>

/**
* main - entrée du program
* 
* Description: convertir une année donnée en mois, jour, minutes, secondes
*
* Return: Toujours 0 (succès)
*/

int main()
{
    int months = 12, days, hours, minutes, seconds, year;
    
    printf("Entrez une année par exemple 1930\n");
    scanf("%d", &year);
    //In this calendar, a common year is 365 days (8760 hours, 525600 minutes or 31536000 seconds), 
    //and a leap year is 366 days (8784 hours, 527040 minutes or 31622400 seconds).
    if (year % 4 == 0 && year % 100 != 0)
    {
        days = 366;
        hours = 8784;
        minutes = 527040;
        seconds = 31622400;
        printf("months:%d\ndays:%d\nhours:%d\nminutes:%d\nseconds:%d\n", months, days, hours, minutes, seconds);
        return (0);
    }
    days = 365;
    hours = 8760;
    minutes = 525600;
    seconds = 31536000;
    printf("months:%d\ndays:%d\nhours:%d\nminutes:%d\nseconds:%d\n", months, days, hours, minutes, seconds);
    return (0);
}