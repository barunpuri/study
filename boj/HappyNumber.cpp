// HappyNumber.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

#include <iostream>
#include <set>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; ++t) {

		int n;
		cin >> n;

		set<int> s;
		s.insert(n);
		int s_size = 0;
		while (n != 1) {
			
			int tmp = 0;

			while (n > 9) {
				tmp += (n % 10)*(n%10);
				n = n / 10;
			}
			tmp += (n % 10)*(n % 10);


			n = tmp;
			s.insert(n);

			if (s_size == s.size())
				break;
			s_size = s.size();
		}
		if (n == 1)
			cout << "HAPPY" << endl;
		else
			cout << "UNHAPPY" << endl;


	}
	

	return 0;
}






/*
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		int sum = n;
		map<int, bool> check_list;
		bool res = false;
		do {
			sum = sumOfPower(sum);
			if (sum == 1) {
				res = true;
				break;
			}

			if (check_list.find(sum) != check_list.end()) {
				res = false;
				break;
			}
			else {
				check_list[sum] = true;
				continue;
			}
		} while (1);
		return res;
	}

	int sumOfPower(int n) {
		int sum = 0;
		while (n != 0) {
			sum += (n % 10)*(n % 10);
			n /= 10;
		}
		return sum;
	}
};



int main(int argc, const char * argv[]) {
	// insert code here...
	Solution sc;
	int happy_num = 5;
	if (sc.isHappy(happy_num)) {
		cout << "HAPPY_NUM" << endl;
	}
	else {
		cout << "UNHAPPY_NUM" << endl;
	}
	return 0;
}
*/