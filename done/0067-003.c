#include "stdio.h"

int find_last_digit (int n) {
	return n % 10;
}

int solution () {
	int n, scheck, last_digit;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 1 || n > 100)
		return 1;
	
	last_digit = find_last_digit(n);
	
	printf("%d\n", last_digit);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
