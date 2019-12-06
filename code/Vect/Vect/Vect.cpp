// Vect.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Review {
	string title;
	int rating;
};

bool operator<(const Review & r1,const Review & r2);
bool worseThan(const Review &r1,const Review & r2);
bool FillRewiew(const Review & rr);
void showReview(const Review & rr);


int main()
{
	vector<Review> books;
	Review temp;
	while (FillRewiew(temp))
		books.push_back(temp);
	if (books.size() > 0)
	{
		cout << "thanks.U entered the following'"
			<< books.size() << "rating:\n"
			<< "rating\tboks\n'";
		for_each(books.begin(), books.end(), showReview);

		sort(books.begin(), books.end());
		cout << "sort by the title:\nRating\Tbook\n";
		for_each(books.begin(), books.end(), showReview);

		sort(books.begin(), books.end(), worseThan);
		cout << "sort by the rating:\nRating\Tbook\n";
		for_each(books.begin(), books.end(), showReview);

		random_shuffle(books.begin(), books.end());
		cout << "sort by the random_shuffle:\nRating\Tbook\n";
		for_each(books.begin(), books.end(), showReview);
	}
	else
		cout << "no enter.";
	cout << "bye";
	return 0;
}
bool operator<(const Review & r1, const Review & r2) 
{	
	if (r1.title<r2.title)
		return true;
	else if(r1.title == r2.title&&r1.rating < r2.rating)
		return true;
	else false;
}
bool worseThan(const Review & r1, const Review & r2)
{
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}
bool FillRewiew(const Review & r)
{
	cout << "enter book title(quit to quit):";
	int a;
	cin >> a;
	string b = r.title;
	getline(a, b);
	if (r.title == "quit")
		return false;
	cout << "enter the book rating:";
	std::cin>>r.rating;
	if (!cin)
		return false;
	while (cin.get() != '\n')
		continue;
	return true;
}
void showReview(const Review & rr)
{
	cout << rr.rating<< "\t" << rr.title << endl;
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
