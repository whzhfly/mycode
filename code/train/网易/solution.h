
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include<queue>
using namespace std; 
//class niuniufindjob {
//	struct job
//	{
//		long long dif;
//		long long pay;
//	};
//	bool cmp(job & a ,job & b) {
//		if (a.dif == b.dif)
//			return a.pay > b.pay;
//		return a.dif < b.dif;
//	}
//public:
//	void input() {
//		int  jobAccount, peopleNumble;
//		cin >> jobAccount >> peopleNumble;
//		vector<job> jobvec;
//		for (int i = 0; i < jobAccount; i++) {
//			job j;
//			cin >> j.dif >> j.pay;
//			jobvec.push_back(j);
//		}
//		vector<long long> peopeleAbility(peopleNumble);
//		for (int i = 0; i < peopleNumble; i++) {
//			int tmp;
//			cin >> tmp;
//			peopeleAbility[i] = tmp;
//		}
//		find(jobvec,peopeleAbility,jobAccount,peopleNumble);
//		sort(jobvec.begin(), jobvec.end(), cmp);
//		for (int i = 0; i < peopleNumble; i++) {
//			int j = 0;
//			for (; j < jobvec.size(); j++) {
//				if (peopeleAbility[i] < jobvec[j].dif)
//					break;
//			 }
//			j--;
//			if (i>0&&peopeleAbility[i]>=jobvec[j].dif) {
//				cout << jobvec[j].pay;
//				jobvec.erase(jobvec.begin()+j);
//
//			}
//		}
//	}
//	
//	
//};
//guy 也要排序  利用hashmap
//int main()
//{
//	int n, m;
//	while (cin >> n >> m) {
//		vector<pair<int, int> > job(n + 1), guy(m);
//		vector<int> map(m);
//		int mx = 0, index = 0, left = 0;
//		job[0] = make_pair(0, 0);  //有些没有工作
//		for (int i = 1; i <= n; ++i) {
//			cin >> job[i].first >> job[i].second;
//		}
//		for (int i = 0; i < m; ++i) {
//			cin >> guy[i].first;
//			guy[i].second = i;
//		}
//		sort(job.begin(), job.end(), [&](pair<int, int> a, pair<int, int> b) {return a.first < b.first; });
//		sort(guy.begin(), guy.end(), [&](pair<int, int> a, pair<int, int> b) {return a.first < b.first; });
//		for (int i = 0; i <= n; ++i) {
//			mx = max(mx, job[i].second);
//			job[i].second = mx;
//		}  //这个是保证一个工作可被多个人选择，所以使用其保存最大值
//		while (left < m && index < n + 1) {
//			if (guy[left].first >= job[index].first) ++index;
//			else {
//				map[guy[left].second] = job[index - 1].second;
//				++left;
//			}
//		}
//		for (int i = left; i < m; ++i) {  //上面存在一个index<n+1 导致后面没分配完全
//			map[guy[i].second] = job[n].second;
//		}
//		for (int i = 0; i < m; ++i) {
//			cout << map[i] << endl;
//		}
//	}
//}


class div3 {
	typedef long long int ll;
public:
	static void solution() {
		ll l, r;
		while (cin >> l >> r) {
			ll count = 0;
			for (int i = l; i <= r; i++) {
				if ((i + 1) * i / 2 % 3 == 0)    count++;
			}
			cout << count << endl;
		}
		
	}
};

class roadlight {
public:
	static void solution() {
		int number;
		cin >> number;
		while (number--) {
			int len;
			cin >> len;
			string road;
			cin >> road;
			int cnt = 0;
			for (int i = 0; i < len; i++) {
				if (road[i] == 'x')
					continue;
				else {
					cnt++;
					i += 2;
				}
			}
			cout << cnt << endl;
		}
	}
};

class loseway_niuniu {
public:
	static void solution() {
		int n;
		cin >> n;
		string direction;
		cin >> direction;
		int left = 0, right = 0;
		for (auto i : direction) {
			if (i == 'L')
				left++;
			else
				right++;
		}
		left = left % 4;
		right = right % 4;
		int di = left - right;
		if (di > 0) {
			switch (di)
			{
			case 1:
				cout << "W";
				break;
			case 2:
				cout << "S";
				break;
			case 3:
				cout << "E";
				break;
			}
		}
		else if (di < 0)
		{
			switch (di)
			{
			case -1:
				cout << "E";
				break;
			case -2:
				cout << "S";
				break;
			case -3:
				cout << "W";
				break;
			}
		}
		else
			cout << "N";
	}
};

class shudui {
public:
	static void mysolution() {  //wrong
		int n, k;
		cin >> n >> k;
		long long  ans = 0;
		if (n < k)
			cout << ans;
		//x<=y时候 从x开始判断  这里出现了问题 
		int dif = n - k;
		ans = (1 + dif ) * (dif) / 2;  // 总有一个偶数
		//x>y时候 y>k 从y开始判断
		for (int i = k + 1; i <= n; i++) {
			ans+= (n / i - 1)*(i-k);
			if (n % i >= k)
				ans+=n%i-k+1; //不止是加一
		}
		cout << ans;
	}
	static void solution1() {
		int n, k;
		while (cin >> n >> k)
		{
			long long res = 0;
			if (k == 0)
			{
				cout << (long long)n * n << endl;
				continue;
			}
			for (int i = k + 1; i <= n; i++) //y>n 从y开始取
			{
				res = res + (n / i) * (i - k);  //这里的x可以小于y  所以不用减去1
				if (n % i >= k) res = res + n % i - k + 1;
			}
			cout << res << endl;
		}
	}
	
};

class rectnum {
public:

	static void solution() {  //矩形的覆盖转化到边的问题，在转化到点的问题，被覆盖的点，遍历边上所有的（x,y），我们考虑覆盖矩形的左下角那个点，那个点就行某一个矩形的x1,y1，利用它来判断。
		int n;   //重叠的区域角横坐标x必然是【x1，x2】中某个值，重叠的区域角横坐标y必然是【y1，y2】中某个值  **这里我们只考虑被覆盖的矩形的左下角的点x1和y1** 因为它的值对应的矩形的另一个右上角的x2,y2的结果和x1,y1一样
		cin >> n;
		vector<int> x1(n);
		vector<int> y1(n);
		vector<int> x2(n);
		vector<int> y2(n);
		for (int i = 0; i < n; i++) {
			cin >> x1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> y1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> x2[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> y2[i];
		}
		int ans = 0;
		int cnt = 0;
		for (int x : x1) {
			for (int y : y1) {
				for (int i = 0; i < n; i++) {
					if (x >= x1[i] && x < x2[i] && y >= y1[i] && y < y2[i]) {//因为是左下角的点 所有右边不能等于
						cnt++;
					}
				}
				if (cnt > ans)
					ans = cnt;
				cnt = 0;
			}
		}
		cout << ans;
	}
};
void helper(vector<int> &suma,int a, int b, int pos,int limit, vector<int>& nums,int &res) {
	if (suma.size() == 0 &&pos==limit)
		return;
	if (suma.size() == nums.size() && pos == limit)
		return;
	if (pos == nums.size()) {
		if (a > b && a - suma[0] < b + suma[0])
			res++;
	}
	else
	{
		suma.push_back(nums[pos]);
		helper(suma,a+nums[pos],b,pos+1,limit,nums,res);
		suma.pop_back();
		helper(suma, a, b + nums[pos], pos + 1,limit ,nums, res);
	}
}
class basketball {
public:
	static void solution1() {
		int n;
		cin >> n;
		vector<int> ability(n , 0);
		int sum = 0;
		for (int i = 0; i <n; i++) {
			int tmp;
			cin >> tmp;
			sum += tmp;
			ability[i] = tmp;
		}
		sort(ability.begin(), ability.end());
		vector<int> a;
		int res = 0;
		helper(a, 0, 0, 0, n,ability, res);
		cout << res;

	}
	static void solution2() {
		int n;
		cin >> n;
		vector<int> ability(n+1, 0);
		int sum = 0;
		for (int i = 1; i <=n; i++) {
			int tmp;
			cin >> tmp;
			sum += tmp;
			ability[i] = tmp;
		}
		sort(ability.begin(), ability.end());
		vector<int> res(sum / 2 + ability[n], 0);
		res[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = res.size()-1; j>= ability[i]; j--) {
				if (res[j - ability[i]] != 0)
					res[j]++;
			}
		}
	}
};
struct point
{
	int x;
	int y;
	int manx;
	int many;
	point(int a, int b, int c, int d) :x(a),y(b),manx(c),many(d){};
};
void bocktrap(vector< vector<int>> &map,int x,int y,int manx,int many,int des_x,int des_y) {
	int n = map.size();
	int m = map.size();
	int visit[9][9][9][9] = {0};
	visit[x][y][manx][many] =1;
	queue<point> qu;
	point begin(x,y,manx,many);
	qu.push(begin);
	int stepx[4] = {0,0,1,-1};//优点 抽象
	int stepy[4] = {1,-1,0,0 };
	while (!qu.empty())
	{
		point p = qu.front();
		qu.pop();
		if (p.x == des_x && p.y == des_y) {
			cout << visit[p.x][p.y][p.manx][p.many]-1;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int next_manx = p.manx + stepx[i];
			int next_many = p.many + stepy[i];
			if (next_manx < 0 || next_many < 0 || next_manx >= n || next_many >= m || map[next_manx][next_many] == 4)
				continue;
			if (next_manx == p.x && next_many == p.y) {
				int next_x = p.x + stepx[i];
				int next_y = p.y + stepy[i];
				if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= m || map[next_x][next_y] == 4)
					continue;
				if (visit[next_x][next_y][next_manx][next_many])
					continue;
				visit[next_x][next_y][next_manx][next_many] = visit[p.x][p.y][p.manx][p.many]+1;
				qu.push(point(next_x, next_y, next_manx, next_many));
			}
			else
			{
				if (visit[p.x][p.y][next_manx][next_many])
					continue;
				visit[p.x][p.y][next_manx][next_many]= visit[p.x][p.y][p.manx][p.many] + 1;
				qu.push(point(p.x, p.y, next_manx, next_many));
			}
		}
	}
	cout << "-1" << endl;
}
class leihuo {
public:
	static void solution2() {
		int n, d, a;
		cin >> n >> d;
		vector< vector<int>> map(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int tmp;
				cin >> tmp;
				map[i][j] = tmp;
			}
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int line_heng = 0, line_shu = 0, line_down = 0, line_up = 0;
				for (int k = 0; k < d; k++) {
					if (i + d <= n) {
						line_shu += map[i + k][j];
						if (j + d <= n)
							line_down += map[i + k][j+k];
					}
					if (j + d <= n) {
						line_heng += map[i][j + k];
						if (i >=d-1) {
							line_up += map[i - k][j + k];
						}
					}
				}
				res = max(res, line_down);
				res = max(res, line_heng);
				res = max(res, line_shu);
				res = max(res, line_up);
			}
		}
		cout << res;
	}
	static void solution3() {
		int n, m;
		while (cin>>n>>m)
		{
			vector< vector<int>> map(n, vector<int>(m, 0));
			int x, y;
			int manx, many;
			int desx, desy;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					char tmp;
					cin >> tmp;
					if (tmp == '.')
						map[i][j] = 0;
					else if(tmp=='*')
					{
						map[i][j] = 1;
						x = i;
						y = j;
					}
					else if(tmp=='@')
					{
						map[i][j] = 2;
						desx = i;
						desy = j;
					}
					else if(tmp=='X')
					{
						map[i][j] = 3;
						manx = i;
						many = j;
					}
					else 
					{
						map[i][j] = 4;
					}
				}
			}
			bocktrap(map,x,y,manx,many,desx,desy);
		}
	}
};
#pragma once