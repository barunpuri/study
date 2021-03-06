// Eureka.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>



int main()
{
	std::ifstream fin;
	fin.open("input.txt");
	
	int numTestCases;
	fin >> numTestCases;

	int triangle_num[45] = {0, };
	int len = 45;
	for (int i = 0; i < len; ++i) {
		triangle_num[i] = (i + 1)*(i + 2) / 2;
	}


	for (int t = 0; t < numTestCases; ++t) {
		int n;
		fin >> n;
		bool is_tri = false;
		
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j <= i; ++j) {
				for (int k = 0; k <= j; ++k) {
					if (triangle_num[i] + triangle_num[j] + triangle_num[k] == n) {
						is_tri = true;
					}
				}
			}
		}

		if (is_tri)
			std::cout << 1 << std::endl;
		else
			std::cout << 0 << std::endl;

	}


    return 0;
}

/*
사실 범위 [3,1000] 내에서 답이 0인 경우는 4 6 11 20 29 다섯 가지밖에 없습니다.
나머지 경우에 모두 1이 나오는지 테스트해보세요.
1000 이하인 삼각수가 몇 개나 될 지 생각해보시고, 더 간단하고 짧은 브루트 포스 솔루션을 작성해보시면 좋을 것 같습니다.*/