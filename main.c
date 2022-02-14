#include "libftprintf/includes/ft_printf.h"
//#include "libftprintf/libft/includes/libft.h"
//#include "clone/includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main ()
{
	//char *str = "HELLO WOLRD";
	int ret;
	//double n = 1.5 / .00345;
	//unsigned int n = UINT_MAX;
	
	ret = ft_printf("%+- i", 23);
	printf("\n");
	printf("ret1: %d\n", ret);

	//ret = printf("|%08c|", 42) - 2;
	//printf("\n");
	//printf("ret2: %d\n", ret);

	//ft_putnbr_base(12345678, 34, 1);
	//printf("\n");


	return (0);
}

//%[$][flags][width][.precision][length modifier]conversion

//make  -C libftprintf && gcc main.c -L libftprintf -lftprintf
//printf("%.1f %.1f\n", 0.15, 0.85);
//printf("%.1Lf %.1Lf\n", 0.15l, 0.85l);