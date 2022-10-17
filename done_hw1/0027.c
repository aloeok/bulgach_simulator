#include "stdio.h"
#include "math.h"

double rev_cos_law (double aj1, double aj2, double op) {
	double cosph, ph;
	cosph = (aj1 * aj1 + aj2 * aj2 - op * op) / (2 * aj1 * aj2);
	ph = acos(cosph);
	return ph;
}

void find_angles (double a, double b, double c, double* pha, double* phb, double* phc) {
	*pha = rev_cos_law(b, c, a);
	*phb = rev_cos_law(c, a, b);
	*phc = rev_cos_law(a, b, c);
}

int solution () {
	double a, b, c, pha, phb, phc;
	int scheck;
	
	scheck = scanf("%lf%lf%lf", &a, &b, &c);
	
	if (scheck != 3)
		return 1;
	if (a < 0.000001 || b < 0.000001 || c < 0.000001)
		return 1;
	if ( (a + b < c + 0.000001) || (b + c < a + 0.000001) || (c + a < b + 0.000001) )
		return 1;
	
	find_angles(a, b, c, &pha, &phb, &phc);
	
	printf("%f\n%f\n%f\n", pha, phb, phc);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
