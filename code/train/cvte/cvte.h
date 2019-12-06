
#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<deque>
#include<queue>
using namespace std; 

class cvte {
public:
	int n;
	static void zuoye() {
		string s;
		cin >> s;
		vector<int> res;
		for (int i = 0; i < 4; i++) {
			int tmp = ((s[i] - '0') + 5) % 10;
			res.push_back(tmp);
		}
		swap(res[0], res[3]);
		swap(res[1],res[2]);
		int ans = 0;
		for (int i = 0; i < 4; i++) {
			ans += res[i];
			ans = ans * 10;
		}
		ans = ans / 10;
		cout << ans;
	}

};
#pragma once
