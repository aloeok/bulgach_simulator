#include "stdio.h"
#include "math.h"

int solution () {
	int scheck;
	double a, b, c;
	
	scheck = scanf("%lf%lf%lf", &a, &b, &c);
	
	if (scheck != 3)
		return 1;
	
	if (fabs(a - b) < 0.0001 || fabs(b - c) < 0.0001 || fabs(c - a) < 0.0001)
		return 1;
	
	if (a + b + c < 1) {
		if (a < b && a < c)
			a = (b + c) / 2;
		else if (b < c && b < a)
			b = (c + a) / 2;
		else
			c = (a + b) / 2;
	} else {
		if (a < b)
			a = (b + c) / 2;
		else
			b = (a + c) / 2;
	}
	
	printf("%lf\n%lf\n%lf\n", a, b, c);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
