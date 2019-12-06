// 网易游戏2020.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"solution.h"
#include <iostream>
#include<vector>

using namespace std;
class cafe
{
public:
	static int  solution(vector<int>& cafevec, int k)
	{
		int n = cafevec.size();
		int endday = 1;
		int startday = 1;
		if (n != 0)
		{
			endday = cafevec[n - 1];
			startday = cafevec[0];
		}
		int res = n;
		for (int i = 1; i < n; i++)
		{
			int len = cafevec[i] - cafevec[i - 1] - 1 - 2 * k;
			if (len)
			{
				int j = 1;
				while (j <= len)
				{
					res++;
					j += k + 1;
				}
			}
		}
		if (n != 0)
		{
			int i = k + 1;
			while (i < cafevec[0])
			{
				res++;
				i += k + 1;
			}
			i = cafevec[n - 1] + k + 1;
			while (i <= 30)
			{
				res++;
				i += k + 1;
			}
		}
		else
		{
			for (int i = 1; i <= 30; i += k + 1)
			{
				res++;
			}
		}
		return res;
	}
};
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int k, M;
		cin >> k >> M;
		vector<int>cafevec(M, 0);
		for (int j = 0; j < M; j++)
		{
			cin >> cafevec[j];
		}
		cout << cafe::solution(cafevec, k) << endl;
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
