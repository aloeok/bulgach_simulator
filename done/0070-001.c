#include "stdio.h"
#define PI 3.14
#define R_SPEED 0.095944

double tm_to_rad (int tm) {
	return PI / 2 - tm * PI / 30;
}

double th_to_rad (double th) {
	return PI / 2 - th * PI / 6;
}

double rev_rad_dist (double ph1, double ph2) {
	return (ph1 - ph2 < 0) ? ph1 - ph2 + 2 * PI : ph1 - ph2;
}

int solution () {
	int th_int, tm, scheck;
	double th, r_th, r_tm, r_dist, r_time;
	
	scheck = scanf("%d%d", &th_int, &tm);
	if (scheck != 2)
		return 1;
	if ( (th_int <= 0) || (th_int > 12) || (tm < 0) || (tm >= 60) )
		return 1;
	th_int %= 12;
	
	th = th_int + tm / 60.0;
	
	r_th = th_to_rad(th);
	r_tm = tm_to_rad(tm);
	r_dist = rev_rad_dist(r_tm, r_th);
	r_time = r_dist / R_SPEED;
	
	printf("%d\n", (int)r_time);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
