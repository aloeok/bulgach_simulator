#include "stdio.h"
#include "math.h"

double sq (double a) {
	return a * a;
}

double cb (double a) {
	return a * a * a;
}

int solve_qeq (double a, double b, double c, double* x1, double* x2) {
	int res = 1;
	double d = b * b - 4 * a * c;
	
	if (d < 0)
		return -1;
	
	if (fabs(d) < 0.0001)
		res = 0;
	
	*x1 = ( -b + sqrt(d) ) / (2 * a);
	*x2 = ( -b - sqrt(d) ) / (2 * a);
	
	return res;
}

int solution () {
	int scheck;
	double c, d, x1, x2, a1, a2, a3, a;
	
	scheck = scanf("%lf%lf", &c, &d);
	if (scheck != 2)
		return 1;
	
	solve_qeq(1, -3, -fabs(c * d), &x1, &x2);
	
	a1 = cb(sin(fabs( c*cb(x1) + d*sq(x2) - c*d )));
	a2 = sq(c*cb(x1) + d*sq(x2) - x1) + 3.14;
	a3 = tan(c*cb(x1) + d*sq(x2) - x1);
	
	a = fabs(a1 / sqrt(a2)) + a3;
	
	printf("%f\n", a);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
