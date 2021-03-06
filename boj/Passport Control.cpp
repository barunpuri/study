// Passport Control.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>



int main()
{
	std::ifstream fin;
	fin.open("input.txt");
	int testCase;
	fin >> testCase;
	for (int t = 0; t < testCase; ++t) {
		int n, k;
		fin >> n >> k;
		if (fin.peek() == EOF)break;
		int* port = new int[k] {0, };
		int* data = new int[n];
		for (int i = 0; i < n; ++i) {
			int tmp;
			fin >> tmp;
			if (fin.peek() == EOF)break;
			data[i] = tmp;

		}
		
		int no = 0;
		for (int i = 0; i < n; ++i) {
			int j = 0;
			while (j < k) {
				if (data[i] > port[j]) {
					port[j] = data[i];
					break;
				}
				++j;
			}
			if (j == k) {
				no = 1;
				break;
			}
		}
		
		if (no == 1)
			std::cout << "NO" << std::endl;
		else
			std::cout << "YES" << std::endl;
	}

    return 0;

}

