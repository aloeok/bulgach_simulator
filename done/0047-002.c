#include "stdio.h"

int solution () {
	int scheck;
	double x, y, z;
	
	scheck = scanf("%lf%lf%lf", &x, &y, &z);
	
	if (scheck != 3)
		return 1;
	if (x <= 0 || y <= 0 || z <= 0)
		return 1;
	
	if ( (x + y <= z) || (y + z <= x) || (z + x <= y) )
		return 1;
	
	if ( (x*x + y*y > z*z) && (y*y + z*z > x*x) && (z*z + x*x > y*y) )
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
