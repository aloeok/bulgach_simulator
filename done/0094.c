#include "stdio.h"
#include "math.h"
#include "stdlib.h"

double f (int n) {
	int i;
	double v_pp, u_pp, v_p, u_p, v, u;
	
	v_pp = 0;
	u_pp = 0;
	
	v_p = 0;
	u_p = 0;
	
	v = 1;
	u = 1;
	
	for (i = 3; i <= n; ++ i) {
		v_pp = v_p;
		u_pp = u_p;
		
		v_p = v;
		u_p = u;
		
		u = (u_p - u_pp * v_p - v_pp) / (1 + u_p * u_p + v_p * v_p);
		v = (u_p - v_p) / (fabs(u_pp + v_pp) + 2);
	}
	
	return v;
}

int solution () {
	int n, scheck;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 3)
		return 1;
	
	printf("%f\n", f(n));
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
