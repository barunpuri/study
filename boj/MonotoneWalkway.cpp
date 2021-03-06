// MonotoneWalkway.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Point {
public:
	int x;
	int y;
	Point(int x_, int y_) {
		x = x_;
		y = y_;
	}
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << p.x << " " << p.y;
	return os;
}

bool comp(Point p1, Point p2) {
	if (p1.x == p2.x)
		return p1.y < p2.y;
	return p1.x < p2.x;
}
bool comp2(Point p1, Point p2) {
	if (p1.x == p2.x)
		return p1.y > p2.y;
	return p1.x < p2.x;
}

int main()
{
	int numTestCases;
	std::cin >> numTestCases;

	for (int t = 0; t < numTestCases; ++t) {
		int num;
		std::cin >> num;
		std::vector<Point> p = { Point(-1,0) };
		for (int i = 0; i < num; ++i) {
			int x, y;
			std::cin >> x >> y;
			p.push_back(Point(x, y));
		}
		sort(p.begin(), p.end(), comp);

		//for (int i = 0; i < p.size(); ++i)
		//	std::cout << p[i] << std::endl;

		
	
		for (int i = 1; i < p.size()-1; ++i) {
			if (p[i - 1].x != p[i].x and p[i - 1].y != p[i].y) {
				int k = 1;
				while (i + k<p.size() and p[i].x == p[i + k].x ) ++k;
				//std::cout << p[i].x << " " << k << std::endl;
				sort(p.begin() + i, p.begin() + i + k, comp2);
			}
		}
		
		
		int k;
		std::cin >> k;
		for (int i = 0; i < k; ++i) {
			int tmp;
			std::cin >> tmp;
			std::cout << p[tmp] << std::endl;
		}
	
	}
    return 0;
}

/*
1
4
0 0
0 1
1 1
1 0
5 1 4 1 3 1
*/