
#include <iostream>
#include <windows.h>
#include<thread>
#include<vector>
#include<atomic>
#include<mutex>
#include<algorithm>
using namespace std; 

class vecresort {
public:
	static void solution1(){
		int n, m;
		cin >> n >> m;
		vector<int> vec1(n);
		vector<int> vec2(n);
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			vec1[i] = tmp;
		}
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			vec2[i] = tmp;
		}
		sort(vec1.begin(), vec1.end());
		sort(vec2.begin(), vec2.end());
		vector<bool> visit1(n, false);
		vector<bool> visit2(n, false);
		vector<int> res;
		int cnt = 0;
		int des = m - 1;
		while (cnt<n)
		{
			for (int i = 0; i < n; i++) {
				if (visit1[i])
					continue;
				for (int j = n - 1; j >= 0; j--) {
					if (visit2[j])
						continue;
					if (vec1[i] + vec2[j] == des|| vec1[i] + vec2[j]==des+m) {
						res.push_back(des);
						cnt++;
						visit1[i] = true;
						visit2[j] = true;
					}
					else if(vec1[i]+vec2[j]>des)
					{
						continue;
					}
					else
					{
						break;
					}
				}
			}
			des--;
		}
		for (auto i : res)
			cout << i << " ";
	}
};

class surfacearea {
public:
	static void solution2() {
		int row, col;
		cin >> row >> col;
		vector< vector<int>> map(row,vector<int> (col));
		int cnt = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int tmp;
				cin >> tmp;
				cnt += tmp;
				map[i][j] = tmp;
			}
		}
		int shadow = 0;
		for

	}
};
#pragma once
