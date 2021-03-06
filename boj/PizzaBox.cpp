// PizzaBox.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <set>

int main()
{
	int t;
	std::cin >> t;

	for(int k=0; k<t; ++k){

	int n, m;
	std::cin >> n >> m;

	int** box = new int*[n];
	long long sum = 0;
	std::set<int> high;
	for (int i = 0; i < n; ++i) {
		box[i] = new int[m];
		int max = 0;
		for (int j = 0; j < m; ++j) {
			int tmp;
			scanf("%d", &tmp);
			//std::cin >> tmp;
			box[i][j] = tmp;
			sum += (long long)tmp;
			if (tmp > max) {
				max = tmp;
			}
		}
		high.insert(max);
	}

	/*for (int i = 0; i < n; ++i) {
		int max=0;
		for (int j = 0; j < m; ++j) {
			if (box[i][j] > max ) {
				max = box[i][j];

			}
		}
		high.insert(max);
	}*/
	for (int j = 0; j < m; ++j) {
		int max=0;
		for (int i = 0; i < n; ++i) {
			if (box[i][j] > max ) {
				max = box[i][j];
			}
		}
		high.insert(max);
	}
	
	for (std::set<int>::iterator it = high.begin(); it != high.end(); ++it) {
		sum -= (long long)*it;
	}
	
	std::cout << sum << std::endl;
	}
    return 0;
}

/*
2
3 5
1 11 25 20 23
17 2 16 21 15
10 3 12 24 22
4 4
1 2 4 6
16 9 13 11
5 10 8 15
12 14 7 3
*/

