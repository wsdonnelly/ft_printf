#include <stdio.h>
#include <stdlib.h>
#include "libft/includes/libft.h"
#include <limits.h>



int main ()
{

	int ret;
	//int ret2;
	//unsigned long long  n = 12345;
	//unsigned int x = 12345678;
	//char c = '$';
	//unsigned long long  n = ULLONG_MAX;
	ret =printf("%-10.30d\n", -1234);
	printf("ret: %d\n", ret);

	//ft_putnbr_base(ULLONG_MAX, 16, 0);
	

	
	//printf("\n");
	//printf("ret2: %d\n", ret2);
	return (0);
}

//%[$][flags][width][.precision][length modifier]conversion
//gcc tester.c -L libft -lft