// 二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"BinaryTree.h"
using namespace std;
void test() {
	int array[] = { 1, 2, 3, '#', '#', 4, 40, '#', '#', '#', 5, 6, '#', '#', '#' };
	binary_tree<int> t(array, sizeof(array) / sizeof(int), '#');
	t.prev();
	t.prev_order_no_r();
	t.in();
	t.in_order_no_r();
	t.post_order_no_r();
	t.level_order();
	cout << "size:" << t.size() << endl;
	cout << "leaf_size:" << t.leaf_size() << endl;
	cout << "height:" << t.height() << endl;
	cout << "is_complete_tree:" << t.is_complete_tree() << endl;
	cout << "k_level_size:" << t.get_k(4) << endl;
	binary_tree<int> ba(t);
	ba.prev_order_no_r();
}

int main()
{
	test();
	system("pause");
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
