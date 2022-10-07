#include "stdio.h"

int find_digit_sum (int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int solution () {
	int n, scheck, digit_sum;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 1 || n > 100)
		return 1;
	
	digit_sum = find_digit_sum(n);
	
	printf("%d\n", digit_sum);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
