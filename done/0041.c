#include "stdio.h"

int solution () {
	int scheck;
	double a, b, c;
	
	scheck = scanf("%lf%lf%lf", &a, &b, &c);
	
	if (scheck != 3)
		return 1;
	
	if (a > 1 && a < 3)
		printf("%f\n", a);
	
	if (b > 1 && b < 3)
		printf("%f\n", b);
	
	if (c > 1 && c < 3)
		printf("%f\n", c);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
