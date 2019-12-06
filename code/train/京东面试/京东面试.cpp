// 京东面试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include"solution.h"
using namespace std;
int fmin(vector<long long>& num, int pos) {
	int min = num[pos];
	int index = pos;
	for (int i = pos; i < num.size(); i++) {
		if (min > num[i]) {
			index = i;
			min = num[i];
		}
	}
	return min;
}
int fmax(vector<long long>& num) {
	int pos = 0;
	int max = num[pos];
	int index = pos;
	for (int i = pos; i < num.size(); i++) {
		if (max < num[i]) {
			index = i;
			max = num[i];
		}
	}
	return max;
}
int help(vector<long long>& vec) {
	int res = 0;
	int min, max;
	int pos = 1;
	vector<int> left;
	left.push_back(vec[0]);
	while (pos<vec.size())
	{
		min = fmin(vec, pos);;
		max = fmax(vec);
		if (max <= min) {
			left.clear();
			res++;
			left.push_back(vec[pos]);
			pos++;
		}
		else
		{
			left.push_back(vec[pos]);
			pos++;
		}
	}
	if (left.size() > 0)
		res++;
	return res;
}
int main()
{
	int n;
	cin >> n;
	vector<long long> nums;
	int res = 0;
	for (int i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	cout << help(nums) << endl;
	
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
