#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
#include<map>
#include<queue>
#include"BinaryTree.h"

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
}; 
//二叉树镜像
class Solution_Mir {
public:
	void Mirror(TreeNode* pRoot) {
		if (pRoot == NULL)
			return;
		TreeNode* tmp = pRoot->right;
		pRoot->right = pRoot->left;
		pRoot->left = tmp;
		Mirror(pRoot->left);
		Mirror(pRoot->right);

	}
};

//从上往下打印出二叉树的每个节点，同层节点从左至右打印。
class Solution_PrintTTB {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		if (root == NULL)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		int index = q.size();
		while (!q.empty()) {
			TreeNode* tmp = q.front();
			res.push_back(tmp->val);
			q.pop();
			if (tmp->left)
				q.push(tmp->left);
			if (tmp->right)
				q.push(tmp->right);
		}
		return res;
	}
};

//输入一个整数数组，判断该数组是不是某二叉搜索树(有序的)的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

class Solution_VerOfBST {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		int len = sequence.size();
		if (len == 0)
			return false;
		return helper(sequence, 0, len - 1);
	}
	bool helper(vector<int>& sequence, int i, int j) {
		if (i >= j)
			return true;
		int max = sequence[j];
		int k = i;
		while (sequence[k] < max) {
			k++;
		}
		for (int t = k; t < j; t++) {
			if (sequence[t] < max)
				return false;
		}
		return helper(sequence, i, k - 1) && helper(sequence, k, j - 1);
	}
};

//二叉树和为某一路径 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
class Solution_FindP {
public:
	vector<vector<int> > buffer;
	vector<int> tmp;
	void helper(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return;
		tmp.push_back(root->val);
		if (expectNumber - root->val == 0 && root->left == NULL && root->right == NULL)
			buffer.push_back(tmp);
		helper(root->left, expectNumber - root->val);
		helper(root->right, expectNumber - root->val);
		if (tmp.size() != 0)
			tmp.pop_back();
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		if (root == NULL)
			return buffer;
		helper(root, expectNumber);
		return buffer;
	}
};

//二叉树和双向链表  输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
//模仿中序便利 123456 记录pre ,cur的left就是pre， pre 的right 就是cur
class Solution_Con{
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		TreeNode* tmp = NULL;
		helper(pRootOfTree, tmp);
		TreeNode* res = pRootOfTree;
		while (res->left)
			res = res->left;
		return res;
	}
	void helper(TreeNode* root, TreeNode*& pre) {
		if (root == NULL)
			return;
		helper(root->left, pre);
		root->left = pre;
		if (pre)
			pre->right = root;
		pre = root;
		helper(root->right, pre);
	}
};

//二叉树的深度
class Solution_Dep {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		return tree(pRoot, 0);
	}
	int tree(TreeNode* pRoot, int dep)
	{
		if (pRoot == NULL)
			return dep;
		dep++;
		int a = tree(pRoot->left, dep);
		int b = tree(pRoot->right, dep);
		return ((a > b) ? a : b);
	}
};

//是否平衡二叉树
class Solution_iSbAL {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {

		return getDepth(pRoot) != -1;
	}
	int getDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int left = getDepth(pRoot->left);
		if (left == -1) return -1;
		int right = getDepth(pRoot->right);
		if (right == -1) return -1;
		int d = abs(left - right);
		return ((d > 1) ? -1 : 1 + max(left, right));
	}
};

//从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
class Solution_P {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > res;
		if (pRoot == NULL) return res;
		queue<TreeNode*> qu;
		qu.push(pRoot);
		while (!qu.empty())
		{
			int low = 0, high = qu.size();
			vector<int> tmp;
			while (low++ < high) {
				TreeNode* p = qu.front();
				qu.pop();
				tmp.push_back(p->val);
				if (p->left)
					qu.push(p->left);
				if (p->right)
					qu.push(p->right);
			}
			res.push_back(tmp);
		}
		return res;
	}

};

//请实现两个函数，分别用来序列化和反序列化二叉树
//二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，从而使得内存中建立起来的二叉树可以持久保存。
//序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。
//二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
class Solution_t {
public:
	vector<int> buf;
	void dfs1(TreeNode* root)
	{
		if (root)
		{
			buf.push_back(root->val);
			dfs1(root->left);
			dfs1(root->right);
		}
		else buf.push_back(0xFFFFFFFF);
	}
	TreeNode* dfs2(int*& p)
	{
		if (*p == 0xFFFFFFFF)
		{
			p++;
			return NULL;
		}
		TreeNode* res = new TreeNode(*p);
		p++;
		res->left = dfs2(p);
		res->right = dfs2(p);
		return res;
	}
	char* Serialize(TreeNode* root) {
		buf.clear();
		dfs1(root);
		int len = buf.size();
		int* res = new int[len];
		for (int i = 0; i < len; i++)
			res[i] = buf[i];
		return (char*)res;
	}
	TreeNode* Deserialize(char* str) {
		int* p = (int*)str;
		return dfs2(p);
	}
};

// 第K个节点 给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4
class Solution_k {
public:
	int count = 0;
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot != NULL)
		{
			TreeNode* node = KthNode(pRoot->left, k);
			if (node != NULL)
				return node;
			count++;
			if (k == count)
				return pRoot;
			node = KthNode(pRoot->right, k);
			if (node != NULL)
				return node;
		}
		return NULL;
	}
};

//重建二叉树
//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{ 1,2,4,7,3,5,6,8 }和中序遍历序列{ 4,7,2,1,5,3,8,6 }，则重建二叉树并返回。
class Solution_Re {
public:
	TreeNode* helper(vector<int> pre, vector<int> vin, int prestr, int preend, int vinstr, int vinend) {
		if (prestr > preend || vinstr > vinend)
			return NULL;
		TreeNode* head = new TreeNode(pre[prestr]);
		int tmp = vinstr;
		int cnt = 0;
		while (pre[prestr] != vin[tmp]) {
			tmp++;
			cnt++;
		}
		head->left = helper(pre, vin, prestr + 1, prestr + cnt + 1 - 1, vinstr, tmp - 1);
		head->right = helper(pre, vin, prestr + cnt + 1, preend, tmp + 1, vinend);
		return head;
	}
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int prestr = 0;
		int preend = pre.size();
		int vinstr = 0;
		int vinend = vin.size();
		return helper(pre, vin, prestr, preend - 1, vinstr, vinend - 1);

	}
};

//二叉树中最远两个节点的距离
struct node
{
	node* pLeft;
	node* pRight;
	int nMaxLeft;
	int nMaxRight;
};

int nMaxLen = 0;

void FindMaxLen(node* root)
{
	if (root == NULL)    return;

	if (root->pLeft == NULL)
		root->nMaxLeft = 0;

	if (root->pRight == NULL)
		root->pRight = 0;

	if (root->pLeft != NULL)
	{
		FindMaxLen(root->pLeft);
	}

	if (root->pRight != NULL)
	{
		FindMaxLen(root->pRight);
	}

	if (root->pLeft != NULL)  //左子树最大距离
	{
		int nTempMax = 0;
		if (root->pLeft->nMaxLeft > root->pLeft->nMaxRight)
			nTempMax = root->pLeft->nMaxLeft;
		else
			nTempMax = root->pLeft->nMaxRight;
		root->nMaxLeft = nTempMax + 1;
	}

	if (root->pRight != NULL)  //右子树最大距离
	{
		int nTempMax = 0;
		if (root->pRight->nMaxLeft > root->pRight->nMaxRight)
			nTempMax = root->pRight->nMaxLeft;
		else
			nTempMax = root->pRight->nMaxRight;
		root->nMaxRight = nTempMax + 1;
	}

	if (root->nMaxLeft + root->nMaxRight > nMaxLen)  //更新最大距离 
		nMaxLen = root->nMaxLeft + root->nMaxRight;
}

//二叉树公共祖先
TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
	if (!root || root == p || root == q)
		return root;
	TreeNode left = lowestCommonAncestor(root.left, p, q);
	TreeNode right = lowestCommonAncestor(root.right, p, q);
	if (left && right)
		return root;
	if (!left)
		return right;
	if (!right)
		return left;
}

#pragma once
