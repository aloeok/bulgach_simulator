#include "stdio.h"
#include "math.h"
#define PI 3.14

int solution () {
	double phi1, phi2, phi3, r, s1, s2, s3;
	int scheck;
	
	scheck = scanf("%lf%lf%lf%lf", &phi1, &phi2, &phi3, &r);
	
	if (scheck != 4)
		return 1;
	if (phi1 <= 0 || phi2 <= 0 || phi3 <= 0 || r <= 0)
		return 1;
	if (fabs(phi1 + phi2 + phi3 - PI) > 0.0001)
		return 1;
	
	s1 = 2 * r * sin(phi1);
	s2 = 2 * r * sin(phi2);
	s3 = 2 * r * sin(phi3);
	
	printf("%f\n%f\n%f\n", s1, s2, s3);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
