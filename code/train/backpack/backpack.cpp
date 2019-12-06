// backpack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"backpack.h"
int main()
{
	vector<int> w{ 0,10,3,4,5 };
	vector<int> v{0,3,4,6,7};
	vector<int> mount{0,5,1,2,1};
	int m = 10;
	int n = 4;

	int res=backpack_01::solution_2di(w,v,m,4);
	cout << res << endl;
	res = backpack_01::solution_1di(w, v, m, 4);
	cout << res<<endl;
	res= backpack_full::solution_2di(w, v, m, 4);
	cout << res << endl;
	res = backpack_full::solution_1di(w, v, m, 4);
	cout << res << endl;
	res = backpack_multi::solution_2di(w, v,mount, m, 4);
	cout << res << endl;
	cout << "3333333333" << endl;
	res = backpack_01::solution_2di(w, v, m, 3);
	cout << res << endl;
	res = backpack_01::solution_1di(w, v, m, 3);
	cout << res << endl;
	res = backpack_full::solution_2di(w, v, m, 3);
	cout << res << endl;
	res = backpack_full::solution_1di(w, v, m, 3);
	cout << res << endl;
	res = backpack_multi::solution_2di(w, v, mount, m, 3);
	cout << res << endl;
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
