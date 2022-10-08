#include "stdio.h"

double cnt2 (double a, double d, double n) {
	return (2 * a + (n - 1) * d) * n / 2;
}

int solution () {
	double a, d;
	int n, scheck;
	
	scheck = scanf("%lf%lf", &a, &d);
	
	if (scheck != 2)
		return 1;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 1)
		return 1;
	
	printf("%f\n", cnt2(a, d, n));
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
