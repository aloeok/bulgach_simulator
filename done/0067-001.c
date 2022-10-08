#include "stdio.h"

int find_digit_num (int n) {
	int num = 0;
	while (n > 0) {
		++ num;
		n /= 10;
	}
	return num;
}

int solution () {
	int n, scheck, digit_num;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 1 || n > 100)
		return 1;
	
	digit_num = find_digit_num(n);
	
	printf("%d\n", digit_num);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
