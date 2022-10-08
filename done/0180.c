#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int predicate (int q) {
	q = abs(q);
	return (q % 3 == 0) && (q % 2 == 1);
}

int solution () {
	int n, i, scheck, sum = 0;
	
	scheck = scanf("%d", &n);
	
	if (scheck != 1)
		return 1;
	if (n > 100000)
		return 1;
	if (n < 1)
		return 1;
	
	for (i = 1; i <= n; ++ i) {
		if (predicate(i * i * i - 3 * i * n * n + n))
			sum += i * i * i - 3 * i * n * n + n;
	}
	
	printf("%d\n", sum);
	
	return 0;
}

int main () {
	int exit_code;
	exit_code = solution();
	return exit_code;
}
