// 华为研发.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
int main()
{
	int pos = 0;
	vector<int> A;
	vector<int> B;
	int cnt = 2;
	int R;
	while (cnt--)
	{
		while (1)
		{
			char c;
			cin >> c;
			if (c == '{')
				break;
		}
		while (1)
		{
			int tmp;
			cin >> tmp;
			if (cnt == 1)
				A.push_back(tmp);
			else
			{
				B.push_back(tmp);
			}
			char c;
			cin >> c;
			if (c == '}')
				break;
		}
		if (cnt == 0)
		{
			char c;
			cin >> c >> c >> c;
			int tmp;
			cin >> tmp;
			R = tmp;
		}
	}
	vector< vector<int>> res;
	for (int i = 0; i < A.size(); i++) {
		bool flag = false;
		for (int j = 0; j < B.size(); j++) {
			if (A[i] <= B[j]) {
				if (B[j] - A[i] > R)
				{
					if (!flag)
					{
						vector<int> tmp;
						tmp.push_back(A[i]);
						tmp.push_back(B[j]);
						res.push_back(tmp);
					}
					break;
				}
				else
				{
					vector<int> tmp;
					tmp.push_back(A[i]);
					tmp.push_back(B[j]);
					res.push_back(tmp);
					flag = true;
				}
			}
		}
	}
	for (int i = 0; i < res.size(); i++) {
		cout << "(" << res[i][0] << "," << res[i][1] << ")" << " ";
	}
	return 0;
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
