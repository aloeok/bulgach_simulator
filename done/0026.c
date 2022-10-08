#include "stdio.h"
#include "math.h"
#define PI 3.14
#define R 13.7

int solution () {
	double phi, a;
	int scheck;
	
	scheck = scanf("%lf", &phi);
	
	if (scheck != 1)
		return 1;
	
	if (phi < 0 || phi > 2 * PI)
		return 1;
	
	a = R * R * phi / 2;
	
	printf("%f\n", a);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
