// cingetlinecingetline.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
/*当同时使用cin>>,getline()时，需要注意的是，在cin>>输入流完成之后，getline()之前，需要通过

str="\n";
getline(cin,str);

的方式将回车符作为输入流cin以清除缓存，如果不这样做的话，在控制台上就不会出现getline()的输入提示，而直接跳过，因为程序默认地将之前的变量作为输入流。*/
int main()
{
	int age;
	//standard input(cin)
	cout << "Please enter an integer value as your age: ";
	cin >> age;
	cout << "Your ager is: " << age << ".\n";
	//cin and string
	string mystr;
	cout << "What's your name? " << endl;
	mystr = "\n";
	getline(cin, mystr);
	getline(cin, mystr);
	cout << "Hello," << mystr << ".\n";
	char sex;
	cout << "Please enter a F or M as your sex: ";
	cin >> sex;
	cout << "Your sex is: " << sex << endl;
	cout << "What's your favorite team? ";
	mystr = "\n";
	getline(cin, mystr);
	getline(cin, mystr);
	cout << "I like " << mystr << ".\n";

	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
