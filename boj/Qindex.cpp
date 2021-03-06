// Qindex.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

	int testcase;
	std::cin >> testcase;
	
	for(int k=0; k<testcase; ++k){

	int n;
	std::cin >> n;
	std::vector<int> num = { 0 };
	for (int i = 0; i < n; ++i) {
		int tmp;
		std::cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	
	int res = 0;
	int size = num.size();
	for (int i = 1; i < n+1; ++i) {
		if (num[size - i ] >= i and num[size - 1 - i] <= i){
			res = i;
			break;
		}
	}


	std::cout << res << std::endl;
	}
    return 0;
}

/*
3
5
8 4 5 3 10
4
0 0 0 0
6
12 7 6 8 9 10
*/