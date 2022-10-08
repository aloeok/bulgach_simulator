#include "stdio.h"
#include "math.h"
#include "stdlib.h"

double f (int i) {
	if (i == 1)
		return 0.0;
	if (i == 2)
		return 0.0;
	if (i == 3)
		return 1.5;
	
	return f(i - 1) * (i + 1) / (i*i + 1) - f(i - 2) * f(i - 3);
}

int solution () {
	int n, scheck;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 4)
		return 1;
	
	printf("%f\n", f(n));
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
