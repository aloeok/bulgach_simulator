#include "stdio.h"

int is_four_digit_palindrome (int n) {
	int digits [4];
	int i;
	for (i = 0; i < 4; ++ i) {
		digits[i] = n % 10;
		n /= 10;
	}
	return digits[0] == digits[3] && digits[1] == digits[2];
}

int solution () {
	int n, scheck;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n < 1 || n > 9999)
		return 1;
	
	if (is_four_digit_palindrome(n))
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
