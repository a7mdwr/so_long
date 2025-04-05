#include "so_long.h"

int char_cheak(char c)
{
    return('1' || '0' || 'C' || 'P' || 'E');
}

int same_rows(t_long s)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s.array[j])
    {
        while(s.array[j][i])
        {
            if (!char_cheak(s.array[j][i]))
                return (write(2, "Error\n"
        }
    }
    
}