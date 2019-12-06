
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include<map>
using namespace std; 

class twosum {
	static void solution() {
		vector<int> num;
		while (!cin.eof())
		{
			int tmp;
			cin >> tmp;
			num.push_back(tmp);
		}
		int p = num[num.size() - 1];
		num.pop_back();
		int low = 0, high = num.size() - 1;
		while (low<high)
		{
			if (num[low] + num[high] == p) {
				cout << num[low] << "," << num[high] << endl;
				if (num[low] != num[low + 1])
					low++;
				else
				{
					high--;
				}
			}
			else if(num[low]+num[high]<p)
			{
				low++;
			}
			else
			{
				high--;
			}
		}
	}
};
class stringreverse {
public:
	static void solution3() {
		string str;
		getline(cin,str);
		string res = "";
		for (int i = str.size() - 1; i >= 0; i--) {
			res += str[i];
		}
		cout << res;
	}
};
class longestlianxu {  //https://blog.csdn.net/qq_37497322/article/details/82466400
public:
	static void solution() {
		vector<int> num;
		while (!cin.eof())
		{
			int tmp;
			cin >> tmp;
			num.push_back(tmp);
		}
		map<int, int> mp;
		int res = 0;
		for (int i = 0; i < num.size(); i++)
		{
			int t = num[i];
			if (mp[t])
			{
				continue;
			}
			int len = 1;
			int j = t + 1;  //j表示最右边那个数
			len += mp[t + 1];
			j = t + mp[t + 1];
			int k = t - mp[t - 1];  //k表示最左边那个数
			mp[k] += len;
			mp[j] = mp[k];
			if (mp[k] > res)
				res = mp[k];
			if (!mp[t])
				mp[t] = 1;
		}
		cout << res;
	}
};
#pragma once
