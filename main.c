#include "libftprintf/includes/ft_printf.h"

#include <limits.h>
#include <stdio.h>


int main ()
{
	//int x = 21;
	//int y = 51;
	//char *str = "HELLO WOLRD";
	int ret;
	double n = 105067845.056 / 33987.78;
	//unsigned long long  n = 12345;
	//ret = ft_printf("here's a num: %#llX and here be %c\n", n, '@');

	
	ret = ft_printf("%.10f", n);
	printf("\n");
	printf("ret1: %d\n", ret);


	ret =  printf("%.10f", n);
	printf("\n");
	printf("ret2: %d\n", ret);

	//printf("REALi started and%% i did it!\n", x);
	//ft_printf("ret: %# 0.20d\n", ret);

	//ret2 = printf("%d\n", 12345);


	return (0);
}

//%[$][flags][width][.precision][length modifier]conversion
//make  -C libftprintf && gcc main.c -L libftprintf -lftprintf