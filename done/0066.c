#include "stdio.h"
#include "math.h"

void transform (double* a1, double* a2, double* a3) {
	*a1 = fabs(*a1);
	*a2 -= 0.5;
	*a3 -= 0.5;
}

int solution () {
	int k, m, scheck;
	double x, y, z;
	
	scheck = scanf("%d%d", &k, &m);
	
	if (scheck != 2)
		return 1;
	
	scheck = scanf("%lf%lf%lf", &x, &y, &z);
	
	if (scheck != 3)
		return 1;
	
	if (k < m * m)
		transform(&x, &y, &z);
	else if (k == m * m)
		transform(&y, &x, &z);
	else
		transform(&z, &x, &y);
	
	printf("%f\n%f\n%f\n", x, y, z);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
