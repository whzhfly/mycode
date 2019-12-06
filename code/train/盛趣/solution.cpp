#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
#include<map>
#include<set>
#include<queue>
using namespace std;
static int solution_1di(vector<int> weight, vector<int> value, int m_weight, int backpack_number) {
	vector<int> res(m_weight + 1, 0);  //若背包要求恰好装满 则除了res[0] ，其他初始化为INT_MIN，因为初始化为0也是一种解
	for (int i = 1; i <= backpack_number; i++) {
		for (int j = m_weight; j >= weight[i]; j--) {
			res[j] = max(res[j], res[j - weight[i]] + value[i]);
		}
	}
	return res[m_weight];
}
class solution {
public:
	static void solution1() {
		long long  n;
		cin >> n;
		int cnt = 0;
		long long tmp = n;
		vector<int> vec;
		while (tmp)
		{
			tmp = tmp / 10;
			int t = tmp % 10;
			vec.push_back(t);
		}
		reverse(vec.begin(), vec.end());
		string s = "";
		for (int i = 0; i < vec.size(); i++) {
			
		}

	}
	static void solution2() {
		int m;
		int n;
		cin >> m >> n;
		vector<int> vec;
		while (!cin.eof())
		{
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		vector<int> weight;
		vector<int> value;
		weight.push_back(0);
		value.push_back(0);
		int limt = vec.size() / 2;
		for (int i = 0; i < vec.size(); i++) {
			if (i < limt)
				weight.push_back(vec[i]);
			else
			{
				value.push_back(vec[i]);
			}
		}
		int res = solution_1di(weight,value,m,n);
		cout << res;
	}
	static void solution4() {
		vector<int> toy;
		int money;
		while (1)
		{
			char c;
			cin >> c;
			if (c == ']') {
				cin >> c;
				int tmp;
				cin >> tmp;
				money = tmp;
				break;
			}
			int tmp;
			cin >> tmp;
			toy.push_back(tmp);
		}
		vector<int> dp(money + 1, money);
		for (int i = 1; i <= money; i++) {
			for (int j = 0; j < toy.size(); j++) {
				if(i>=toy[j])
					dp[i] = min(dp[i],dp[i-toy[j]]);
			}
		}
	}
};