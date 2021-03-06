// Trucks.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <queue>

using namespace std;


int main()
{
	int n, w, l;
	cin >> n >> l >> w;

	int time = 0;
	int w_bridge = 0;
	int w_truck;
	queue<int> on_bridge;


	for (int i = 0; i < l; ++i) {
		on_bridge.push(0);
	}

	for (int i = 0; i < n; ++i) {
		cin >> w_truck;
		while (true) {
			w_bridge -= on_bridge.front();
			on_bridge.pop();
			time++;
			if (w_truck + w_bridge <= w) {
				on_bridge.push(w_truck);
				w_bridge += w_truck;
				break;
			}
			else {
				on_bridge.push(0);
			}
		}
	}

	cout << time + l << endl;


    return 0;
}

