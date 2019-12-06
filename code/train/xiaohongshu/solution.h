
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
#include<map>
#include<queue>
using namespace std; 
struct point
{
	int x;
	int y;
	int times;
};

struct pppoint
{
	long long  x;
	long long  y;
};
void trap(vector<pppoint> &vec,vector<pppoint> &res,vector<bool> &visit,int & t){
	bool is = true;
	pppoint tmp = res[res.size()-1];
	for (int i =0 ; i < vec.size(); i++) {
		if (!visit[i]) {
			if (vec[i].x >= tmp.x && vec[i].y >= tmp.y)
			{
				res.push_back(vec[i]);
				visit[i] = true;
				is = false;
				trap(vec,res,visit,t);
				visit[i] = false;
				res.pop_back();
			}
		}
	}
	if (true) {
		int t2 = res.size();
		t = max(t,t2);
	}
}
class xiaohonghsu {
public:
	static void solution1() {
		int n, m, k;
		cin >> n >> m >> k;
		vector< vector<bool>> visit(n, vector<bool>(m, false));
		while (k--)
		{
			int x, y;
			cin >> x>> y;
			visit[x][y] = true;
		}
		queue<point> q;
		point p;
		visit[0][0] = true;
		p.x = 0;
		p.y = 0;
		p.times = 1;
		q.push(p);
		int xt[4]={1,-1,0,0};
		int yt[4]={0,0,1,-1};
		int res = 0;
		bool t = false;
		while (!q.empty())
		{
			point tmp = q.front();
			if (tmp.x == n - 1 && tmp.y == m - 1)
			{
				res = tmp.times;
				t = true;
				break;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_x = tmp.x + xt[i];
				int next_y = tmp.y + yt[i];
				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m)
				{
					if (visit[next_x][next_y])
						continue;
					point next;
					next.x = next_x;
					next.y = next_y;
					next.times = tmp.times + 1;
					q.push(next);
					visit[next_x][next_y] = true;
				}
			}

		}
		if(t)
			cout << res-1;
		else
		{
			cout << '0';
		}
	
	}
	static void solution2() {
		string s;
		cin >> s;
		vector<char> vec;
		int cnt = 0;
		int pre = -9;
		for (int i = 0; i < s.size(); i++) {
			int len = vec.size();
			if (s[i] == '<') {
				if (len == 0 ||i==0|| s[i-1] == '<' || s[i - 1] == '(' || s[i - 1] == ')')
					continue;
				else if(i-1==pre)
				{
					vec.pop_back();
				}
			}
			else if(s[i]=='(')
			{
				cnt++;
			}
			else if(s[i]==')')
			{
				cnt--;
			}
			else if(cnt==0)
			{
				vec.push_back(s[i]);
				pre = i;
			}
		}
		for (auto i : vec)
			cout << i;
	}
	static void solution3() {
		int n;
		cin >> n;
		vector< vector<bool>> visit(n, vector<bool>(n, false));
		int x=0, y=0,des_x=0,des_y=0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j++) {
				int tmp = s[j];
				if (tmp == '.')
					continue;
				else if (tmp=='#')
				{
					visit[i][j] = true;
				}
				else if(tmp=='S')
				{
					x = i;
					y = j;
					visit[i][j] = true;
				}
				else if(tmp=='E')
				{
					des_x = i;
					des_y = j;
				}
			}
		}
		queue<point> q;
		point p;
		p.x = x;
		p.y = y;
		p.times = 0;
		q.push(p);
		int xt[4] = { 1,-1,0,0 };
		int yt[4] = { 0,0,1,-1 };
		int res = 0;
		bool is = false;
		while (!q.empty())
		{
			point tmp = q.front();
			if (tmp.x == des_x && tmp.y ==des_y)
			{
				res = tmp.times;
				is = true;
				break;
			}
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next_x = tmp.x + xt[i];
				int next_y = tmp.y + yt[i];
				if (next_x == n)
					next_x =0;
				if (next_x == -1)
					next_x = n-1;
				if (next_y == n)
					next_y = 0;
				if (next_y == -1)
					next_y = n - 1;
				if (!visit[next_x][next_y])
				{
					point next;
					next.x = next_x;
					next.y = next_y;
					next.times = tmp.times + 1;
					q.push(next);
					visit[next_x][next_y] = true;
				}
			}

		}
		if(is)
			cout << res;
		else
		{
			cout << "-1";
		}
		

	}
	static void solution4() {
		long long n;
		cin >> n;
		vector<pppoint> vec;
		vector<pppoint> res;
		vector<bool> visit(n,false);
		for (int i = 0; i < n; i++) {
			long long x, h;
			pppoint p;
			cin >> p.x>> p.y;
			vec.push_back(p);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			res.push_back(vec[i]);
			visit[i] = true;
			trap(vec,res,visit,ans);
			visit[i] = false;
			res.pop_back();
		}
		cout << ans;
	}
};



#pragma once
