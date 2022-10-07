#include "stdio.h"

int find_digit_num (int n) {
	int num = 0;
	while (n > 0) {
		++ num;
		n /= 10;
	}
	return num;
}

int find_first_digit (int n) {
	int i, digit_num = find_digit_num(n);
	for (i = 0; i < digit_num - 1; ++ i)
		n /= 10;
	return n;
}

int solution () {
	int n, scheck, first_digit;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 1 || n > 100)
		return 1;
	
	first_digit = find_first_digit(n);
	
	printf("%d\n", first_digit);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
