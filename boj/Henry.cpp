// Henry.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

int Henry(int a, int b) {
	if (a == 1) return b;
	else {
		int x = b / a + 1;
		return Henry(a*x - b, b*x);
	}
}

int main()
{
	int numTestCases;
	std::cin >> numTestCases;
	
	for (int i = 0; i < numTestCases; ++i) {
		int x, y;
		std::cin >> x >> y;
		int res = Henry(x, y);
		std::cout << res << std::endl;
	}


    return 0;
}

