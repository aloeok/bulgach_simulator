#include "stdio.h"
#include "math.h"

double half_sum (double a, double b) {
	return (a + b) / 2;
}

double double_prod (double a, double b) {
	return a * b * 2;
}

int solution () {
	int scheck;
	double a, b;
	
	scheck = scanf("%lf%lf", &a, &b);
	
	if (scheck != 2)
		return 1;
	
	if (fabs(a - b) < 0.0001)
		return 1;
	
	if (a < b)
		printf("%lf\n%lf\n", half_sum(a, b), double_prod(a, b));
	else
		printf("%lf\n%lf\n", double_prod(a, b), half_sum(a, b));
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
