#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	int x = 21;
	//int y = 51;
	//int ret;
	//int ret2;

	ft_printf("i started and %# m+x i did it!\n", x);
	//printf("REALi started and%% i did it!\n", x);
	//ft_printf("ret: %# 0.20d\n", ret);

	//ret2 = printf("%d\n", 12345);
	//printf("%d\n", ret2);


	return (0);
}

//%[$][flags][width][.precision][length modifier]conversion