#include "stdio.h"

int max (int a, int b) {
	return (a > b) ? a : b;
}

int min (int a, int b) {
	return (a < b) ? a : b;
}

int gcd (int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int solution () {
	int m, n, scheck, d;
	
	scheck = scanf("%d%d", &m, &n);
	
	if (scheck != 2)
		return 1;
	if (m < 1 || n < 1)
		return 1;
	
	d = gcd(max(m, n), min(m, n));
	
	printf("%d\n%d\n", m/d, n/d);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
