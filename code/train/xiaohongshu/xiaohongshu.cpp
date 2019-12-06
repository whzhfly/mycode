// xiaohongshu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
class Solution3 {
public:
	struct point {
		int x;
		int y;
		bool operator<( point& b) const
		{
			if (this->x == b.x)
				return this->y > b.y;
			return this->x < b.x;
		}
	};
	static bool cmp(point a,point b)
	{
		return a.x < b.y;
	}
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
		int n = envelopes.size();
		vector<int> dp(n , 1);
		vector<point> vec;
		for (int i = 0; i < n; i++) {
	
				point p;
				p.x = envelopes[i][0];
				p.y = envelopes[i][1];
				vec.push_back(p);
			
		}
		int res = 0;
		sort(vec.begin(), vec.end(),cmp);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (vec[i].y > vec[j].y)
					dp[i] = max(dp[i], dp[j] + 1);
			}
			res = max(res, dp[i]);
		}

		return res;

	}
};

int main()
{
	vector<vector<int>> envelopes={ {5,4},{6,4}, {6,7} ,{2,3} }; 
	Solution3 s;
	int a= s.maxEnvelopes(envelopes);
	cout << a;
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
