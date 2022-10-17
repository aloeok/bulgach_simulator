#include "stdio.h"
#include "math.h"

typedef struct {
	double x;
	double y;
} vect;
void init_v (double x, double y, vect* v) {
	(*v).x = x;
	(*v).y = y;
}
void trig_init_v (double r, double phi, vect* v) {
	init_v(r * cos(phi), r * sin(phi), v);
}
void add_v (vect* v1, vect* v2, vect* res) {
	(*res).x = (*v1).x + (*v2).x;
	(*res).y = (*v1).y + (*v2).y;
}
void mlt_v (double a, vect* v) {
	(*v).x = a * (*v).x;
	(*v).y = a * (*v).y;
}
double sc_mul_v (vect* v1, vect* v2) {
	return (*v1).x * (*v2).x + (*v1).y * (*v2).y;
}
double len_v (vect* v) {
	return sqrt(sc_mul_v(v, v));
}

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

double find_bisector (double s1, double s2, double phi_1_2) {
	vect v1, v2, v3;
	
	init_v(s1, 0, &v1);
	trig_init_v(s2, phi_1_2, &v2);
	
	mlt_v(-1, &v1);
	add_v(&v2, &v1, &v3);
	mlt_v(-1, &v1);
	
	mlt_v(s1 / (s1 + s2), &v3);
	
	add_v(&v1, &v3, &v3);
	
	return len_v(&v3);
}

int solution () {
	double a, b, c, pha, phb, phc, ba, bb, bc;
	int scheck;
	
	scheck = scanf("%lf%lf%lf", &a, &b, &c);
	
	if (scheck != 3)
		return 1;
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if ( (a + b <= c) || (b + c <= a) || (c + a <= b) )
		return 1;
	
	find_angles(a, b, c, &pha, &phb, &phc);
	
	ba = find_bisector(b, c, pha);
	bb = find_bisector(c, a, phb);
	bc = find_bisector(a, b, phc);
	
	printf("%f\n%f\n%f\n", ba, bb, bc);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}