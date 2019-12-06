// Huaweidisanti.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include<map>
#include<queue>
using namespace std;
struct myfriend
{
	int i;
	int sum;
};
bool cmp(myfriend & a,myfriend & b) {
	if (a.sum == b.sum) {
		return a.i < b.i;
	}
	return a.sum > b.sum;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m_user, i_index, n_dimension;
		cin >> m_user >> i_index >> n_dimension;
		int k_num;
		cin >> k_num;
		vector< vector<int>> map(k_num,vector<int> (k_num,0));
		for (int i = 0; i < k_num; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			map[x][y] = z;
			map[y][x] = z;
		}
		vector<bool> visit(k_num, false);
		queue<int> des;
		queue<int> sum;
		des.push(i_index);
		sum.push(0);
		visit[i_index] = true;
		int cnt = 0;
		int len = 1;
		int circle = 0;
		vector<myfriend> vecfriend;
		while (!des.empty())
		{
			if (circle == n_dimension) {
				while (!des.empty())
				{
					myfriend f;
					int tmppoint = des.front();
					int tmpsum = sum.front();
					des.pop();
					sum.pop();
					f.i = tmppoint;
					f.sum = tmpsum;
					vecfriend.push_back(f);
				}
				break;
			}
			cnt++;
			int tmppoint = des.front();
			int tmpsum = sum.front();
			des.pop();
			sum.pop();
			for (int i = 0; i < k_num; i++) {
				if (visit[i] == false && map[tmppoint][i] != 0) {
					des.push(i);
					visit[i] = true;
					sum.push(tmpsum+map[tmppoint][i]);
				}
			}
			if (cnt==len) {
				cnt = 0;
				len = des.size();
				circle++;
			}
		}
		if (vecfriend.empty()) {
			cout << "-1" << endl;
		}
		else
		{
			sort(vecfriend.begin(), vecfriend.end(), cmp);
			for (auto i : vecfriend) {
				cout << i.i << " ";
			}
			cout << endl;
		}

	}
}
//void imput(){
//		1
//		10 5 2
//		13 0 3 5 0 4 9 0 6 8 0 7 5 1 2 6 1 6 3 2 9 7 3 4 3 3 5 3 3 8 3 3 9 3 5 8 9 7 8 9
//}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
