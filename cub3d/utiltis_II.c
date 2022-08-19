#include "cub3d.h"

double ft_to_radien(int degree)
{
    return (M_PI * degree/180);
}

void ft_error(char *error)
{
    write(2,"Error :",7);
    write(2, error, ft_strlen(error));
    write(2,"\n",1);
    exit(1);
}