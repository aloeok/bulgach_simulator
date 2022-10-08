#include "stdio.h"
#include "math.h"
#include "stdlib.h"

double f (int n) {
	if (n == 0)
		return 1;
	
	return n * f(n - 1) + 1.0/n;
}

int solution () {
	int n, scheck;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 0)
		return 1;
	
	printf("%f\n", f(n));
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
