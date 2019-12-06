#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std;
void dfsdeep(vector < vector<int>> &map,int cur,int deep,int &max_deep,vector<bool> &visit) {
	bool end = true;
	for (int i = 0; i < map.size(); i++) {
		if (map[cur][i] != 0&&visit[i]==false) {
			visit[i] = true;
			end = false;
			dfsdeep(map, i, deep + 1, max_deep,visit);
		}
	}
	if (end)
		max_deep = max(deep,max_deep);
}
class solution {
public:
	static void maptravel()
	{
		int n;
		cin >> n;
		vector < vector<int>> map(n,vector<int> (n,0));
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			map[x-1][y-1] = 1;
		}
		vector<bool> visit(n, false);
		int max_deep=0;
		dfsdeep(map,0,0,max_deep,visit);
		cout << 2 * (n - 1) - max_deep;
		
	}
	static void max_all_1_string() {
		int len,times;
		cin >> len>>times;
		vector<int> cnt0(len,0);
		vector<int> vec;
		int sum0 = 0;
		for (int i = 0; i < len; i++) {
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
			if (tmp == 0)
				sum0++;
			cnt0[i] = sum0;
		}
		int res = 0;
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (cnt0[j] - cnt0[i] == times) {
					if (vec[i] == 1)
						res = max(res, j - i + 1);
					else
					{
						res = max(res, j - i);
					}
				}
				
			}
		}
		cout << res;
		
	}
	static void leastcost() {
		int n, money;
		cin >> n >> money;
		vector<int> food(n+1, 0);
		for (int i = 1; i <= n; i++) {
			int tmp;
			cin >> tmp;
			food[i] = tmp;
		}
		sort(food.begin(), food.end());
		vector<bool> canbuy(money + food[1]+1,false);
		canbuy[0] = true;
		for (int i = 1; i <= n; i++) {
			for (int j = canbuy.size()-1; j>=0; j--) {
				if (canbuy[j] == true&&j+food[i]<money+food[1]) {
					canbuy[j + food[i]] = true;
				}
			}
		}
		int res = money;
		while (canbuy[res]==false&&res<money+food[1])
		{
			res++;
		}
		cout << res;
	}
	static void leastwater() {
		int n;
		cin >> n;
		vector<int> garden(n);
		vector<bool> visit(n, false);
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			garden[i] = tmp;
		}
		int cnt = 0;
		int res = 0;
		while (cnt<n)
		{
			cnt++;
			int min = INT_MAX;
			int index;
			for (int i = 0; i < n; i++) {
				if (visit[i] == false&& min > garden[i]) {
					index = i;
					min = garden[i];
				}
			}
			visit[index] = true;
			res += garden[index];
			int left = index-1,right=index+1;
			while (left>=0&&visit[left]==false)
			{
				garden[left] -= garden[index];
				if (garden[left] == 0) {
					visit[left] = true;
					cnt++;
				}
				left--;
			}
			while (right<n && visit[right] == false)
			{
				garden[right] -= garden[index];
				if (garden[right] == 0) {
					visit[right] == true;
					cnt++;
				}
				right++;
			}
			garden[index] = 0;
		}
		cout << res;
	}
};
class meituan {
public:
	static void solution() {
		string s;
		cin >> s;
		map<char, int> mp;
		int cnt = 0;
		int max = 0;
		for (int i = 0; i < s.size(); i++) {
			auto it = mp.find(s[i]);
			if (it == mp.end())
				cnt++;
			mp[s[i]]++;
			if (mp[s[i]] >= max)
				max = mp[s[i]];
		}
		vector<int> res;
		res.push_back(cnt);
		for (int i = 1; i < max; i++) {
			for (auto it = mp.begin();it!=mp.end(); it++) {
				if (it->second == i)
					cnt--;
			}
			res.push_back(cnt);
		}
		for (auto it : res)
			cout << it << " " << endl;
	}
	struct de
	{
		char x;
		int value;
		de() {
			x = 'a';
			value = 0;
		}
	};
	static void solution2() {
		string s;
		cin >> s;
		vector<string> str;
		for (int i = 0; i < s.size(); i++) {
			string tmp="";
			while (i<s.size()&&s[i]!=' ')
			{
				tmp += s[i];
				i++;
			}
			str.push_back(tmp);
		}
		vector<char> res;
		res.push_back(str[0][0]);
		for (int i = 1; i < str.size(); i++) {
			if(str[i][0]!=str[i-1][0])
				res.push_back(str[i][0]);
		}
		vector<de> devec;
		for (int i = 0; i < s.size(); i++) {
			de d;
			d.x = s[i];
			d.value++;

		}

	}
};
#pragma once
