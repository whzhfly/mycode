#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<deque>
#include<queue>
using namespace std; 

bool cando(int index,vector<int> &nums,int des) {
	int cnt = 0;
	int pre = -index;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] - pre >= index) {
			cnt++;
			pre = nums[i];
			if (cnt == des)
				return true;
		}
	}
	return false;
}
void trap(int k,int i,vector<int> &sleep,vector<int> eat,int &res,int &tmpnum,vector<int> &tmp,vector<int> & ans,int dif,int li) {
	if (i == sleep.size()) {
		if (tmpnum > res) {
			res = tmpnum;
			for (int i = 0; i < sleep.size(); i++)
				ans[i] = tmp[i];
		}
		return;
	}
	if (i >=k) {
		if (dif<0 || dif>li)
			return;
	}
	//Ë¯¾õ
	tmp.push_back(0);
	tmpnum +=sleep[i];
	trap(k,i + 1, sleep, eat, res, tmpnum, tmp, ans, dif,li);
	tmpnum -= sleep[i];
	tmp.pop_back();
	//³Ô·¹
	tmp.push_back(1);
	tmpnum +=eat[i];
	trap(k, i + 1, sleep, eat, res, tmpnum, tmp, ans, dif, li);
}
class yuncong {
public:
	static void solution1() {
		int n, m;
		cin >> n >> m;
		vector<int> nums;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			nums.push_back(tmp);
		}
		sort(nums.begin(), nums.end());
		int lo = 1, high = nums[n - 1];
		int ans=0;
		while (lo<=high)
		{
			int mid = (lo + high) / 2;
			if (cando(mid, nums, m))
			{
				ans = mid;
				lo= mid+1;
			}
			else
			{
				high= mid -1;
			}
		}
		cout<< ans;
	}
	static void solution3() {
		int n, k, ms, me;
		cin >> n >> k >> ms >> me;
		vector<int> sleep;
		vector<int> eat;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			sleep.push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			eat.push_back(tmp);
		}
		vector<char> tmp;
	}
};
#pragma once
