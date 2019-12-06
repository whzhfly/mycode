
#include <iostream>
#include <windows.h>
#include<thread>
#include<vector>
#include<atomic>
#include<mutex>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std; 
void sw(int & x,int &y) {
	if (x < y) {
		int tmp = x;
		x = y;
		y = tmp;
	}
}
class solution {
public:
	static void xyandm() {
		int x, y, m;
		cin >> x >> y >> m;
		int res = 0;
		sw(x, y);
		if (x <= 0 && y <=0 && m>0)
			cout << "-1" << endl;
		else
		{
			while (x<m)
			{
				res++;
				y= x + y;
				sw(x, y);
			}
			cout << res << endl;
		}
	}

	static void doubleptr() {
		int multi;
		cin >> multi;
		vector<int> vec = {2,3,5,7};
		/*while (!cin.eof())
		{
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}*/
		sort(vec.begin(), vec.end());
		int low = 0, high = vec.size() - 1;
		while (low<high)
		{
			if (vec[low] * vec[high] == multi) {
				cout << "1" << endl;
				break;
			}
			else if (vec[low] * vec[high] < multi)
			{
				low++;
			}
			else
			{
				high--;
			}
		}
		cout << "-1" << endl;
	}
};
#pragma once
