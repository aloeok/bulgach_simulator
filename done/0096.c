#include "stdio.h"
#include "math.h"
#include "stdlib.h"

double f (int n) {
	int i;
	double a_p, b_p, a, b, S;
	
	a_p = 0;
	b_p = 0;
	
	a = 1;
	b = 1;
	
	S = 1;
	
	for (i = 2; i <= n; ++ i) {
		a_p = a;
		b_p = b;
		
		a = 0.5 * (sqrt(b_p) + 0.5 * sqrt(a_p));
		b = 2 * a_p * a_p + b_p;
		
		S += a * b;
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
