#include "libftprintf/includes/ft_printf.h"
#include "libftprintf/includes/libft.h"
#include <limits.h>
#include <stdio.h>

int main ()
{
	//char *str = "HELLO WOLRD";
	int ret;
	//double n = 1.5 / .00345;
	//unsigned int n = UINT_MAX;
	//ret = ft_printf("%CB", CYAN, "i have shrimped i have shrimmped hard");
	ret = ft_printf("%#Cx", BLUE, 42);
	//ret = ft_printf("%.f %.f %.f", 0.5, 1.5, 2.5);
	//printf("\n");
	//printf("ret1: %d\n", ret);

	//ret = printf("%7.9x %7.9x here", 42, 42);
	//printf("\n");
	//printf("ret2: %d\n", ret);

	//ft_putnbr_base(12345678, 34, 1);
	//printf("\n");


	return (0);
}

//%[$][flags][width][.precision][length modifier]conversion

//make  -C libftprintf && gcc main.c -L libftprintf -lftprintfS