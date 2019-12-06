
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
#include<map>
#include<set>
#include<queue>
using namespace std; 
struct tree
{
	int weight;
	int cnt;
};
struct  cmp {
	bool operator() (const tree& a, const tree& b) {
		if (a.cnt == b.cnt)
			return a.weight < b.weight;
		else
		{
			return a.cnt < b.cnt;
		}
	}
};
class pdd2019 {
public:
	static void solution1() {
		int n, k;
		cin >> n >> k;
		vector<int> nums;
		map<int, int> mp;
		for (int i = 0; i < n; i++) {
			char tmpc;
			cin >> tmpc;
			int tmp = tmpc - '0';
			nums.push_back(tmp);
			mp[tmp]++;
			if (mp[tmp] >= k)
				return;
		}
		int res = 888;
		int flag = 0;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			int cnt = k - it->second;
			priority_queue<int, vector<int>> q;
			for (int i = 0; i < n; i++) {
				int tmp = nums[i];
				int dif = abs(tmp - it->first);
				if (dif != 0)
					q.push(dif);
			}
			int sum = 0;
			while (cnt--)
			{
				sum += q.top();
				q.pop();
			}
			if (res > sum) {
				res = sum;
				flag = it->first;
			}
		}
		cout << res;
	}
	static void solution2() {
		int n;
		cin >> n;
		vector<int> nums;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			nums.push_back(tmp);
			sum += tmp;
		}
		vector<int> res;
		int pre = -1;
		while (sum>0)
		{
			int pos=0;
			int max = 0;
			int index = 0;
			for (int i = 0; i < n; i++) {
				if (i == pre)
					continue;
				if (nums[i] >max)
					pos = i;
			}
			if (nums[pos] >= (sum+1) / 2) {
				res.push_back(pos + 1);
				nums[pos]--;
			}
			else
			{
				while (nums[index]==0||index==pre)
				{
					index++;
				}
				res.push_back(index+1);
				nums[index]--;
				pos = index;
			}
			sum--;
			pre = pos;
		}
		for (auto i : res)
			cout << i << " ";
	}
};

class pdd2020 {
public:
	static void solution1() {
		bool flag = true;
		priority_queue<int, vector<int>,less<int>> q_oushu;
		priority_queue<int, vector<int>, less<int>> q_jishu;
		while (1)
		{
			if (flag) {
				int tmp;
				cin >> tmp;
				if (tmp % 2 == 0) {
					q_oushu.push(tmp);
				}
				else
				{
					q_jishu.push(tmp);
				}
				flag = false;
			}
			else
			{
				flag = true;
				char tmpc;
				cin >> tmpc;
				if (tmpc == ';')
					break;
			}
		}
		int n;
		cin >> n;
		vector<int> res;
		int cnt = 0;
		while (!q_oushu.empty())
		{
			if (cnt == n)
				break;
			cnt++;
			int t = q_oushu.top();
			q_oushu.pop();
			res.push_back(t);
		}
		while (!q_jishu.empty())
		{
			if (cnt == n)
				break;
			cnt++;
			int t = q_jishu.top();
			q_jishu.pop();
			res.push_back(t);
		}
		for (int i = 0; i < res.size()-1; i++) {
			cout << res[i] << ',';
		}
		cout << res[res.size() - 1];
	}
	static void solution2() {
		int n;
		cin >> n;
		while (n--) {
			string s, str;
			cin >> s >> str;
			set<char> se;
			for (int i = 0; i < s.size();i++) {
				se.insert(s[i]);
			}
			for (int i = 0; i < str.size(); i++) {
				if (se.find(str[i]) == se.end()) {
					cout << '{' << endl;
					cout << '}' << endl;
					continue;
				}
			}
			set<char> se_str;
			for (int i = 0; i < str.size(); i++) {
				se_str.insert(str[i]);
			}
			string s_tmp = "";
			for (int i = 0; i < s.size(); i++) {
				if (se_str.find(s[i]) != se.end())
					s_tmp += s[i];
			}
			if (s_tmp.size() < str.size()) {
				cout << '{' << endl;
				cout << '}' << endl;
				continue;
			}
			vector< vector<char>> res;
			
		}
	}
	static void solution4() {
		int n, m, k;
		long long res;
		cin >> n >> m >> k;
		if (n > m) {
			int tmp = n;
			n = m;
			m = tmp;
		}
		if (k == 1) {
			res = m * n;
			cout <<res;
			return;
		}
		int index = 1;
		int pos = n - 1;
		int cnt = 0;
		while (index<=m)
		{
			if (cnt >= k)
				break;
			cnt += index;
			index++;
			pos--;
		}
		if (cnt >= k) {
			int dif =index-( cnt - k)-2;
			int x = pos + dif+2;
			int y = m-dif;
			res = x * y;
			cout << res;
		}
		else
		{

		}
		
	}
};
#pragma once
