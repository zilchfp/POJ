#include <iostream>
#include <cstdio>
using namespace std;

int DFS() {

	return 0;
}


int POJ2488() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL

	int nCases;
	cin >> nCases;
	while (nCases)
	{
		int p_row, int q_col; 
		cout << "Scenario #" << nCases << ":";
		cin >> p_row >> q_col;
		bool reached[26][26];
		memset(reached, 0, sizeof(reached));
		reached[0][0] = true;


		cout  << endl;
		nCases--;
	}




	return 0;
}