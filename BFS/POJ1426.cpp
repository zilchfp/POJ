#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <string>


//RESULT:  Time Limit Exceeded
using namespace std;


unsigned long long ans = 1;
bool ok = false;



int bfs(int n) {
	queue<unsigned long long> q;
	if (n == 1) { cout << 1 << endl; return 0; }
	q.push(1);
	while (!ok && !q.empty()) {
		if (q.front() % n == 0) ok = true;
		else {
			q.push(q.front() * 10);
			q.push(q.front() * 10 + 1);
			q.pop();
			continue;
		}
		if (ok) {
			cout << q.front() << endl;
			return 0;
		}
	}

}

int POJ1426() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL

	int n = 1;
	while (scanf("%d", &n) == 1 && n) {
		ans = 1;
		
		ok = false;
		bfs(n);
	}	
	return 0;
}



/*
先读入字符串s（被除数）
bfs构造除数 , 判断s能否被整除

被题目的范围吓到了，本来以为要高精度除法，结果discuss里说unsigned long long就够用了

*/