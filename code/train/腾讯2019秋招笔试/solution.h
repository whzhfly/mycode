#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
class tencent {
public:
	int leastTime(int n,vector<int> towl) {
		vector<int> jump(n,0);
		vector<int> climb(n,0);
		jump[0] = 0;
		climb[0] = towl[0];
		for (int i = 1; i < n; i++) {
			if (i >= 2)
				jump[i] = min(climb[i - 1], climb[i - 2]);
			climb[i] = min(climb[i - 1] ,jump[i - 1]) + towl[i];
		}
		return min(climb[n - 1], jump[n - 1]);
	}
	
	int niuniu() {
		int t;
		cin >> t;
		while (t--) {
			int n, m;
			cin >> n >> m;
			vector < vector<int>> t(n+1,vector<int> (m+1,0)); //1ÊÇ°×£¬¶þÊÇºÚ
			t[1][1] = 1;
			int black = n * m / 2;
			int white = n * m - black;
			int x0, y0, x1, y1;
			int x2, y2, x3, y3;
			cin >> x0 >> y0 >> x1 >> y1;
			cin >> x2 >> y2 >> x3 >> y3;
			int d;
			if ((x0 + y0) & 1 == 1)
				d = ((x1 - x0 + 1) * (y1 - y0 + 1)+1) / 2;
			else
				d = (x1 - x0 + 1) * (y1 - y0 + 1) / 2;
			white += d;
			black -= d;
			if ((x2 + y2) & 1 == 1)
				d = ((x3 - x2 + 1) * (y3 - y2 + 1)+1) / 2;
			else
				d = (x3 - x2 + 1) * (y3 - y2 + 1) / 2;
			white += d;
			black -= d;
			int a = max(x0, x2);
			int b = max(y0, y2);
			int c = min(x1, x3);
			d = min(y1, y3);
			int e = 0;
			if (c < a || b < d)
				e = 0;
			else
			{
				if((a+b)&1==1)
					e = ((c - a + 1) * (d - b + 1) + 1) / 2;
				else
					e = (c - a + 1) * (d - b + 1) / 2;
			}
			white -= e;
			black -= e;
			cout << white << endl;
			cout << black << endl;
		}
	}
	
	int min() {
		
	}
};
class bytedance {
public:
	int find() {
		int N, D;
		cin >> N >> D;
		vector<int> t(100000, 0);
		for (int i = 0; i < N; i--)
		{
			int tmp;
			cin >> tmp;
			t[tmp] = 1;
		}
		int res;
		for (int i = 0; i < t.size(); i++) {
			if (t[i] == 1)
			{
				int x = i + D;
				while (t[i]!=1&&x>i)
				{
					x--;
				}
				if (x == i)
					return 0;
				int cnt;
				for (int i = 0; i < x; i++)
				{
					if (t[i] == 1)
						cnt++;
				}
				res = cnt * (cnt - 1) / 2;
			}
		}

	}

	int travel() {
		int n;
		cin >> n;
		vector< vector<int>>  city(n,vector<int> (n,0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int tmp;
				cin >> tmp;
				city[i][j] = tmp;
			}
		}
		vector< vector<int>>  dp(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			dp[0][i] = city[0][i];
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j)
					dp[i][j] = min(dp[i][j], dp[k-j][i] + city[i][j]);
			}
		}

	}
};
#pragma once
