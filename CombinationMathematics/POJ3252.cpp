#include <cstdio>
#include <iostream>
#include <time.h>
using namespace std;
long int start, finishi;
int key,roundNum = 0,counter; //count the 0 and  - if it is 1

//VERSION_ONE：暴力遍历求解
//RESULT:TIME LIMITED OUT


int POJ3252() {

	clock_t start, finish;
	double totaltime;
	start = clock();


	cin >> start >> finishi;
	for (int i = start; i <= finishi; i++) {
		int counter = 0;
		key = i;
		do {
			if (key & 1) counter--;
			else counter++;
			key = key >> 1;
//DEBUG			printf("i:=%d ", key);
		} while (key);
		if (counter >= 0) roundNum++;
	}
	cout << roundNum;

	finish = clock();
	totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
	cout << "\n此程序的运行时间为" << totaltime << "秒！" << endl;

	return 0;

}

