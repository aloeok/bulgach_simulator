#include "stdio.h"
#define MAX_SUM_CUBE 5832

int digit_sum (int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int resolve (int n) {
	int ds, sum_cube, b;
	
	ds = digit_sum(n);
	sum_cube = ds * ds * ds;
	
	for (b = 0; b * b <= MAX_SUM_CUBE; ++ b)
		if (b * b == sum_cube)
			return b;
	
	return -1;
}

int solution () {
	int n, scheck, sol;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 1 || n > 99)
		return 1;
	
	sol = resolve(n);
	
	if (sol == -1)
		printf("NO\n");
	else
		printf("YES\n");
	
	return 0;
}

int main () {
	int exit_code = 0;
	exit_code = solution();
	return exit_code;
}
