#include "stdio.h"

int solution () {
	int scheck;
	double a, b, c, d;
	
	scheck = scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	
	if (scheck != 4)
		return 1;
	
	if (a <= b && b <= c && c <= d) {
		a = d;
		b = d;
		c = d;
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
