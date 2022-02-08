#include "libftprintf/includes/ft_printf.h"
#include "libftprintf/includes/libft.h"
#include <limits.h>
#include <stdio.h>

void	ft_putnbr_base(unsigned long long n, int base, int flag)
{

	if (n == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (n / base)
		ft_putnbr_base(n / base, base, flag);
	if (n % base > 9)
	{
		if (flag)
			ft_putchar((n % base) - 10 + 'A');
		else
			ft_putchar((n % base) - 10 + 'a');
		return ;
	}
	else
	{
		ft_putchar(n % base + '0');
		return ;
	}
	return ;
}

int main ()
{
	//int x = 21;
	//int y = 51;
	//char *str = "HELLO WOLRD";
	int ret;
	double n = 10.0 / 2.9735;
	 //int n = 123456;
	//ret = ft_printf("here's a num: %#llX and here be %c\n", n, '@');

	
	ret = ft_printf("%f", n);
	printf("\n");
	printf("ret1: %d\n", ret);


	ret =  printf("%        f", n);
	printf("\n");
	printf("ret2: %d\n", ret);

	ft_putnbr_base(12345678, 34, 1);
	printf("\n");
	//printf("REALi started and%% i did it!\n", x);
	//ft_printf("ret: %# 0.20d\n", ret);

	//ret2 = printf("%d\n", 12345);


	return (0);
}

//%[$][flags][width][.precision][length modifier]conversion

//make  -C libftprintf && gcc main.c -L libftprintf -lftprintf