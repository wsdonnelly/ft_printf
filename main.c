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
	

	
<<<<<<< HEAD
	ret = ft_printf("%20p", &str);
=======
	ret = ft_printf("%5.o%5.0o", 0, 0);
>>>>>>> full
	printf("\n");
	printf("ret1: %d\n", ret);


<<<<<<< HEAD
	ret =  printf("%20p", &str);
=======
	ret =  printf("%5.o%5.0o", 0, 0);
>>>>>>> full
	printf("\n");
	printf("ret2: %d\n", ret);

	//ft_putnbr_base(12345678, 34, 1);
	//printf("\n");


	return (0);
}

//%[$][flags][width][.precision][length modifier]conversion

//make  -C libftprintf && gcc main.c -L libftprintf -lftprintf