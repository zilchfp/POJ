#include <iostream>
#include <queue>

//title: Find The Multiple
//RESULT:c++  Time Limit Exceeded
//g++ : AC
using namespace std;


unsigned long long ans = 1;
bool ok = false;


int POJ1426() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL

	int n = 1;
	while ((cin >> n ) && n) {
		ok = false;
		queue<unsigned long long> q;
		if (n == 1) { cout << 1 << endl;continue; }
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
				break;
			}
		}
		
	}return 0;
}