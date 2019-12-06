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
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
}; 
class net {
public:
	static void solution1() {
		int T;
		cin >> T;
		vector<string> res;
		while (T--)
		{
			int n;
			cin >> n;
			vector<int> vec;
			int num = 1;
			while (n>=num)
			{
				if(n&num)
					vec.push_back(1);
				else
				{
					vec.push_back(0);
				}
				num = num << 1;
			}
			int i = 0, j = vec.size()-1;
			bool flag = false;
			while (i<=j)
			{
				if (vec[i] == vec[j]) {
					i++;
					j--;
				}
				else
				{
					res.push_back("NO");
					flag = true;
					break;
				}
			}
			if(!flag)
				res.push_back("YES");
		}
		for (auto i : res)
			cout << i << endl;
	}
	static void solution2() {
		int num;
		cin >> num;
		while (num--)
		{
			int N;
			cin >> N;
			vector< vector<int>> tree(N, vector<int>(3, 0));
			vector<bool> isroot(N, true);
			for (int i = 0; i < N; i++) {
				int value, left, right;
				cin >> value >> left >> right;
				tree[i][0] = value;
				tree[i][1] = left;
				tree[i][2] = right;
				if (left != -1)
					isroot[left] = false;
				if (right != -1)
					isroot[right] = false;
			}
			int root = 0;
			for (int i = 0; i < N; i++) {
				if (isroot[i]) {
					root = i;
					break;
				}
			}
			int pre_sum =0;
			queue<int> q;
			q.push(root);
			int sum = 0;
			int cnt = 1;
			bool flag=true;
			while (!q.empty())
			{
				int tmp = q.front();
				q.pop();
				cnt--;
				sum += tree[tmp][0];
				if (tree[tmp][1] != -1)
					q.push(tree[tmp][1]);
				if (tree[tmp][2] != -1)
					q.push(tree[tmp][2]);
				if (cnt == 0)
				{
					if (sum < pre_sum)
					{
						flag = false;
						break;
					}
					cnt = q.size();
					pre_sum = sum;
					sum = 0;
				}

			}
			if (flag)
				cout << "YES" << endl;
			else
			{
				cout << "NO" << endl;
			}
		}
	}
	static void solution3() {
		int Times;
		cin >> Times;
		while (Times--)
		{
			int inter, daynum;
			cin >> inter>> daynum;
			vector<int> cafeday;
			for (int i = 0; i < daynum; i++) {
				int tmp;
				cin >> tmp;
				cafeday.push_back(tmp);
			}
			vector < vector<int>> dp(31,vector<int> (2,0));
			for (int i = 0; i < daynum; i++)
			{
				dp[cafeday[i]][0] = -30;
				dp[cafeday[i]][1] = -30;
			}
			int left = 1;
			for (int t = 0; t <=daynum; t++) {
				int limit;
				if (t == daynum)
					limit = 30;
				else
					limit=cafeday[t];
				//ÌìÊý
				for (int i = left; i <=limit; i++) {
					for (int j = inter;j>=0; j++) {
						if (i-j<0)
							break;
						dp[i][1] = max(dp[i][1], dp[i - j][0] + 1);
					}
					for (int j =0; j<=inter; j++) {
						dp[i][0] = max(dp[i][0], dp[i -j][0]);
						dp[i][0] = max(dp[i][0], dp[i - j][1]);
					}
				}
				left = limit;
				
			}
			int res = max(dp[30][0], dp[30][1]);
			res += daynum;
			cout << res<<endl;
		}
	}
	static void solution4() {
		
	}
};
#pragma once
