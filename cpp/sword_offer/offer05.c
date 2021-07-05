#include <stdio.h>
#include <stdlib.h>

void ReplaceBlank(char string[], int length)
{
    if(string == NULL || length == 0)
        return;

    char *pEnd = string;
    int new_cnts = 0;
    while(*pEnd != 0) {
        new_cnts++;
        pEnd++;
        if(*pEnd == ' ')
            new_cnts+=2;
    }

    if(length < new_cnts + 1)
        return;

    char *pNewEnd = string + new_cnts;
    while(pEnd >= string)
    {
        if(*pEnd == ' ') {
            *pNewEnd-- = '0';
            *pNewEnd-- = '2';
            *pNewEnd-- = '%';
        }
        else {
            *pNewEnd-- = *pEnd;
        }
        pEnd--;
    }
}