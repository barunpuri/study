// BlackChain.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>


int main()
{
	int testCase;
	std::cin >> testCase;
	for (int t = 0; t < testCase; ++t) {

		long long n;
		std::cin >> n;
		long long i = 1;
		for (; pow(2, i)*i <= n; ++i) {}
		std::cout << i-1 << std::endl;

	}

    return 0;
}

