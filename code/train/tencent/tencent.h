#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
#include<map>
using namespace std;

void solution1() {
	string s;
	while (!cin.eof()) {
		cin >> s;
		string str = "";
		for (int i = s.size() - 1; i >= 0; i--) {
			str += s[i];
		}
		int res = 0;
		vector<vector<int>> dp(s.size() + 1, vector<int>(str.size() + 1, 0));
		for (int i = 1; i <= s.size(); i++) {
			for (int j = 1; j <= str.size(); j++) {
				if (s[i - 1] == str[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		cout << s.size() - dp[s.size()][str.size()];
	}
}
void solution2() {
	while (!cin.eof()) {
		string s;
		cin >> s;
		int len = s.size();
		int pos = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] <= 'z' && s[i] >= 'a') {
				char tmp = s[i];
				for (int k = i; k > pos; k--) {
					s[k] = s[k - 1];
				}
				s[pos] = tmp;
				pos++;
			}
		}
		cout << s<<endl;
	}
}
void solution3() {
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	sort(nums.begin(), nums.end());
	map<int, int> mp;
	for (int i : nums)
		mp[i]++;
	int max = mp[nums[n - 1]] * mp[nums[0]];
	if (nums[n - 1] == nums[0])
		max = (n) * (n - 1);
	int min_res = INT_MAX;
	int min_cnt;
	for (int i = 0; i < n-1;i++) {
		if (i>0&&nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j < n; j++) {
			if (nums[i] == nums[j])
				continue;
			if (nums[j] - nums[i] < min_res) {
				min_res = nums[j] - nums[i];
				min_cnt= mp[nums[i]] * mp[nums[j]];
			}
			else if (nums[j] - nums[i] == min_res)
				min_res +=mp[nums[i]] * mp[nums[j]];

		}
	}
	cout << min_res << " " << max;
	/*int left = 0;
	int right = n - 1;
	int min_left = 1;
	int min_right = 1;
	while (nums[left]=nums[left+1]&&left+1<n)
	{
		min_left++;
		left++;
	}
	while (nums[right] = nums[right-1] && right-1>=0)
	{
		min_right++;
		right--;
	}
	min = min_left * min_right;
	if (nums[0] == nums[n - 1])
		min = (n) * (n - 1);
	int minvalue = INT_MAX;
	for (int i = 0; i < n; ) {
		int cnt = 0;
		int pre = i;
		while (nums[i]==nums[i+1]&&i+1<n)
		{
			cnt++;
			i++;
		}
		
	}*/
}
#pragma once
