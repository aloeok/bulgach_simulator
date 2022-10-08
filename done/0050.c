#include "stdio.h"
#include "math.h"

int is_solvable (double a1, double b1, double a2, double b2) {
	double D = fabs(a1 * b2 - a2 * b1);
	if (D >= 0.0001)
		return 1;
	return 0;
}

void solve (double a1, double b1, double c1, double a2, double b2, double c2, double* sol_x, double* sol_y) {
	if (fabs(a1) < 0.0001) {
		a1 += a2; b1 += b2; c1 += c2;
	}
	
	b2 += b1 * (-a2 / a1); c2 += c1 * (-a2 / a1); a2 += a1 * (-a2 / a1);
	a1 += a2 * (-b1 / b2); c1 += c2 * (-b1 / b2); b1 += b2 * (-b1 / b2);
	b1 *= (1 / a1); c1 *= (1 / a1); a1 *= (1 / a1);
	a2 *= (1 / b2); c2 *= (1 / b2); b2 *= (1 / b2);
	
	*sol_x = - c1;
	*sol_y = - c2;
}

int solution () {
	double a1, b1, c1, a2, b2, c2, sol_x, sol_y;
	int scheck;
	
	scheck = scanf("%lf%lf%lf%lf%lf%lf", &a1, &b1, &c1, &a2, &b2, &c2);
	
	if (scheck != 6)
		return 1;
	if (!is_solvable(a1, b1, a2, b2))
		return 1;
	
	solve(a1, b1, c1, a2, b2, c2, &sol_x, &sol_y);
	
	printf("%f\n%f\n", sol_x, sol_y);
	
	return 0;
}

int main () {
	int exit_code = 0;
	/*while (1)*/ exit_code = solution();
	return exit_code;
}
