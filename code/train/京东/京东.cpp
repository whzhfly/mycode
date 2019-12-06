// 京东.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。>
#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int limit = 1002;
struct  goods
{
	int x;
	int y;
	int z;
};
bool cmp(goods a,goods b) {
	if (a.x != b.x)
		return a.x < b.x;
	if (a.y != b.y)
		return a.y < b.y;
	return a.z < b.z;

}
int main()
{
	int n;
	cin >> n;
	vector<goods> goodsvec;
	for (int i = 0; i < n; i++) {
		goods food;
		cin >> food.x >> food.y >> food.z;
		goodsvec.push_back(food);
	}
	sort(goodsvec.begin(),goodsvec.end(), cmp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j<n; j++) {
			if (goodsvec[i].y < goodsvec[j].y && goodsvec[i].z < goodsvec[j].z) {
				ans++;
				break;
			}
		}
	}
	cout << ans;
	
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
