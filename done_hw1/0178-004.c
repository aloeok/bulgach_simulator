#include "stdio.h"

int predicate (int a, int a_prev, int a_next) {
	return 2 * a < a_prev + a_next;
}

int solution () {
	int n, i, scheck, count = 0;
	int a [100000];
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n > 100000)
		return 1;
	if (n < 1)
		return 1;
	
	for (i = 0; i < n; ++ i) {
		scheck = scanf("%d", a + i);
		if (scheck != 1)
			return 1;
		if (*(a + i) < 1)
			return 1;
	}
	
	for (i = 1; i < n - 1; ++ i) {
		if (predicate(*(a + i), *(a + i - 1), *(a + i + 1)))
			++ count;
	}
	
	printf("%d\n", count);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
