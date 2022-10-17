#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int factorial (int n) {
	if (n <= 0)
		return 1;
	return n * factorial(n - 1);
}

double f (int n, double u, double v) {
	int i = 1;
	double a_p, b_p, a, b, S = 0;
	
	a_p = 0;
	b_p = 0;
	
	a = u;
	b = v;
	
	S += a * b / factorial(i + 1);
	
	for (i = 2; i <= n; ++ i) {
		a_p = a;
		b_p = b;
		
		a = 2 * b_p + a_p;
		b = 2 * a_p * a_p + b_p;
		
		S += a * b / factorial(i + 1);
	}
	
	return S;
}

int solution () {
	int n, scheck;
	double u, v;
	
	scheck = scanf("%lf%lf", &u, &v);
	if (scheck != 2)
		return 1;
	
	scheck = scanf("%d", &n);
	if (scheck != 1)
		return 1;
	if (n < 1)
		return 1;
	
	printf("%f\n", f(n, u, v));
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
