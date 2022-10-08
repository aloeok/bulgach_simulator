#include "stdio.h"
#define PI 3.14
#define R_SPEED 0.095944

double tm_to_rad (int tm) {
	return PI / 2 - tm * PI / 30;
}

double th_to_rad (double th) {
	return PI / 2 - th * PI / 6;
}

double min (double a, double b) {
	return (a < b) ? a : b;
}

double rev_rad_dist (double ph1, double ph2) {
	return (ph1 - ph2 < 0) ? ph1 - ph2 + 2 * PI : ph1 - ph2;
}

int solution () {
	int th_int, th_int_1, th_int_2, tm, scheck;
	double th_1, th_2, r_th_1, r_th_2, r_tm, r_dist_1, r_dist_2, r_time_1, r_time_2, r_time;
	
	scheck = scanf("%d%d", &th_int, &tm);
	if (scheck != 2)
		return 1;
	if ( (th_int <= 0) || (th_int > 12) || (tm < 0) || (tm >= 60) )
		return 1;
	th_int %= 12;
	
	th_int_1 = (th_int + 3) % 12;
	th_int_2 = (th_int + 9) % 12;
	
	th_1 = th_int_1 + tm / 60.0;
	th_2 = th_int_2 + tm / 60.0;
	
	r_th_1 = th_to_rad(th_1);
	r_th_2 = th_to_rad(th_2);
	r_tm = tm_to_rad(tm);
	
	r_dist_1 = rev_rad_dist(r_tm, r_th_1);
	r_dist_2 = rev_rad_dist(r_tm, r_th_2);
	
	r_time_1 = r_dist_1 / R_SPEED;
	r_time_2 = r_dist_2 / R_SPEED;
	
	r_time = min(r_time_1, r_time_2);
	
	printf("%d\n", (int)r_time);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
