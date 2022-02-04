#include <stdio.h>
#include <math.h>


void print_float(double n, int precision) //123.456
{
	int num_digi = 0;
	int first_digi_exp = 0;
	double digit;
	int max_digi = 100;

	if (n < 0)
		n = -n;
	first_digi_exp = (int)floor(log10(n));
	n = n / pow(10, first_digi_exp); //scaled to 1.23456
	printf("-");
	while (n > 0.0 && num_digi < max_digi)
	{
		digit = floor(n);
		
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
	double n = -12345.67890;

	print_float(n, 9);
	printf("\n");
	printf("doulbe = %.9f\n", n);

}