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
string LCCS(string A, string B) { //dp[i][j]表示数组A的前i个数字和数组B的前j个数字的最长子数组的长度,以i,j结尾的
	int res = 0;
	int index;
	vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
			if (res < dp[i][j])
			{
				res = dp[i][j];
				index = i;
			}
		}
	}
	string resstr = "";
	int pos = index - res ;
	while (res--)
	{
		resstr += A[pos++];

	}
	return resstr;
}
int main()
{
	string s1, s2;
	cin >> s1;
	cin >> s2;
	string res = LCCS(s1, s2);
	cout << res;
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
