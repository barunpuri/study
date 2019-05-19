// Farm.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>



int main()
{
	int testCase;
	std::cin >> testCase;
	for (int t = 0; t < testCase; ++t) {
		int a, b, n, w;
		std::cin >> a >> b >> n >> w;
		int i = 1; 
		int j = n - 1;
		int x, y;
		int ok = 0;
		while (i <= n - 1) {
			if (i*a + j * b == w){
				ok += 1;
				x = i;
				y = j;
			}
			i += 1;
			j -= 1;
		}

		if (ok == 1)
			std::cout << x << " " << y << std::endl;
		else
			std::cout << -1 << std::endl;
	}
	return 0;
}

