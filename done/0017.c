#include "stdio.h"
#define INR 20.0
#define PI 3.14

double circle_area (double r) {
	return PI * r * r;
}

int solution () {
	double r;
	int scheck;
	
	scheck = scanf("%lf", &r);
	
	if (scheck != 1)
		return 1;
	
	if (r <= 20)
		return 1;
	
	printf("%lf\n", circle_area(r) - circle_area(INR));
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
