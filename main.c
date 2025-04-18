#include "so_long.h"
 
 int cheak_ber(char *file)
 {
     int len;
 
     len = ft_strlen(file);
     if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
         return (0);
     return 1;
}
 
 int main(int ac , char **av)
 {
    //  t_game s;

     if (!check(ac, av))
         return (0);
 }