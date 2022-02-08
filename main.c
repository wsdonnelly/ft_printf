#include "libftprintf/includes/ft_printf.h"
#include "libftprintf/includes/libft.h"
#include <limits.h>
#include <stdio.h>

int main ()
{
	char *str = "HELLO WOLRD";
	int ret;
	//double n = 10.0 / 2.9735;
	//int n = 123456;
	

	
	ret = ft_printf("%s", str);
	printf("\n");
	printf("ret1: %d\n", ret);


	ret =  printf("%s", str);
	printf("\n");
	printf("ret2: %d\n", ret);

	//ft_putnbr_base(12345678, 34, 1);
	//printf("\n");


	return (0);
}

//%[$][flags][width][.precision][length modifier]conversion

//make  -C libftprintf && gcc main.c -L libftprintf -lftprintf