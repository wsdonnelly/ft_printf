#include <stdio.h>
#include <stdlib.h>
//#include "libft/includes/libft.h"
#include <limits.h>


unsigned int num_digits_basetest(unsigned long long n, unsigned long long base, unsigned int sum)
{
	if (n == 0)
		return (1);
	if (n / base)
	sum = num_digits_basetest(n / base, base, sum);
	return (++sum);
}

int main ()
{

	printf("%u\n", 1234567890);
	printf("numdig: %u\n", num_digits_basetest(1234567890, 10, 0));


	return (0);
}

//%[$][flags][width][.precision][length modifier]conversion
//gcc tester.c -L libft -lft