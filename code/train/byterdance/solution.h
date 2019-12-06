#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<deque>
#include<queue>
using namespace std; 
void helper(vector< vector<int>>& map, int pos, vector<bool>& visit) {
	for (int i = 0; i < map.size(); i++) {
		if (i == pos)
			continue;
		if (map[pos][i] >= 3&&visit[i]==false) {
			visit[i] = true;
			helper(map,i,visit);
		}
	}
}
bool hascon(int &a, int &b) {
	int m = min(a, b);
	for (int i = 2; i <= m / 2 + 1; i++) {
		if (a % i == 0 && b % i == 0)
		{
			return true;
		}
	}
	return false;
}
void candytrap(vector< vector<int>>& map, int& tmp, vector<bool>& visit, int pos) {
	for (int i = 0; i < map.size(); i++) {
		if (i == pos)
			continue;
		if (map[pos][i] == 1 && visit[i] == false) {
			visit[i] = true;
			tmp++;
			candytrap(map, tmp, visit, i);
		}
	}
}
class solution {
public:
	static void solution1() {
		int n;
		cin >> n;
		vector< vector<int>> map(n,vector<int> (n,0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int tmp;
				cin >> tmp;
				map[i][j] = tmp;
			}
		}
		vector<bool> visit(n, false);
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				visit[i] = true;
				res++;
				helper(map, i, visit);
			}
		}
		cout << res;
	}
	static void solution2() {
		int n;
		cin >> n;
		
	}
	static void solution3() {
		int num;
		cin >> num;
		vector< vector<int>> map(4, vector<int>(4, 0));
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int tmp;
				cin >> tmp;
				map[i][j] = tmp;
			}
		}
		if (num == 1) {
			int times = 3;
			while (times--) {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 4; j++) {
						if (map[i][j] != 0 && map[i][j] == map[i + 1][j]) {
							map[i][j] *= 2;
							map[i + 1][j] = 0;
							int up = i - 1;
							while (up >= 0 && map[up][j] == 0)
							{
								map[up][j] = map[up + 1][j];
								map[up + 1][j] = 0;
								up--;
							}
						}
					}
				}
			}
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (map[i][j] != 0)
					{
						int up = i - 1;
						while (up >= 0 && map[up][j] == 0)
						{
							map[up][j] = map[up + 1][j];
							map[up + 1][j] = 0;
							up--;
						}
					}
				}
			}
		}
		else  if (num == 2) {
			int times = 3;
			while (times--) {
				for (int i = 3; i > 0; i--) {
					for (int j = 0; j < 4; j++) {
						if (map[i][j] != 0 && map[i][j] == map[i - 1][j]) {
							map[i][j] *= 2;
							map[i - 1][j] = 0;
							int down = i + 1;
							while (down < 4 && map[down][j] == 0)
							{
								map[down][j] = map[down - 1][j];
								map[down - 1][j] = 0;
								down++;
							}
						}
					}
				}
			}
			for (int i = 3; i >= 0; i--) {
				for (int j = 0; j < 4; j++) {
					if (map[i][j] != 0)
					{
						int down = i + 1;
						while (down < 4 && map[down][j] == 0)
						{
							map[down][j] = map[down - 1][j];
							map[down - 1][j] = 0;
							down++;
						}
					}
				}
			}
		}
		else if (num == 3) {
			int times = 3;
			while (times--) {
				for (int j = 0; j < 3; j++) {
					for (int i = 0; i < 4; i++) {
						if (map[i][j] != 0 && map[i][j] == map[i][j + 1]) {
							map[i][j] *= 2;
							map[i][j + 1] = 0;
							int up = j - 1;
							while (up >= 0 && map[i][up] == 0)
							{
								map[i][up] = map[i][up + 1];
								map[i][up + 1] = 0;
								up--;
							}
						}
					}
				}
			}
			for (int j = 0; j < 4; j++) {
				for (int i = 0; i < 4; i++) {
					if (map[i][j] != 0) {
						int up = j - 1;
						while (up >= 0 && map[i][up] == 0)
						{
							map[i][up] = map[i][up + 1];
							map[i][up + 1] = 0;
							up--;
						}
					}
				}
			}
		}
		else {
			int times = 4;
			while (times--) {
				for (int j = 3; j > 0; j--) {
					for (int i = 0; i < 4; i++) {
						if (map[i][j] != 0 && map[i][j] == map[i][j - 1]) {
							map[i][j] *= 2;
							map[i][j - 1] = 0;
							int down = j + 1;
							while (down < 4 && map[i][down] == 0)
							{
								map[i][down] = map[i][down - 1];
								map[i][down - 1] = 0;
								down++;
							}
						}
					}
				}
			}
			for (int j = 3; j >= 0; j--) {
				for (int i = 0; i < 4; i++) {
					if (map[i][j] != 0) {
						int down = j + 1;
						while (down < 4 && map[i][down] == 0)
						{
							map[i][down] = map[i][down - 1];
							map[i][down - 1] = 0;
							down++;
						}
					}
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {

				cout << map[i][j] << " ";
			}
			cout << endl;
		}

	}
	static void solution4() {
		int n;
		cin >> n;
		vector<int> candy;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			candy.push_back(tmp);
		}
		vector< vector<int>> map(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (hascon(candy[i], candy[j])) {
					map[i][j] =1;
					map[j][i] = 1;
				}
			}
		}
		vector<bool> visit(n, false);
		int res = 0;
		for (int i = 0; i < n; i++) {
			int tmp= 0;
			if (!visit[i]) {
				visit[i] = true;
				tmp++;
				candytrap(map, tmp, visit, i);
			}
			res = max(tmp, res);
		}
		cout << res;
	}
};
#pragma once
