#include <iostream>
#include <queue>
#include <stack>
using namespace std;
const int maxN = 100000;
int line[maxN + 10];
bool bolline[maxN + 10];
int minute = 0;
queue<int> s;
stack<int> ans;
int bfs(int n,int k) {
	if (bolline[n]) return 0;
	bolline[n] = true;
	if (n == k) return line[n];
	if (n - 1 >= 0 && n <= maxN && !bolline[n - 1]) {
		s.push(n - 1); 
		line[n - 1] = line[n] + 1;
		bolline[n - 1] = true;
	}
	if (n >= 0 && n + 1 <= maxN && !bolline[n + 1]) { 
		s.push(n + 1);
		line[n + 1] = line[n] + 1;
		bolline[n + 1] = true;
	}
	if ((n * 2 < maxN) && (!bolline[n * 2])) {	
		s.push(n * 2); 
		line[2 * n] = line[n] + 1;
		bolline[2 * n] = true;
	}
	/*
	else {   
		line[n]--;
		bolline[n] = false;
		return 0;
	}
	*/
	while (!s.empty())
	{
		int temp =s.front();
		s.pop();
		bfs(temp, k);
	} 
	return 0;
}


int n = 0, k = 0;
int POJ3278() {
	memset(line, 0, sizeof(line));
	memset(bolline, 0, sizeof(bolline));

	scanf("%d%d", &n, &k);
	int ans = bfs(n, k);
	cout << ans;
	return 0;
}