#include "stdio.h"
#include "math.h"

int solve_qeq (double a, double b, double c, double* x1, double* x2) {
	int res = 1;
	double d = b * b - 4 * a * c;
	
	if (d < 0)
		return -1;
	
	if (fabs(d) < 0.00001)
		res = 0;
	
	*x1 = ( -b + sqrt(d) ) / (2 * a);
	*x2 = ( -b - sqrt(d) ) / (2 * a);
	
	return res;
}

int solution () {
	int scheck, res;
	double a, b, c, x1, x2;
	
	scheck = scanf("%lf%lf%lf", &a, &b, &c);
	
	if (scheck != 3)
		return 1;
	
	if (fabs(a) < 0.0001)
		return 1;
	
	res = solve_qeq(a, b, c, &x1, &x2);
	
	if (res == -1)
		printf("NO\n");
	else if (res == 0)
		printf("%f\n", x1);
	else
		printf("%f\n%f\n", x1, x2);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
