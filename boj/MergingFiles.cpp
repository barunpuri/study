// MergingFiles.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int min(int a, int b) {
	if (a > b)
		return b;
	else
		return a;
}

int main()
{
	ios::sync_with_stdio(false);
	//ifstream cin;
	//cin.open("input.txt");
	int testCase;
	cin >> testCase;
	for (int t = 0; t < testCase; ++t) {

		int n;
		cin >> n;
		int **data = new int*[n];
		for (int i = 0; i < n; ++i)
			data[i] = new int[n] {0, };
		
		int **size = new int*[n];
		for (int i = 0; i < n; ++i) {
			size[i] = new int [n] {0, };
			int tmp;
			cin >> tmp; // ("%d", &tmp);
			size[i][i] = tmp;
		}
		
		for (int i = 0; i < n-1; ++i) {
			for (int j = 1; j < n - i; ++j) {
				int min_n = 987654321;
				for (int k = 0; k < i + 1; ++k) {
					
					min_n = min(min_n, data[j-1][i + j-1-k] + data[i+j-k][i + j]);
				}
				size[j - 1][i + j] = size[j - 1][i + j - 1] + size[i+j][i + j];

				data[j-1][i+j] = min_n+size[j-1][i+j];
			}
		}
		/*
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << data[0][n - 1] << endl;

	}

    return 0;
}

/*

2
4
40 30 30 50
15
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32

*/

/*
#include <iostream>
using namespace std;

int cost[501];
int dp[501][501];
int tmp[501];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++) {
			cin >> cost[i];
			tmp[i] = tmp[i - 1] + cost[i];
		}


		for (int i = 2; i <= k; i++) {
			for (int j = i - 1; j>0; j--) {
				dp[j][i] = 987654321;
				for (int h = j; h <= i; h++) {
					dp[j][i] = min(dp[j][i], dp[j][h] + dp[h + 1][i]);
				}
				dp[j][i] += tmp[i] - tmp[j - 1];
			}
		}
		cout << dp[1][k] << "\n";
	}
	return 0;
}
*/