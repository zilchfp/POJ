
#include <iostream>
#include <queue>
using namespace std;

const int maxN = 100000;
int visited3278[maxN + 10];
int land3278[maxN + 10];
int POJ3278(){
#ifdef LOCAL
	freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
#endif // LOCAL

	int n, k;


	queue<int> q;
	memset(visited3278, 0, sizeof(visited3278));
	memset(land3278, 0, sizeof(land3278));

	cin >> n >> k;

	land3278[n] = 0;
	visited3278[n] = true;
	q.push(n);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == k) {
			cout << land3278[k] << endl; break;
		}
		if ((now + 1 <= maxN)  && !visited3278[now + 1] && (now <k)) {
			visited3278[now + 1] = true;
			land3278[now + 1] = land3278[now] + 1;
			q.push(now + 1);
		}
		if ((now - 1 >= 0) &&  !visited3278[now - 1] ) {
			visited3278[now - 1] = true;
			land3278[now - 1] = land3278[now] + 1;
			q.push(now - 1);
		}
		if ((now * 2 <= maxN) && (!visited3278[now * 2])) {
			visited3278[now * 2] = true;
			land3278[now * 2] = land3278[now] + 1;
			q.push(now * 2);
		}
	}
	return 0;
}