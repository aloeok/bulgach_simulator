#include "stdio.h"

int solution () {
	int scheck;
	double a, b;
	
	scheck = scanf("%lf%lf", &a, &b);
	
	if (scheck != 2)
		return 1;
	
	if (a <= b)
		a = 0;
	
	printf("%lf\n%lf\n", a, b);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
