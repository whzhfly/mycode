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
	//4+2+1*5*5*4  ת��˳��
	static void solution1() {
		int n;
		cin >> n;
		vector<int> nums;
		vector<char> fuhao;
		nums.push_back(0);
		fuhao.push_back('+');//���4-3������
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
		//��������*/�����жϣ���Ϊ1*1+2+3*4*5  �����+��ֻ��һ�������ϡ�
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
				if (visit[i])//**/�����
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
				i =next_i;//����i++
			}
			if (fuhao[i] == '/') {  //����3/4/5��3���ܻ�
				int j = i;
				while (j < n - 1 && fuhao[i] == fuhao[j])
				{
					j++;
				}
				int next_i = j - 1;
				if (!visit[i]) // 4/5/6 ��3*5/4/5����� ��Ҫi++
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
				i = next_i;//����i++
			}
		}
		for (int i = 0; i < n - 1; i++) {
			vector<int> tmp_num;
			int j = i;
			if (fuhao[i] == '+' || fuhao[i] == '-') {
				while (j < n - 1 && fuhao[i] == fuhao[j])
				{
					j++;  //���������ж�Ӱ����һλ ֻ������visit���ж�
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
				i = next_i;//������i++
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
