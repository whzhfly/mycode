
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
		int k, x;
		vector<int> nums{1,2,3,4,5,7,8,9,4,5};
		/*while (!cin.eof())
		{
			int tmp;
			cin >> tmp;
			nums.push_back(tmp);
		}*/
		int len = nums.size()-1;
		k = nums[len-1];
		x = nums[len ];
		len = len - 2;
		vector<int> res_down;
		vector<int> res_up;
		int low = 0, high = len;
		while (low<high)
		{
			int mid = low + (high - low) / 2;
			if (nums[mid] > x) {
				high = mid-1;
			}
			else if(nums[mid] <x)
			{
				low = mid+1;
			}
			else
			{
				low = mid;
				break;
			}
		}
		int cnt = 0;
		int left = low, right = low + 1;
		while (cnt<k&&left>=0&&right<=len)
		{
			int a = abs(nums[left] -x );
			int b = abs(nums[right] - x);
			if (a <= b) {
				res_down.push_back(nums[left]);
				left--;
			}
			else
			{
				res_up.push_back(nums[right]);
				right++;
			}
			cnt++;
		}
		if (cnt < k && left >= 0) {
			while (cnt<k)
			{
				cnt++;
				res_down.push_back(nums[left]);
				left--;
			}
		}
		else if (cnt < k && right >= 0)
		{
			while (cnt < k)
			{
				cnt++;
				res_up.push_back(nums[right]);
				right++;
			}
		}
		for (int i=res_down.size()-1;i>=0;i--)
			cout << res_down[i]<< " ";
		for (int i=0;i<res_up.size();i++)
			cout << res_up[i]<< " ";

	}
	static void solution2() {
		vector<int> nums{ 1,2,3,4,5,4,3 };
		vector<int> distance{ 0,30,20,35,40 };
		vector<int> power{ 0, 20,18,25,30 };
		int n = 4;
		int limit = 100;
		vector<int> res(limit + 1, 0);
		for (int i = 1; i <= n; i++) {
			for (int j = distance[i]; j <= limit; j++) {
				res[j] = max(res[j], res[j - distance[i]] + power[i]);  //把当前物品拆成多件，每次用一次更新
			}
		}
		cout << res[limit];
	}
};
#pragma once
