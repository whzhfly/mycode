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
struct machine
{
	int dif;
	int time;
};
struct job
{
	int dif;
	int time;
};
bool cmp_j(job a, job b) {
	if (a.time == b.time)
		return a.dif > b.dif;
	return a.time > b.time;
}
bool cmp_m(machine a, machine b) {
	if (a.time == b.time)
		return a.dif > b.dif;
	return a.time > b.time;
}
class tencent {
public:

	//小Q的歌单
	static void solution1() {
		int k, len_a, cnt_a, len_b, cnt_b;
		cin >> k >> len_a >> cnt_a >> len_b >> cnt_b;
		vector<long long> dp(k + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < cnt_a; i++) {
			for (int j = k; j >= len_a; j--) {
				dp[j] = (dp[j] + dp[j - len_a] % 1000000007);
			}
		}
		for (int i = 0; i < cnt_b; i++) {
			for(int j=k;j>=len_b;j--)
				dp[j] = (dp[j] + dp[j - len_b] % 1000000007);
		}
		cout << dp[k] % 1000000007;
	}

	//安排机器
	static void solution2() {
		int n, m;
		cin >> n >> m;
		vector<machine> m_vec;
		vector<job> j_vec;
		for (int i = 0; i < n; i++) {
			machine m;
			cin >> m.time >> m.dif;
			m_vec.push_back(m);
		}
		for (int i = 0; i < m; i++) {
			job j;
			cin >> j.time >> j.dif;
			j_vec.push_back(j);
		}
		sort(j_vec.begin(), j_vec.end(), cmp_j);
		sort(m_vec.begin(), m_vec.end(), cmp_m);
		int j = 0;
		int cnt = 0, sum = 0;
		vector<bool> visit;
		for (int i = 0; i < m; i++) {
			/*if (j_vec[i].time <= m_vec[j].time && j_vec[i].dif <= m_vec[j].dif) {
				cnt++;
				sum += 200 * j_vec[i].time + 3 * j_vec[i].dif;
				j++;
			}
			else
			{
				if(j)
			}*/
			if (j_vec[i].time <= m_vec[j].time) {  //时间最大 然后难度最适和的
				while (j_vec[i].time <= m_vec[j].time && j_vec[i].dif <= m_vec[j].dif&&j<n&&!visit[i])
				{
					j++;
				}
			}
		}
		cout << cnt << " " << sum;
	}
};
#pragma once
