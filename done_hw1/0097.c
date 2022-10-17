#include "stdio.h"
#include "math.h"
#include "stdlib.h"

double f (int n) {
	int i;
	double x_p, y_p, x, y, S;
	
	x_p = 0;
	y_p = 0;
	
	x = 1;
	y = 1;
	
	S = 0.5;
	
	for (i = 2; i <= n; ++ i) {
		x_p = x;
		y_p = y;
		
		x = 0.3 * x_p;
		y = x_p + y_p;
		
		S += x / (1 + fabs(y));
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
