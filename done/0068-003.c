#include "stdio.h"

void make_digit_arr (int n, int* digits) {
	int i;
	for (i = 0; i < 10; ++ i)
		digits[i] = 0;
	for (i = 0; i < 4; ++ i) {
		++ digits[n % 10];
		n /= 10;
	}
}

int are_different_digits (int n) {
	int i;
	int digits [10];
	make_digit_arr(n, digits);
	for (i = 0; i < 10; ++ i)
		if (digits[i] > 1)
			return 0;
	return 1;
}

int solution () {
	int n, scheck;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 1 || n > 9999)
		return 1;
	
	if (are_different_digits(n))
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
