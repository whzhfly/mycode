#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<deque>
#include<queue>
using namespace std; 
class solution {
public:
	static void solution1() {
		int n, m;
		cin >> n >> m;
		vector<int> res;
		map<int, int> mp;
		while (n--)
		{
			int tmp;
			cin >> tmp;
			mp[tmp]++;
			res.push_back(tmp);
		}
		for (auto i : res) {
			if(mp[i]<=m)
			cout << i << " ";
		}
	}
	static void solution2() {
		int times;
		cin >> times;
		while (times--)
		{
			priority_queue <int, vector<int>, less<int>> q;
			int n;
			cin >> n;
			int ans = 0;
			for (int i = 0; i < n; i++) {
				int tmp;
				cin >> tmp;
				if(tmp!=0)
					q.push(tmp);
			}
			while (!q.empty())
			{
				int num1 = q.top();
				q.pop();
				if (q.empty())
					break;
				int num2 = q.top();
				q.pop();
				if (q.empty())
					break;
				int num3 = q.top();
				q.pop();
				num1--;
				num2--;
				num3--;
				ans++;
				if (num1 > 0)
					q.push(num1);
				if (num2 > 0)
					q.push(num2);
				if (num3 > 0)
					q.push(num3);
			}
			cout << ans << endl;
		}
	}
	static void solution3() {
		int len,times,k;
		cin >> len>>times>>k;
		int ans = 0;
		if (k > len)
		{
			cout << ans;
			return;
		}
		string s,str;
		cin >> s>>str;
		vector<int> mp;
		for (int i = 0; i < s.size(); i++) {
			if (str[i] == s[i])
				mp.push_back(0);
			else
			{
				mp.push_back(1);
			}
		}
		
	}
};
#pragma once
