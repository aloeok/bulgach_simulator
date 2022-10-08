#include "stdio.h"
#include "math.h"

double solve_eq (double v1, double v2, double x) {
	return x / (v1 + v2);
}

double solve_ac (double v1, double v2, double a1, double a2, double x) {
	return (sqrt((v1 + v2)*(v1 + v2) + 2*x*(a1 + a2)) - (v1 + v2)) / (a1 + a2);
}

/*
 * It is assumed that all given values are positive
 */
int solution () {
	double v1, v2, a1, a2, x, t;
	int scheck;
	
	scheck = scanf("%lf%lf%lf%lf%lf", &v1, &v2, &a1, &a2, &x);
	
	if (scheck != 5)
		return 1;
	if (v1 < 0 || v2 < 0 || a1 < 0 || a2 < 0 || x < 0)
		return 1;
	if (v1 + v2 + a1 + a2 < 0.00001)
		return 1;
	
	if (a1 + a2 < 0.00001) {
		t = solve_eq(v1, v2, x);
	} else {
		t = solve_ac(v1, v2, a1, a2, x);
	}
	
	printf("%f\n", t);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
