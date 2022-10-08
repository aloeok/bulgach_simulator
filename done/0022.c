#include "stdio.h"
#include "math.h"
#define PI 3.14

int solution () {
	double a, b, phi, S;
	int scheck;
	
	scheck = scanf("%lf%lf%lf", &a, &b, &phi);
	
	if (scheck != 3)
		return 1;
	if (a <= 0 || b <= 0 || phi <= 0)
		return 1;
	if (a <= b)
		return 1;
	if (phi >= PI / 2)
		return 1;
	
	S = tan(phi) * (a * a - b * b) / 4;
	
	printf("%f\n", S);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
