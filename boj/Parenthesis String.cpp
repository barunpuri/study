// Parenthesis String.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <String>
#include <vector>

int main() {
	int numTestCases;
	std::cin >> numTestCases;

	for (int i = 0; i<numTestCases; ++i) {
		std::string str;
		std::cin >> str;
		
		std::vector<char> res;
		for( int j=0; j<str.size(); ++j){
			if (str[j] == ')') {
				if ((res.size()>0)and(res[res.size()-1]== '(') ){
					res.pop_back();
					continue;
				}
				else{
					res.push_back(str[j]);
					break;
				}
			}
			res.push_back(str[j]);
		}

		if (res.size() > 0) 
			std::cout << "NO" << std::endl;
		else
			std::cout << "YES" << std::endl;


	}
}
