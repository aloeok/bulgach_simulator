#include "stdio.h"
#include "math.h"
#include "stdlib.h"

double a (int i) {
	if (i == 0 || i == 1)
		return 1.0;
	
	return a(i - 2) + a(i - 1) / pow(2, i - 1);
}

double f (int i) {
	if (i == 0)
		return a(0);
	
	return a(i) * f(i - 1);
}

int solution () {
	printf("%f\n", f(14));
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
