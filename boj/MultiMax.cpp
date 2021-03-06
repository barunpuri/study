// MultiMax.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

bool comp(int a, int b) {
	return a > b;
}


int main()
{
	int n;
	std::vector<int> nums;

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp;
		std::cin >> tmp;
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end(), comp);

	int res = nums[0] * nums[1];
	if (nums[2] > 0) {
		res *= nums[2];
	}
	
	std::cout << res << std::endl;

	return 0;
}

