#include "stdio.h"

int solution () {
	int scheck;
	double x, y;
	
	scheck = scanf("%lf%lf", &x, &y);
	
	if (scheck != 2)
		return 1;
	
	if (x < 0 && y < 0) {
		x = - x;
		y = - y;
	} else if ( (x < 0 && y >= 0) || (x >= 0 && y < 0) ) {
		x += 0.5;
		y += 0.5;
	} else if ( (x < 0.5 || x > 2.0) && (y < 0.5 || y > 2.0) ) {
		x /= 10;
		y /= 10;
	}
	
	printf("%lf\n%lf\n", x, y);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
