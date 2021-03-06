// GoldBach's Conjecture.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

int main() {
	int numTestCases;
	int prime_num[10000] = { 0,0,1,1,0, };
	std::cin >> numTestCases;


	for (int i = 5; i <= 10000; i += 2) {
		bool divided = false;
		for (int j = 2; j <= sqrt(i); ++j)
			if (i%j == 0) {
				divided = true;
				break;
			}
		if( !divided )
			prime_num[i] = 1;
	}

//	for (int i = 0; i < 10000; ++i) {
//		if (prime_num[i] == 1)
//			std::cout << i << " ";
//	}

	for (int i = 0; i<numTestCases; ++i) {
		int n;
		std::cin >> n;
		for (int j = n / 2; j >= 2; --j) {
			if ((prime_num[j] == 1) and (prime_num[n - j] == 1)) {
				std::cout << j << " " << n - j << std::endl;
				break;
			}
		}
	}
	return 0;
}
