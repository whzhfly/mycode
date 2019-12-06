// test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<string>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
string solution(string input) {
	char mid = input[0];
	//找到第一个分割的逗号
	if (input.size() == 4) {
		string s="";
		if(input[1]==',')
			s +=input[2];
		else
		{
			s += input[1];
		}
		return s;
	}
	if (input.size() == 5) {
		string s = "";
		s += input[1];
		s += input[3];
		return s;
	}
	int cnt1 = 0;
	int index = 2;
	for (int i = 1; i < input.size() - 1; i++) {
		if (input[i] == '(')
			cnt1++;
		if (input[i] == ')')
			cnt1--;
		if (input[i] == ',' && cnt1 == 1) {
			index = i;
			break;
		}
	}
	string left_t="", right_t="";
	for (int i = 2; i < index; i++) {
		left_t += input[i];
	}
	for (int i = index+1; i < input.size()-1; i++) {
		right_t += input[i];
	}
	string left = solution(left_t);
	string right = solution(right_t);
	return left + mid + right_t;
}
/******************************结束写代码******************************/


int main() {
	string res;

	string _input;
	getline(cin, _input);

	res = solution(_input);
	cout << res << endl;

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
