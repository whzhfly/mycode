// Search.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int sum = 0;
bool aa(vector<vector<int> > &vec, vector<vector<bool> >& visit,int x,int y,int endx,int endy,int n,int m) {
	if (x == endx && y == endy) {
		sum++;
		return true;
	}
	visit[x][y] = true;
	if (x - 1 >= 0 && x - 1 < n && visit[x - 1][y] == false && vec[x][y] < vec[x - 1][y])
		return aa(vec, visit, x - 1, y, endx, endy, n, m);
	if (x +1 >= 0 && x +1 < n && visit[x+1][y] == false && vec[x][y] < vec[x +1][y])
		return aa(vec, visit, x+1, y, endx, endy, n, m);
	if (y + 1 >= 0 && y + 1 < m && visit[x ][y+1] == false && vec[x][y] < vec[x ][y+1])
		return aa(vec, visit, x, y+1, endx, endy, n, m);
	if (y -1 >= 0 && y- 1 < m && visit[x][y-1] == false && vec[x][y] < vec[x][y-1])
		return aa(vec, visit, x, y -1, endx, endy, n, m);
	visit[x][y] = false;
	return false;
}
int main()
{
	int n, m;
	while (cin>>n>>m)
	{
		vector<vector<int> > vec(n, vector<int>(m));
		for (int i = 0, j = 0; i < n;)
		{
			cin >> vec[i][j];
			if (j + 1 == m)
			{
				i = i + 1;
				j = 0;
				
			}
			else
				j++;
		}
		int x, y, endx, endy;
		cin >> x >> y >> endx >> endy;
		vector<vector<bool> > visit(false);
		int a = aa(vec,visit,x,y,endx,endy,n,m);
		cout << sum % (10 ^ 9);

	}
}

//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
