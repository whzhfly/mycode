#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<deque>
#include<queue>
using namespace std;
class solutoin {
public:
	static  void solution1() {
		int n;
		cin >> n;
		if (n == 0) {
			return;
		}
		if (n == 1) {
			return;
		}
		vector<long long> nums;
		int res = 0;
		for (int i = 0; i < n; i++) {
			long long tmp;
			cin >> tmp;
			nums.push_back(tmp);
		}
		int flag=0;
		if (nums[0] < nums[1])
			flag = -1;
		else if (nums[0] > nums[1])
		{
			flag = 1;
		}
		for (int i = 1; i < n; i++) {
			int dif = nums[i] - nums[i - 1];
			if (flag == 0) {
				if (dif > 0)
					flag = 1;
				else if(dif<0)
				{
					flag = -1;
				}
				else
				{
					flag = 0;
				}
			}
			else if(flag<0)
			{
				if (dif <= 0)
					continue;
				else
				{
					flag = 1;
					res++;
				}
			}
			else
			{
				if (dif >= 0)
					continue;
				else
				{
					flag = -1;
					res++;
				}
			}
		}
		cout << res;
	}
	static void solution2() {
		int n, m;
		cin >> n >> m;
		vector< vector<int>> map(n, vector<int>(n, 0));
		vector<int> relation_in(2*n,0);
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			if (x > y) {
				int tmp = x;
				x = y;
				y = tmp;
			}
			relation_in[x]++;
			relation_in[y-1]++;
			y = y - n-1;
			map[x][y] = 1;
			map[y][x] = 1;
		}
		vector<int> res;
		while (m>0)
		{
			int index = 0;
			for (int i = 1; i < 2 * n; i++) {
				if (relation_in[i] > relation_in[index]) {
					index = i;
				}
			}
			relation_in[index] = 0;
			for (int i = 0; i < n; i++) {
				if (index >= n && map[i][index] == 1) {
					map[i][index] = 0;
					m--;
				}
				else if (index < n && map[index][i] == 1)
				{
					map[index][i] = 0;
					m--;
				}
			}
			res.push_back(index);
		}
		cout << res.size() << endl;
		for (auto i : res)
			cout << i << endl;
	}
	
};
#pragma once
