#include "stdio.h"

double max (double a, double b) {
	return (a > b) ? a : b;
}

int solution () {
	int scheck;
	double a, b, c, d;
	
	scheck = scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	
	if (scheck != 4)
		return 1;
	
	if (a <= b && b <= c && c <= d) {
		a = max(a, max(b, max(c, d)));
		b = a;
		c = a;
		d = a;
	} else if ( !(a > c && c > b && b > d) ) {
		a = a * a;
		b = b * b;
		c = c * c;
		d = d * d;
	}
	
	printf("%f\n%f\n%f\n%f\n", a, b, c, d);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
