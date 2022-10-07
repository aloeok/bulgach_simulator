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
	double a, b, c, pha, phb, phc, ha, hb, hc;
	int scheck;
	
	scheck = scanf("%lf%lf%lf", &a, &b, &c);
	
	if (scheck != 3)
		return 1;
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if ( (a + b <= c) || (b + c <= a) || (c + a <= b) )
		return 1;
	
	find_angles(a, b, c, &pha, &phb, &phc);
	
	ha = c * sin(phb);
	hb = a * sin(phc);
	hc = b * sin(pha);
	
	printf("%lf\n%lf\n%lf\n", ha, hb, hc);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
