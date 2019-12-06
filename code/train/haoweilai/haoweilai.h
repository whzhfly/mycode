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
typedef struct node {
	int data;
	struct node* link;
	node(int a):data(a) {};
} NODE;
class solution {
public:
	static void solution1() {
		node* head = new node(1);
		node* cur = head;
		int a = 5;
		int cnt = 0;
		while (a--)
		{
			cnt++;
			int tmp;
			cin >> tmp;
			node * next = new node(tmp);
			cur->link = next;
			cur = next;
		}
		head = head->link;
		set<int> se;
		node* res = head;
		node* pre = head;
		head->data = abs(head->data);
		se.insert(head->data);
		node* p = head->link;
		cnt--;
		int cnt1 = 1;
		while (cnt--)
		{
			int t = abs(p->data);
			p->data = t;
			if (se.find(t) == se.end()) {
				cnt1++;
				se.insert(t);
				pre->link = p;
				pre = p;
				p = p->link;
			}
			else
			{
				p = p->link;
			}
		}
		while (cnt1--)
		{
			cout << res->data << " ";
			res = res->link;
		}
	}
	static void solution2() {
		long long n;
		cin >> n;
		priority_queue<int, vector<int>, less<int>> q;
		for (long long i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			q.push(tmp);
		}
		long long cnt = (n+999) / 1000;
		while (cnt--)
		{
			int t = q.top();
			cout << t << endl;
			q.pop();
		}
	}
	static void solution3() {
		long long n;
		cin >> n;
		priority_queue<int, vector<int>, greater<int>> q;
		long long cnt = (n + 999) / 1000;
		int t = 0;
		for (long long i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			if (t < cnt) {
				t++;
				q.push(tmp);
			}
			else
			{
				if (tmp > q.top()) {
					q.pop();
					q.push(tmp);
				}
			}
		}
		while (cnt--)
		{
			int t = q.top();
			cout << t << endl;
			q.pop();
		}
	}
};
#pragma once
