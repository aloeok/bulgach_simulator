#include "stdio.h"
#include "math.h"

double find_len (double x1, double y1, double x2, double y2) {
	return sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
}

double perimeter (double a, double b, double c) {
	return a + b + c;
}

double area (double a, double b, double c) {
	double p = perimeter(a, b, c) / 2;
	return sqrt( p * (p - a) * (p - b) * (p - c) );
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
	
	if (a < 0.0001 || b < 0.0001 || c < 0.0001)
		return 1;
	if ( (a + b <= c) || (b + c <= a) || (c + a <= b) )
		return 1;
	
	printf("%lf\n", area(a, b, c));
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
