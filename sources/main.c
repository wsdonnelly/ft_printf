#include "ft_printf.h"
#include <stdio.h>

int main ()
{
	//int x = 21;
	//int y = 51;
	int ret;
	//int ret2;

	ret = ft_printf("%#x\n", 12345678);
	printf("ret: %d\n", ret);
	//printf("REALi started and%% i did it!\n", x);
	//ft_printf("ret: %# 0.20d\n", ret);

	//ret2 = printf("%d\n", 12345);


	return (0);
}

//%[$][flags][width][.precision][length modifier]conversion