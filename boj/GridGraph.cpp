// GridGraph.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>w

void print(int x1, int y1, int x2, int y2) {	//한줄 출력
	for (int i = x1; i = x2; i += (x1-x2)/abs(x1-x2)) {
		for (int j = y1; j <= y2; j += (y1-y2)/abs(y1-y2)) {
			std::cout << "(" << i << "," << j << ")" << std::endl;
		}
	}
}

int main()
{
	int numTestCases;
	std::cin >> numTestCases;
	for (int i = 0; i < numTestCases; ++i) {
		int x, y;
		std::cin >> x >> y;

		if (x % 2 == 0) {

		}
		else if (y % 2 == 0) {

		}
		else {

		}



	}



    return 0;
}

