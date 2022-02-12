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
	ret = ft_printf("%CB",GREEN, "abcdefghijklmnopqrstuvwxyz");
	//printf("\n");
	printf("ret1: %d\n", ret);

	//ret = printf("%.10f", 4294967.0 / 13.11);
	//printf("\n");
	//printf("ret2: %d\n", ret);

	//ft_putnbr_base(12345678, 34, 1);
	//printf("\n");


	return (0);
}

//%[$][flags][width][.precision][length modifier]conversion

//make  -C libftprintf && gcc main.c -L libftprintf -lftprintfS