#include <iostream>
#include <cstdio>
#include <math.h>
int prime2[1300];

int primeCreate() {
	prime2[0] = 2;
	int m = 1;
	double mark = 0;
	for (int i = 3;i < 10000;i+=2) {
		mark = sqrt((double)i);
		int j;
		for (j = 2; j <= mark; j++)
			if (i % j == 0) break;
		if (j > sqrt((double)i)) prime2[m++] = i;
	}

	return 0;
}


int POJ2739_TWO() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL

	primeCreate();

	int num;
	while (scanf("%d", &num) && num) {
		int total = 0;
		for (int i = 0; prime2[i] <= num; i++) {
			int sum = 0;
			for (int j = 0; prime2[j] <= num; j++) {
				sum += prime2[i + j];
				if (sum == num) total++;
				else if (sum > num) break;
			}
		}
		printf("%d\n", total);
	}



	return 0;
}