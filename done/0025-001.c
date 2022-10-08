#include "stdio.h"
#include "math.h"

double find_len (double x1, double y1, double x2, double y2) {
	return sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
}

double perimeter (double a, double b, double c) {
	return a + b + c;
}

int solution () {
	double ax, ay, bx, by, cx, cy;
	double a, b, c;
	int scheck;
	
	scheck = scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
	
	if (scheck != 6)
		return 1;
	
	a = find_len(bx, by, cx, cy);
	b = find_len(cx, cy, ax, ay);
	c = find_len(ax, ay, bx, by);
	
	if (a < 0.00001 || b < 0.00001 || c < 0.00001)
		return 1;
	if ( (a + b < c + 0.000001) || (b + c < a + 0.000001) || (c + a < b + 0.000001) )
		return 1;
	
	printf("%f\n", perimeter(a, b, c));
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
