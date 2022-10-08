#include "stdio.h"
#include "math.h"

int solution () {
	double x1, y1, x2, y2, d;
	int scheck;
	
	scheck = scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	
	if (scheck != 4)
		return 1;
	
	d = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
	
	printf("%f\n", d);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
