#include "stdio.h"
#include "math.h"
#include "stdlib.h"

int factorial (int n) {
	if (n <= 0)
		return 1;
	return n * factorial(n - 1);
}

double pow2 (int n) {
	return pow(2, n);
}

double f (int n) {
	int i = 1;
	double a_p, b_p, a, b, S = 0;
	
	a_p = 0;
	b_p = 0;
	
	a = 1;
	b = 1;
	
	S += pow2(i) / (1 + a*a + b*b) / factorial(i);
	
	for (i = 2; i <= n; ++ i) {
		a_p = a;
		b_p = b;
		
		a = 3 * b_p + 2 * a_p;
		b = 2 * a_p + b_p;
		
		S += pow2(i) / (1 + a*a + b*b) / factorial(i);
	}
	
	return S;
}

int solution () {
	int n, scheck;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 1)
		return 1;
	
	printf("%f\n", f(n));
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
