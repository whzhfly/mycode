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
//����������
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

//�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
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

//����һ���������飬�жϸ������ǲ���ĳ����������(�����)�ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��

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

//��������Ϊĳһ·�� ·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
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

//��������˫������  ����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
//ģ��������� 123456 ��¼pre ,cur��left����pre�� pre ��right ����cur
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

//�����������
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

//�Ƿ�ƽ�������
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

//���ϵ��°����ӡ��������ͬһ����������������ÿһ�����һ�С�
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

//��ʵ�������������ֱ��������л��ͷ����л�������
//�����������л���ָ����һ�ö���������ĳ�ֱ�����ʽ�Ľ����ĳ�ָ�ʽ����Ϊ�ַ������Ӷ�ʹ���ڴ��н��������Ķ��������Գ־ñ��档
//���л����Ի����������򡢺��򡢲���Ķ�����������ʽ�������޸ģ����л��Ľ����һ���ַ��������л�ʱͨ�� ĳ�ַ��ű�ʾ�սڵ㣨#������ �� ��ʾһ�����ֵ�Ľ�����value!����
//�������ķ����л���ָ������ĳ�ֱ���˳��õ������л��ַ������str���ع���������
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

// ��K���ڵ� ����һ�ö��������������ҳ����еĵ�kС�Ľ�㡣���磬 ��5��3��7��2��4��6��8��    �У��������ֵ��С˳�����С����ֵΪ4
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

//�ؽ�������
//����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
//��������ǰ���������{ 1,2,4,7,3,5,6,8 }�������������{ 4,7,2,1,5,3,8,6 }�����ؽ������������ء�
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

//����������Զ�����ڵ�ľ���
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

	if (root->pLeft != NULL)  //������������
	{
		int nTempMax = 0;
		if (root->pLeft->nMaxLeft > root->pLeft->nMaxRight)
			nTempMax = root->pLeft->nMaxLeft;
		else
			nTempMax = root->pLeft->nMaxRight;
		root->nMaxLeft = nTempMax + 1;
	}

	if (root->pRight != NULL)  //������������
	{
		int nTempMax = 0;
		if (root->pRight->nMaxLeft > root->pRight->nMaxRight)
			nTempMax = root->pRight->nMaxLeft;
		else
			nTempMax = root->pRight->nMaxRight;
		root->nMaxRight = nTempMax + 1;
	}

	if (root->nMaxLeft + root->nMaxRight > nMaxLen)  //���������� 
		nMaxLen = root->nMaxLeft + root->nMaxRight;
}

//��������������
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
