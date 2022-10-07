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
	double a, b, c;
	
	scheck = scanf("%lf%lf%lf", &a, &b, &c);
	
	if (scheck != 3)
		return 1;
	
	if (a >= 0)
		a = a * a;
	if (b >= 0)
		b = b * b;
	if (c >= 0)
		c = c * c;
	
	printf("%lf\n%lf\n%lf\n", a, b, c);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
