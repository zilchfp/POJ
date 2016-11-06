/*²Î¿¼×ÊÁÏ£ºhttp://blog.csdn.net/zhengnanlee/article/details/9794625 */
//VERSION_TOW:COMBINATION
int factorial(int n) {
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}
int Combination(int all, int key) {
	return ((factorial(all)) / (factorial(all) * factorial(all - key)));
}

int POJ3252_TWO() {

	return 0;
}
