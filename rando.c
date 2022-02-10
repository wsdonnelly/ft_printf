#include <stdio.h>

int main ()
{
	int ret;

	ret = printf("%    % and %u", 13243546);
	printf("\n");
	printf("ret: %d\n", ret);
}
