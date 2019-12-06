// Binary_tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

template<class T>
//node
struct binary_tree_node
{
	T val;
	binary_tree_node<T> * left;
	binary_tree_node<T> * right;
	binary_tree_node(const T& x):val(x), left(NULL), right(NULL){}
};

//二叉树
template<class T> class binary_tree {
	typedef binary_tree_node<T>node;
protected:
	node * root;
public:
	binary_tree(T * a, size_t n, const T& invalid)
	{
		size_t index = 0;
		root = create_tree(a, n, invalid, index);
	}
	node * copy_tree(node * root)
	{
		if (root == NULL)
			return NULL;
		node * new_root = new node(root->val);
		new_root->left = root->left;
		new_root->right = root->right;
		return new_root;
	}
	binary_tree(const binary_tree<T> & t) {
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
	void destory(node * root) {
		if (root == NULL)
			return;
		destory(root->left);
		destory(root->right);
		delete root;
	}
	//创建一棵二叉树
	node* create_tree(T*a, size_t n, const T& invalid, size_t& index) {
		node * root = NULL;
		if (a[index] != invalid)
		{
			root = new node(a[index]);
			root->left = create_tree(a, n, invalid, ++index);
			root->right = create_tree(a, n, invalid, ++index);
		}
		return root;
	}
	//前序遍历
	void prev()
	{
		prev_order(root);
		cout << endl;
	}
	void prev_order(node * root)
	{
		if (root == NULL)
			return;
		cout << root->val<<" ";
		prev_order(root->left);
		prev_order(root->right);
	}
	//非递归的前序遍历 直到cur为NULL并且栈为空，则遍历结束。
	void prev_order_no_r() {
		node * cur = root;
		stack<node *>s;
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
	//中序遍历
	void in() 
	{
		in_order(root);
		cout << endl;
	}
	void in_order(node * root)
	{
		if (root == NULL)
			return;
		in_order(root->left);
		cout << root->val << " ";
		in_order(root->right);
	}
	//非递归的zhong序遍历 直到cur为NULL并且栈为空，则遍历结束。
	void in_order_no_r() {
		node * cur = root;
		stack<node *> s;
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
	//hou序遍历
	void post() {
		post_order(root);
		cout << endl;
	}
	void post_order(node * root){
		if (root == NULL)
			return;
		post_order(root->left);
		post_order(root->right);
		cout << root->val << " ";
	}
	//非递归的hou序遍历 直到cur为NULL并且栈为空，则遍历结束。
	void post_order_no_r() {
		node * cur = root;
		node * pre = NULL;
		stack<node *> s;
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
			else   //right先入栈 保证stack中left先出去 左孩子在右孩子前面被访问，左孩子和右孩子都在根结点前面被访问
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
	//求节点个数
	int size() {
		size_t size = 0;
		_size(root, size);
		return size;
	}
	void _size(node * root, size_t & size)
	{
		if (root == NULL)
			return;
		_size(root->left, size);
		size++;
		_size(root->right, size);
	}
	//求叶子节点的个数
	size_t leaf_size() {
		return _leaf_size(root);
	}
	size_t _leaf_size(node * root) {
		if (root == NULL)
			return 0;
		if (root->left == NULL && root->right == NULL)
			return 1;
		return _leaf_size(root->left) + _leaf_size(root->right);
	}
	//求二叉树的高度
	size_t height() {
		return _height(root);
	}
	size_t _height(node * root) {
		if (root == NULL)
			return 0;
		size_t left = _height(root->left);
		size_t right = _height(root->right);
		return (left > right ? left + 1 : right + 1);
	}
	//求第K层的节点个数：
	size_t get_k(size_t k) {
		return _get_k(root, k);
	}
	size_t _get_k(node * root, size_t k) {
		if (root == NULL)
			return 0;
		//第K层 每个root代表一个节点个数
		if (k == 1)
			return 1;
		//注意这里为什么是k-1?  如果你需要求第二层的节点个数，则需要用第一层的根节点访问他的左子树和右子树的第一层的个数
		return _get_k(root->left, k - 1) + _get_k(root->right, k - 1);
	}
	//层序遍历
	void level_order() {
		queue<node*> q;
		if (root != NULL)
			q.push(root);
		while (!q.empty()) {
			node * front = q.front();
			cout << front->val << " ";
			q.pop();
			if (front->left)
				q.push(front->left);
			if (front->right)
				q.push(front->right);
		}
		cout << endl;
	}
	//判断二叉树是否为完全二叉树
	bool is_complete_tree() {
		queue<node*> q;
		if (root)
			q.push(root);
		bool flag = true;
		while (!q.empty())
		{
			node * front = q.front();
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
	//查找一个节点是否在一棵二叉树中
	node * find(const T & x) {
		return _find(root, x);
	}
	node* _find(node* root, const T & x) {
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
void test() {
	int array[] = { 1, 2, 3, '#', '#', 4, 40, '#', '#', '#', 5, 6, '#', '#', '#' };
	binary_tree<int> t(array, sizeof(array) / sizeof(int), '#');
	t.prev();
	t.prev_order_no_r();
	t.in();
	t.in_order_no_r();
	t.post_order_no_r();
	t.level_order();
	cout << "size:" << t.size() << endl;
	cout << "leaf_size:" << t.leaf_size() << endl;
	cout << "height:" << t.height() << endl;
	cout << "is_complete_tree:" << t.is_complete_tree() << endl;
	cout << "k_level_size:" << t.get_k(4)<< endl;
	binary_tree<int> ba(t);
	ba.prev_order_no_r();
}

int main()
{
	test();
	system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
