#include "includes/libft.h"

int main(int ac, char **av)
{
    int fd;
    char *line;
    int ret;
    
    fd = 0;
    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        while ((ret = get_next_line(fd, &line)) > 0)
        {
            ft_puts(line);
        }
        close(fd);
    }
    else if (ac == 1)
    {
        while ((ret = get_next_line(fd, &line)) > 0)
        {
            ft_puts(line);
            pnbl(line);
        }
        
    }
    free(line);
    return (0);
}