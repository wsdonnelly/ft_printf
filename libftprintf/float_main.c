#include <stdio.h>
#include <math.h>

int	ft_num_digits_s(long long n)
{
	int	num_digits;

	num_digits = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		num_digits++;
		n /= 10;
	}
	return (num_digits);
}

void print_float(double n, int precision) //123.456
{
	int num_digi = 0;
	int first_digi_exp = 0;
	double digit;
	int max_digi = 100;
	int pow;
	int i;

	
	if (n < 0)
	{
		printf("-");
		n = -n;
	}
	//first_digi_exp = (int)floor(log10(n));
	first_digi_exp = ft_num_digits_s((int)n) - 1;
	printf("int ver: %d\n", (int)n);
	pow = 1;
	i = 0;
	//n = n / pow(10, first_digi_exp); //scaled to 1.23456
	while (i++ < first_digi_exp)
		pow *= 10;
	n /= pow;
	printf("scaled: %f\n", n);
	while (n > 0.0 && num_digi < max_digi)
	{
		//digit = floor(n);
		digit = (int)n;
		//printf("\ndigit floor %f\n", digit);
		//buf[num_digi] = '0' + char(digit);
		printf("%c", '0' + (char)digit);
		num_digi++;
		
		n -= digit; //subtract previous first digit
		n *= 10.0;
		if (!first_digi_exp--)
		{
			printf(".");
			num_digi = 0;
			max_digi = precision;
		}
	}
}



int main ()
{
	double n = 100.067 / 3.7;

	print_float(n, 16);
	printf("\n");
	printf("%.16f\n", n);

}