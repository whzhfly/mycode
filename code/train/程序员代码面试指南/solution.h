#include <iostream>
#include <windows.h>
#include<thread>
#include<vector>
#include<atomic>
#include<mutex>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std; 
struct multiTreeNode
{
	int happy = 0;
	int parent = -1;
	vector<int> child;
	int subTreeMaxHappy = 0;
};
int creatmosthappytree(vector<multiTreeNode> & vec,int index) {
	auto& node = vec[index];
	if (node.child.empty())
		return node.happy;
	if (node.subTreeMaxHappy != 0)
		return node.subTreeMaxHappy;
	 //分本节点去和本节点不去2种情况
	 //分别计算2种情况值，取最大值
	int total1 = node.happy, total2 = 0;
	// total 1的情况
	for (int i = 0; i < node.child.size(); i++) {
		auto& childindex = node.child[i];
		for (int j = 0; j < vec[childindex].child.size(); i++){
			total1+=creatmosthappytree(vec,vec[childindex].child[j]);
		}
	}
	//total 2
	for (int i = 0; i < node.child.size(); i++) {
		total2 += creatmosthappytree(vec,node.child[i]);
	}
	node.subTreeMaxHappy = max(total1, total2);
	return node.subTreeMaxHappy;
}
class stacksolution {
private:
	stack<int> s;
public:
	void show() {
		while (!s.empty())
		{
			int tmp = s.top();
			cout << tmp << endl;
			s.pop();
		}
	}
	void myinit() {
		s.push(5);
		s.push(1);
		s.push(9);
		s.push(2);
		s.push(10);
	}
	/******     ****/
	/*****利用递归逆序栈***/
	int getandremoverstact() {  //不断地取最底层的Num
		int num = s.top();
		s.pop();
		if (s.empty())
			return num;
		else
		{
			int last = getandremoverstact();
			s.push(num);
			return last;
		}

	}
	void reverse_stack() {
		if (s.empty())
			return;
		int i = getandremoverstact();
		reverse_stack();
		s.push(i);
	}

	/******利用一个栈实现另一个栈的排序,从顶到底 从小到大****/

	
	void sort_stack() {
		stack<int> helper;
		while (!s.empty())
		{
			int cur = s.top();
			s.pop();
			while (!helper.empty()&&helper.top()>cur)//如果cur小于等于helper栈顶，则直接压入helper，否则将helper元素逐一弹出压入stack,直至cur小于helper栈顶
			{
				int i = helper.top();
				helper.pop();
				s.push(i);
			}
			helper.push(cur);
		}
		while (!helper.empty())
		{
			int tmp = helper.top();
			helper.pop();
			s.push(tmp);
		}
	}
	/******最大窗口问题****/
	void max_window(vector<int> &num,int size) {
		vector<int> res;
		deque<int> s;
		int len = num.size();
		for (unsigned int i = 0; i < len; i++)
		{
			while (s.size() && num[i] >= num[s.back()])
				s.pop_back();
			while (s.size() && i - s.front() + 1 > size)
				s.pop_front();
			s.push_back(i);
			if (size && i + 1 >= size)
				res.push_back(num[s.front()]);
		}
		for (int i : res) {
			cout << i << endl;
		}

	}

	/******最大子矩阵的大小***/
	void max_matrix(vector< vector<int>> &map) {
		if (map.empty() || map[0].empty())
			return;
		int row = map.size();
		int col = map[0].size();
		int max_area = 0;
		vector<int> height(col,0);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				height[j] = map[i][j] == 0 ? 0 : height[j] + 1;
			}
			/*  开始判断  */
			max_area = max(max_area,helper(height));
		}
		cout << max_area;
	}
	int helper(vector<int> & height) {
		int  res = 0;
		stack<int> st;
		height.push_back(0);//最后多一位0 方便全部弹出
		for (int i = 0; i < height.size(); i++) {
			while (!st.empty() && height[i] <= height[st.top()]) {  //每次的st.top()是剩余最大值
				int j = st.top();
				st.pop();
				int k = st.empty() ? -1 : st.top();
				int curarea = (i - k - 1) * height[j];
				res = max(res, curarea);

			}
			st.push(i);
		}
		/*while (!st.empty()) {  //不push（0）的时候
			int j = st.top();
			st.pop();
			int k = st.empty() ? -1 : st.top();
			int curarea = (height.size() - k - 1) * height[j];  //？这里为什么是heigh.size()不是st.size()
			res = max(res, curarea);
		}*/
		return res;
	}

	/***最大值减去最小值小于或等于num的子数组数量***/
	void maxmincon(vector<int> &vec,int num) {

	}
};
class day1 {
public:
	static void singlesstack() {
		long long n;
		cin >> n;
		vector<long long> nums;
		for (long long i = 0; i < n; i++) {
			long long tmp;
			cin >> tmp;
			nums.push_back(tmp);
		}
		stack<long long> s;
		vector<long long > res_left(n);
		vector<long long> res_right(n);
		s.push(0);
		for (long long i = 1; i < n; i++) {
			long long left = s.top();
			if (nums[i] >= nums[left]) {
				s.push(i);
			}
			else
			{
				while (!s.empty()&&nums[i]<nums[s.top()])
				{
					long long tmp = s.top();
					s.pop();
					long long l;
					if (s.empty())
						l = -1;
					else
					{
						l = s.top();
					}
					long long r = i;
					res_left[tmp] = l;
					res_right[tmp] = r;
				}
				s.push(i);
			}
		}
		while (!s.empty())
		{
			long long tmp = s.top();
			s.pop();
			long long l;
			if (s.empty())
				l = -1;
			else
			{
				l = s.top();
			}
			res_left[tmp] = l;
			res_right[tmp] = -1;
		}
		for (long long i = 0; i < n; i++) {
			cout << res_left[i] << " "<<res_right[i] << endl;
		}
	}
	///////////////////
	//////////////////
	static void happparty() {
		int n, root;
		cin >> n >> root;
		vector<multiTreeNode> vec(n+1);
		multiTreeNode node;
		for (int i = 1; i < n+1 ; i++) {
			cin >> vec[i].happy;
		}
		int parent_, child_;
		for (int i = 1; i <=n - 1; i++) {
			cin >> parent_ >> child_;
			vec[child_].parent = parent_;
			vec[parent_].child.push_back(child_);
		}
		cout << creatmosthappytree(vec,root);
	}
};
#pragma once
