#include "so_long.h"

int cheak_ber(char *file)
{
    int len;

    len = ft_strlen(file);
    if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
        return (0);
    return 1;
}

void	free_2d(char **str)
{
	int	i;

	i = 0;
    while (str[i])
	    free(str[i++]);
	free(str);
}

int count_lines(int fd)
{
    int count;
    char *line;

    count = 0;
    line = get_next_line(fd);
    while(line)
    {
        count++;
        free(line);
        line = get_next_line(fd);
    }
    return count;
}

int main(int ac , char **av)
{
    char *line;
    int lines_num = 0;
    int i = 0;
    t_long s;
    ft_bzero(&s, sizeof(s));
    if (ac != 2)
        return (write(2, "Error\n", 7), 0);
    if (!cheak_ber(av[1]))
        return (write(2, "Error : not .ber file\n", 23), 0);
    int fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return (write(2, "Error\n", 7), 0);
    lines_num = count_lines(fd);
    close(fd);
    s.array = malloc(sizeof(char *) * (lines_num + 1));
    if (!s.array)
        return (write(2, "Error: allocation failed\n", 26), close(fd), 1);
    fd = open(av[1], O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        s.array[i] = ft_strtrim(line, "\n");
        i++;
        // printf("%s", line); 
        free(line);
    }
    s.array[i] = NULL;
    if (!same_rows(&s))
    {
        free_2d(s.array);
        return (write(2, "Error : not reqtiangle or invalid char\n ", 41), 0);
    }
    free_2d(s.array);
    close(fd);
}