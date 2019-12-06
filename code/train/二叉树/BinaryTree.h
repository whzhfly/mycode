
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
#include<map>
#include<queue>
using namespace std; 


template<class T>
//node
struct binary_tree_node
{
	T val;
	binary_tree_node<T>* left;
	binary_tree_node<T>* right;
	binary_tree_node(const T& x) :val(x), left(NULL), right(NULL) {}
};

//������
template<class T> class binary_tree {
	typedef binary_tree_node<T>node;
protected:
	node* root;
public:
	binary_tree(T* a, size_t n, const T& invalid)
	{
		size_t index = 0;
		root = create_tree(a, n, invalid, index);
	}
	node* copy_tree(node* root)
	{
		if (root == NULL)
			return NULL;
		node* new_root = new node(root->val);
		new_root->left = root->left;
		new_root->right = root->right;
		return new_root;
	}
	binary_tree(const binary_tree<T>& t) {
		root = copy_tree(t.root);
	}
	binary_tree<T>& operator=(binary_tree<T> t) {
		swap(root, t.root);
		return *this;
	}
	~binary_tree()
	{
		destory(root);
		root = NULL;
	}
	void destory(node* root) {
		if (root == NULL)
			return;
		destory(root->left);
		destory(root->right);
		delete root;
	}
	//����һ�ö�����
	node* create_tree(T* a, size_t n, const T& invalid, size_t& index) {
		node* root = NULL;
		if (a[index] != invalid)
		{
			root = new node(a[index]);
			root->left = create_tree(a, n, invalid, ++index);
			root->right = create_tree(a, n, invalid, ++index);
		}
		return root;
	}
	//ǰ�����
	void prev()
	{
		prev_order(root);
		cout << endl;
	}
	void prev_order(node* root)
	{
		if (root == NULL)
			return;
		cout << root->val << " ";
		prev_order(root->left);
		prev_order(root->right);
	}
	//�ǵݹ��ǰ����� ֱ��curΪNULL����ջΪ�գ������������
	void prev_order_no_r() {
		node* cur = root;
		stack<node*>s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				cout << cur->val << " ";
				s.push(cur);
				cur = cur->left;
			}
			if (!s.empty())
			{
				cur = s.top();
				s.pop();
				cur = cur->right;
			}
		}
		cout << endl;
	}
	//�������
	void in()
	{
		in_order(root);
		cout << endl;
	}
	void in_order(node* root)
	{
		if (root == NULL)
			return;
		in_order(root->left);
		cout << root->val << " ";
		in_order(root->right);
	}
	//�ǵݹ��zhong����� ֱ��curΪNULL����ջΪ�գ������������
	void in_order_no_r() {
		node* cur = root;
		stack<node*> s;
		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			if (!s.empty())
			{
				cur = s.top();
				cout << cur->val << " ";
				s.pop();
				cur = cur->right;
			}
		}
		cout << endl;
	}
	//hou�����
	void post() {
		post_order(root);
		cout << endl;
	}
	void post_order(node* root) {
		if (root == NULL)
			return;
		post_order(root->left);
		post_order(root->right);
		cout << root->val << " ";
	}
	//�ǵݹ��hou����� ֱ��curΪNULL����ջΪ�գ������������
	void post_order_no_r() {
		node* cur = root;
		node* pre = NULL;
		stack<node*> s;
		s.push(root);
		while (!s.empty())
		{
			cur = s.top();
			if ((cur->left == NULL && cur->right == NULL) || (pre != NULL && (pre == cur->left || pre == cur->right)))
			{
				cout << cur->val << " ";
				s.pop();
				pre = cur;
			}
			else   //right����ջ ��֤stack��left�ȳ�ȥ �������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻����
			{
				if (cur->right != NULL) {
					s.push(cur->right);
				}
				if (cur->left != NULL) {
					s.push(cur->left);
				}
			}
		}
		cout << endl;
	}
	//��ڵ����
	int size() {
		size_t size = 0;
		_size(root, size);
		return size;
	}
	void _size(node* root, size_t& size)
	{
		if (root == NULL)
			return;
		_size(root->left, size);
		size++;
		_size(root->right, size);
	}
	//��Ҷ�ӽڵ�ĸ���
	size_t leaf_size() {
		return _leaf_size(root);
	}
	size_t _leaf_size(node* root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;
		return _leaf_size(root->left) + _leaf_size(root->right);
	}
	//��������ĸ߶�
	size_t height() {
		return _height(root);
	}
	size_t _height(node* root) {
		if (root == NULL)
			return 0;
		size_t left = _height(root->left);
		size_t right = _height(root->right);
		return (left > right ? left + 1 : right + 1);
	}
	//���K��Ľڵ������
	size_t get_k(size_t k) {
		return _get_k(root, k);
	}
	size_t _get_k(node* root, size_t k) {
		if (root == NULL)
			return 0;
		//��K�� ÿ��root����һ���ڵ����
		if (k == 1)
			return 1;
		//ע������Ϊʲô��k-1?  �������Ҫ��ڶ���Ľڵ����������Ҫ�õ�һ��ĸ��ڵ�����������������������ĵ�һ��ĸ���
		return _get_k(root->left, k - 1) + _get_k(root->right, k - 1);
	}
	//�������
	void level_order() {
		queue<node*> q;
		if (root != NULL)
			q.push(root);
		while (!q.empty()) {
			node* front = q.front();
			cout << front->val << " ";
			q.pop();
			if (front->left)
				q.push(front->left);
			if (front->right)
				q.push(front->right);
		}
		cout << endl;
	}
	//�ж϶������Ƿ�Ϊ��ȫ������
	bool is_complete_tree() {
		queue<node*> q;
		if (root)
			q.push(root);
		bool flag = true;
		while (!q.empty())
		{
			node* front = q.front();
			q.pop();
			if (front->left)
			{
				if (flag == false)
					return false;
				q.push(front->left);
			}
			else { flag = false; }
			if (front->right)
			{
				if (flag == false)
					return false;
				q.push(front->right);
			}
			else flag = false;
		}
		return true;
	}
	//����һ���ڵ��Ƿ���һ�ö�������
	node* find(const T& x) {
		return _find(root, x);
	}
	node* _find(node* root, const T& x) {
		if (root == NULL)
			return NULL;
		if (root->val == x)
			return root;
		else if (_find(root->left, x))
			return root->left;
		else if (_find(root->right, x))
			return root->right;
		return NULL;
	}
};
#pragma once
