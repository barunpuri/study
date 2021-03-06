// PythagoreanExpectation.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

//#include "stdafx.h"
#include <iostream>
#include <pow>

int main()
{
	int numTestCases;
	std::cin >> numTestCases;
	
	for (int i = 0; i < numTestCases; ++i) {
		int n, m;
		std::cin >> n >> m;
		int *score = new int[n] {0, };
		int *lose = new int[n] {0, };

		for (int j = 0; j < m; ++j) {
			int a, b, p, q;
			std::cin >> a >> b >> p >> q;
			score[a-1] += p;
			score[b-1] += q;
			lose[a-1] -= q;
			lose[b-1] -= p;
		}
		int *W = new int[n] {0, };
		for (int j = 0; j < n; ++j) {
			if ( (score[j] ==0) and( lose[j] == 0) )
				W[j] = 0;
			else
				W[j] = 1000 * pow(score[j],2) / (pow(score[j], 2) + pow(lose[j], 2));
		}
		
		int min = 1000, max = 0;
		for (int j = 0; j < n; ++j) {
			if (W[j] < min) 
				min = W[j];
			if (W[j] > max)
				max = W[j];
		}

		free(score);
		free(lose);
		free(W);


		std::cout << max << std::endl << min << std::endl;

	}

	//2 3 5 1 2 3 5 1 3 10 1 1 2 0 7 2 3 9 3 3 2 4 5 4 6 1 2 0 11 1 3 17 13 1 4 17 1 2 3 7 12 2 4 19 17 3 4 17 0

    return 0;
}

