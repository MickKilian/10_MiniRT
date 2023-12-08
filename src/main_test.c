#include <stdio.h>
#include <math.h>

int	main(void)
{
	double	a = 0.01;
	int		b = a * 255.0;
	double	inf = INFINITY;

	if (a < inf)
		printf("a is smaller than infinity\n");
	else
		printf("a is larger than infinity\n");
	printf("a = %f\n", a);
	printf("b = %d\n", b);
	return (0);
}
