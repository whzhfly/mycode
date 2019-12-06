#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<deque>
#include<queue>
using namespace std;
class solution {
public:
	//4+2+1*5*5*4  转换顺序
	static void solution1() {
		int n;
		cin >> n;
		vector<int> nums;
		vector<char> fuhao;
		nums.push_back(0);
		fuhao.push_back('+');//解决4-3的问题
		for (int i = 0; i < n - 1; i++) {
			int tmp;
			cin >> tmp;
			nums.push_back(tmp);
			char inx;
			cin >> inx;
			fuhao.push_back(inx);
		}
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
		n++;
		//必须先用*/号来判断，因为1*1+2+3*4*5  这里的+号只有一个能用上。
		vector<bool> visit(n, false);
		for (int i = 0; i < n - 1; i++) {
			vector<int> tmp_num;
			if (fuhao[i] == '*') { 
				int j = i;
				while (j < n - 1 && fuhao[i] == fuhao[j])
				{
					j++;
				}
				int next_i = j - 1;
				if (visit[i])//**/的情况
					i++;
				for (int k = i; k <= j; k++) {
					visit[k] = true;
					tmp_num.push_back(nums[k]);
				}
				sort(tmp_num.begin(), tmp_num.end());
				int k = 0;
				for (int t = i; t <= j; t++) {
					nums[t] = tmp_num[k];
					k++;
				}
				i =next_i;//后面i++
			}
			if (fuhao[i] == '/') {  //其中3/4/5的3不能换
				int j = i;
				while (j < n - 1 && fuhao[i] == fuhao[j])
				{
					j++;
				}
				int next_i = j - 1;
				if (!visit[i]) // 4/5/6 和3*5/4/5的情况 都要i++
				{
					visit[i] = true;
				}
				i++;
				for (int k = i; k <= j; k++) {
					visit[k] = true;
					tmp_num.push_back(nums[k]);
				}
				sort(tmp_num.begin(), tmp_num.end());
				int k = 0;
				for (int t = i; t <= j; t++) {
					nums[t] = tmp_num[k];
					k++;
				}
				i = next_i;//后面i++
			}
		}
		for (int i = 0; i < n - 1; i++) {
			vector<int> tmp_num;
			int j = i;
			if (fuhao[i] == '+' || fuhao[i] == '-') {
				while (j < n - 1 && fuhao[i] == fuhao[j])
				{
					j++;  //理论上所有都影响下一位 只不过用visit来判断
				}
				int next_i = j-1;
				if (visit[i] )
					i++;
				if (visit[j])
				{
					j--;
				}
				if (i >= j)
					continue;
				for (int t = i; t <= j; t++) {
					visit[i] = true;
					tmp_num.push_back(nums[t]);
				}
				sort(tmp_num.begin(), tmp_num.end());
				int k = 0;
				for (int t = i; t <= j; t++) {
					nums[t] = tmp_num[k];
					k++;
				}
				i = next_i;//后面有i++
			}

		}
		for (int i = 1; i < n-1; i++) {
			
			cout << nums[i] << " ";
			cout << fuhao[i] << " ";
		}
		cout << nums[n - 1];
	}
	static void solution2() {
		
	}
};
#pragma once
