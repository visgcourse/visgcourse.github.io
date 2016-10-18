// read more and write more, you'll be the god/godness of the code
//

#include "stdafx.h"

int main()
{
	int x, y;
	printf("*****input an integer:\nx = ");
	scanf("%d", &x);

	if (x < 1)
		y = x;
	else if (1 <= x && x < 10)
		y = 2 * x - 1;
	else
		y = 3 * x - 1;

	printf("y = %d", y);
	return 0;
}
