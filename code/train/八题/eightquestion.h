
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 


//https://www.cnblogs.com/dramstadt/p/3439725.html
class n_kind_cion {
public:
	static void solution(vector<int> &cost,vector<int> &nums ,int money,int num) {
		int sum = 0;
		vector<int> flag(num+1,false);
		flag[0]= true;
		for (int i = 1; i <= num; i++) {
			vector<int> tmpnumber(num + 1, 0);//表示当前money用第i个cion的数量
			for (int j = cost[i]; j <= money; j++) {
				if ((!flag[j]) && flag[j - cost[i]] && tmpnumber[j - cost[i]] < nums[i]) {
					tmpnumber[j] = tmpnumber[j - cost[i]] + 1;
					sum++;
					flag[j] = true;
				}
			}
		}
		cout << sum << endl;
	}
};
#pragma once
