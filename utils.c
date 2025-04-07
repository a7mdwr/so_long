#include "so_long.h"

static int char_cheak(char c)
{
    if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
        return 1;
    else
        return 0;
}


static int helper_function(char **str)
{
    int j;
    int i;
    int first;

    first = 1;
    j = 0;
    while (str[j])  
    {
        i = 0;
        if (str[j][0] != '1')
            return 0;
        if (first)
        {
            while(str[j][i])
            {
                if(str[j][i] != '1'){
                    
                printf("{%c}\n", str[j][i]);
            return 0;
        }
                i++;
            }
            first = 0;
        }
        printf("here");
        i = ft_strlen(str[j]) - 1;
        if (str[j][i] != '1')
            return 0;
        i = 0;
        if(!str[j + 1])
        {
            while(str[j][i])
            {
                if(str[j][i] != '1')
                    return 0;
                i++;
            }
        }
        j++;
    }
    return 1;
}

int same_rows(t_long *s)
{
    size_t i;
    int j;

    i = 0;
    j = 1;
    while (s->array[j])
    {
        i = 0;
        while(s->array[j][i])
        {
            if (!char_cheak(s->array[j][i]))
                return (0);
            i++;
        }
        j++;
    }
    j = 0;
    while (s->array[j] && s->array[j + 1])
    {
        i = 0;
        i = ft_strlen(s->array[j]);
        if (i != ft_strlen(s->array[j + 1]))
            return (0);
        j++;
    }
    if(!helper_function(s->array))
        return 0;
    return 1;
}