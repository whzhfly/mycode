#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
typedef long long int2;
using namespace std;
struct person
{
	int a;
	int b;
};
bool cmp(person &a ,person &b) {
	if (a.a == b.a)
		return a.b > b.b;
	else
	{
		return a.a < b.a;
	}
}
void trap(vector<person>& p, int& res) {
	int n = p.size() ;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += p[i].a * (i)+p[i].b * (n - i-1);
	}
	if (sum < res)
		res = sum;
}
int flower(int x, int k) {
	int t = x / k;
	if (t == 0)
		return 0;
	
}
class tencent {
public:
	static void solution1(){
		int n, m;
		cin >> n >> m;
		int a=0, b=0, c=0, d=0;
		for (int i = 0; i < n; i++)
		{
			int tmp;
			cin >> tmp;
			if (tmp % 2 == 0)
				b++;
			else
			{
				a++;
			}
		}
		for (int i = 0; i < m; i++)
		{
			int tmp;
			cin >> tmp;
			if (tmp % 2 == 0)
				d++;
			else
			{
				c++;
			}
		}
		int res = 0;
		res += min(a,d);
		res += min(b, c);
		cout << res;
		
		
	}
	static void solution2() {
		int n;
		cin >> n;
		vector<person> p;
		for (int i = 0; i < n; i++) {
			person per;
			cin >> per.a;
			cin >> per.b;
			p.push_back(per);
		}
		//sort(p.begin(), p.end(), cmp);
		int res = INT_MAX;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				swap(p[i], p[j]);
				trap(p, res);
				swap(p[i],p[j]);
			}
		}
		cout << res;
	}
	static void solution3() {
		int n, m;
		cin >> n >> m;
		vector<int> box;
		int sum = 0;
		int sum_box = 0;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			box.push_back(tmp);
			sum_box += tmp;
			sum += tmp*(i+1);
		}
		if (m >= sum)
		{
			cout << n + 1;
			return;
		}
		else
		{
			int res = sum / m;
			cout << res * (n + 1);
		}


	}
	static void solution4() {
		int2 n;
		cin >> n;
		vector<int2> grade;
		vector<int2> sum;
		int2 sum0 = 0;
		for (int i = 0; i < n; i++) {
			int2 tmp;
			cin >> tmp;
			sum0 +=tmp;
			sum.push_back(sum0);
			grade.push_back(tmp);
		}
		long long res = 0;
		for (int i = 0; i < n; i++) {
			int right = i ;
			int j=i, k=i;
			while (right < n)
			{
				if (grade[right] < grade[i])
					break;
				j = right;
				right++;
			}
			int left = i ;
			while (left >= 0)
			{
				if (grade[left] < grade[i])
					break;
				k = left;
				left--;
			}
			long long tmp = (sum[j] - sum[k]+grade[k]) * grade[i];
			res = max(tmp, res);
		}
		cout << res;
	}
	static void solution5() {
		int t, k;
		cin >> t >> k;
		while (t--)
		{
			int a, b;
			cin >> a >> b;
			int res = 0;
			
		}
	}
};
#pragma once
