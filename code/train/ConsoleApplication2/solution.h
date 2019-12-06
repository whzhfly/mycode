#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
class fogStepn {
public:
	int step(int number) {
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		vector<int> a(number+1, 0);
		a[0] = 1;
		a[1] = 1;
		a[2] = 2;
		for (int i = 3; i <= number; i++)
		{
			for (int j = 0; j < i; j++)
			{
				a[i] += a[j];
			}
		}
		return a[number];
	}
};
class fogStep12 {
public:
	int step(int n) {
		if (n == 1 || n == 0)
			return n;
		int pre = 1;
		int cur = 1;
		for (int i = 2; i <= n; i++) {
			int tmp = cur;
			cur += pre;
			pre = tmp;
		}
		return cur;
	}

};
class rect {
public:
	int rectCover(int number) {
		if (number <= 0)
			return 0;
		if (number == 1 || number == 2)
			return number;
		int cur = 2;
		int pre = 1;
		for (int i = 3; i <= number; i++)
		{
			cur=cur+pre;
			pre= cur-pre;
		}
		return cur;
	}
};
class rabit {
public:
	int resolution1(int n) {
		vector<int> res(n + 1, 0);
		if (n <= 2)
			return n;
		res[0] = 0;
		res[1] = 2;
		res[2] = 2;
		for (int i = 3; i <= n; i++) {
			res[i] = res[i - 2] + res[i - 1];
		}
		return res[n];
	}
	int resolution2(int n) {
		if (n <= 2)
			return n;
		int pre= 2;
		int cur = 2;
		for (int i = 3; i <= n; i++) {

			int tmp = cur;
			cur = cur + pre;
			pre = tmp;
		}
		return cur;
	}
};
class food {
public:
	int solution(int n) {
		int pre = 1;
		int cur = 2;
		if (n <1)
			return n;
		for (int i = 2; i <= n; i++) {
			cur = cur + pre;
			pre = cur - pre;
		}
		return cur;
	}
};
class xyz {
	int solution() {

	}
};
class Q {
public:
	int solution(vector<int> &towl,int n) {
		vector<int> jump(n + 1,0);
		vector<int> climb(n + 1,0);
		for (int i = 1; i <= n; i++) {
			jump[i] = min(jump[i - 1], climb[i - 1]) + towl[i - 1];
			if (i != 1)
				climb[i] = min(jump[i - 1], jump[i - 2]);
		}
		return min(jump[n], climb[n]);
	}
};
class backpack {
public:
	void solution() {
		int m, n;
		cin >> m >> n;
		vector<int> weight(n+1,0);
		vector<int> value(n+1,0);
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			weight[i] = tmp;
		}
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			value[i] = tmp;
		}
		vector<int> dp(n + 1,0);
		for (int i = 1; i <= n; i++) {
			for (int j = m; j >= weight[i]; j--) {
				dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
			}
		}
		cout << dp[n];
	}
};

#pragma once
