#include "stdio.h"
#include "math.h"
#include "stdlib.h"

double f (int n, double q, double r, double b, double c, double d) {
	if (n == 0)
		return c;
	if (n == 1)
		return d;
	
	return q * f(n - 1, q, r, b, c, d) + r * f(n - 2, q, r, b, c, d) + b;
}

int solution () {
	int n, scheck;
	double q, r, b, c, d;
	
	scheck = scanf("%lf%lf%lf%lf%lf", &q, &r, &b, &c, &d);
	if (scheck != 5)
		return 1;
	
	scheck = scanf("%d", &n);
	if (scheck != 1)
		return 1;
	if (n < 2)
		return 1;
	
	printf("%f\n", f(n, q, r, b, c, d));
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
