#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class backpack {
	backpack();
};

class backpack_01 {
public:
	backpack_01();
	static int solution_2di(vector<int> weight, vector<int> value, int m_weight, int backpack_number) {  //其中第一个weight[0]=0 value[0]=0; 也就是weight.size()=m_weight+1;
		vector< vector<int>> res(backpack_number + 1, vector<int>(m_weight + 1, 0));
		for (int i = 1; i <= backpack_number; i++) {
			for (int j = 0; j <= m_weight; j++) {
				if (i > 1) {
					res[i][j] = res[i - 1][j];
					if (j >= weight[i]) {
						res[i][j] = max(res[i][j], res[i - 1][j - weight[i]] + value[i]);
					}
				}
				else  //初始化，只考虑一个背包
				{
					if (j >= weight[1])
						res[i][j] = value[1];
				}
			}
		}
		return res[backpack_number][m_weight];
	}

	static int solution_1di(vector<int> weight, vector<int> value, int m_weight, int backpack_number) {
		vector<int> res(m_weight + 1, 0);  //若背包要求恰好装满 则除了res[0] ，其他初始化为INT_MIN，因为初始化为0也是一种解
		for (int i = 1; i <=backpack_number; i++) {
			for (int j = m_weight; j >= weight[i]; j--) {
				res[j] = max(res[j], res[j - weight[i]] + value[i]);
			}
		}
		return res[m_weight];
	}
};

class backpack_full {
public:
	static int solution_2di(vector<int> weight, vector<int> value, int m_weight, int backpack_number) {
		vector< vector<int>> res(backpack_number + 1, vector<int>(m_weight + 1, 0));
		for (int i = 1; i <= backpack_number; i++) {
			for (int j = 0; j <= m_weight; j++) {
				if (i > 1) {
					res[i][j] = res[i - 1][j];
					if (j >= weight[i]) {
						for (int k = 1; k <= j / weight[i]; k++) {
							res[i][j] = max(res[i - 1][j - k * weight[i]] + k * value[i], res[i][j]);

						}	
					}
				}
				else  //初始化，只考虑一个背包
				{
					if (j >= weight[1])
						res[i][j] =(j/weight[1])* value[1];
				}
			}
		}
		return res[backpack_number][m_weight];

	}

	static int solution_1di(vector<int> weight, vector<int> value, int m_weight, int backpack_number) {
		vector<int> res(m_weight + 1, 0);
		for (int i = 1; i <=backpack_number; i++) {
			for (int j = weight[i]; j<=m_weight; j++) {
				res[j] = max(res[j], res[j - weight[i]] + value[i]);  //把当前物品拆成多件，每次用一次更新
			}
		}
		return res[m_weight];
	}

};

class backpack_multi {
public:
	static int solution_2di(vector<int> weight, vector<int> value, vector<int> mount,int m_weight, int backpack_number) {
		vector< vector<int>> res(backpack_number + 1, vector<int>(m_weight + 1, 0));
		for (int i = 1; i <= backpack_number; i++) {
			for (int j = 0; j <= m_weight; j++) {
				if (i > 1) {
					res[i][j] = res[i - 1][j];
					if (j >= weight[i]) {
						int limit = min(j/weight[i],mount[i]);
						for (int k = 1; k <= limit; k++) {
							res[i][j] = max(res[i - 1][j - k * weight[i]] + k * value[i], res[i][j]);
						}
					}
				}
				else  //初始化，只考虑一个背包
				{
					if (j >= weight[1])
						res[i][j] = (j / weight[1]) * value[1];
				}
			}
		}
		return res[backpack_number][m_weight];
	}

	static int solution_1di(vector<int> weight, vector<int> value, vector<int> mount, int m_weight, int backpack_number) {
		vector<int> res(m_weight + 1, 0);
		
		return res[m_weight];
	}


};
#pragma once
