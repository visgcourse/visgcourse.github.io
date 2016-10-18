#include <stdio.h>

int main()
{
	double x;
	scanf("%lf",&x);
	double y;
	if(x<1)
		y=x;
	else if(x<10)
		y=2*x-1;
	else
		y=3*x-11;
	printf("%f",y);

	return 0;
}