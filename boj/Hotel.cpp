// Hotel.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>


int main()
{
	int numTestCases;
	std::cin >> numTestCases;
	for (int i = 0; i < numTestCases; ++i) {
		int h, w, n;
		std::cin >> h >> w >> n ;

		int floor, num;
		floor = (n-1) % h;
		num = (n-1) / h ;
		int res = (floor+1) * 100 + num+1;
		std::cout << res << std::endl;

	}


	return 0;
}

