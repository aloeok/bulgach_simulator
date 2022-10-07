#include "stdio.h"
#include "math.h"
#define PI 3.14

double to_deg (double rad) {
	return rad * 180 / PI;
}

double to_rad (double deg) {
	return deg * PI / 180;
}

double dec_part (double a) {
	return a - (int)a;
}

double rad_to_h (double phi) {
	return phi * 6 / PI;
}

double h_to_th (double h) {
	return 12 - h;
}

double get_tm (double th) {
	return dec_part(th) * 60;
}

double tm_to_m (double tm) {
	return 60 - tm;
}

double m_to_rad (double m) {
	return m * PI / 30;
}

double get_minute_angle (double h_phi) {
	return m_to_rad( tm_to_m( get_tm( h_to_th( rad_to_h( h_phi ) ) ) ) );
}

void get_thm (double h_phi, int* h, int* m) {
	double th = h_to_th(rad_to_h(h_phi));
	double tm = get_tm(th);
	*h = (int)th;
	*m = (int)tm;
}

int solution () {
	double phi, m_phi;
	int scheck, h, m;
	
	scheck = scanf("%lf", &phi);
	
	if (scheck != 1)
		return 1;
	if (phi <= 0 || phi > 2 * PI + 0.000001)
		return 1;
	
	m_phi = get_minute_angle(phi);
	get_thm(phi, &h, &m);
	
	printf("%lf\n%d\n%d\n", m_phi, h, m);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
