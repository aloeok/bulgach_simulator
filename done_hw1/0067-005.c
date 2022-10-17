#include "stdio.h"

int find_digit_num (int n) {
	int num = 0;
	while (n > 0) {
		++ num;
		n /= 10;
	}
	return num;
}

int find_second_to_last_digit (int n) {
	if (find_digit_num(n) == 1)
		return -1;
	return (n / 10) % 10;
}

int solution () {
	int n, scheck, second_to_last_digit;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 1 || n > 100)
		return 1;
	
	second_to_last_digit = find_second_to_last_digit(n);
	
	if (second_to_last_digit == -1)
		return 1;
	
	printf("%d\n", second_to_last_digit);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
