#include "stdio.h"
#include "math.h"

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

int actual_solution(double a, double b, double c) {
	int res;
	double x1, x2;
	
	if (fabs(a) < 0.0001)
		return 1;
	
	res = solve_qeq(a, b, c, &x1, &x2);
	
	if (res == -1)
		printf("NO\n");
	else if (res == 0)
		printf("%lf\n", x1);
	else
		printf("%lf\n%lf\n", x1, x2);
	
	return 0;
}

int solution () {
	int scheck, exit_code;
	double a, b, c, h;
	double at, ab, bb;
	
	scheck = scanf("%lf", &h);
	
	if (scheck != 1)
		return 1;
	
	at = fabs(sin(8 * h)) + 17;
	ab = 1 - sin(4 * h) * cos (h * h + 18);
	if (fabs( ab ) < 0.0001)
		return 1;
	a = sqrt(at / ab);
	
	bb = 3 + fabs(tan(a * h * h) - sin(a * h));
	if (fabs( bb ) < 0.0001)
		return 1;
	b = 1 - sqrt(3 / bb);
	
	c = a * h * h * sin(b * h) + b * h * h * h * cos(a * h);
	
	exit_code = actual_solution(a, b, c);
	
	return exit_code;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
