#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<deque>
using namespace std;

struct BTreeNode
{
	int value;
	char key;
    BTreeNode* left;
    BTreeNode* right;
};

BTreeNode* CreatHuffman(vector<int> &value,vector<char> & key,int n) {
	
}
class huffman {
private:
	int huffmanCodeing(BTreeNode * root,int len) {
		if (root != NULL)
		{
			if (root->left == NULL && root->right == NULL)
				return root->value * len;  
			else
			{
				return huffmanCodeing(root->left, len + 1) + huffmanCodeing(root->right, len + 1);//每一层01的个数加一
			}
		}

	}
	int getMinCode(string s) {
		map<char, int> m;
		int len = s.size();
		for (int i = 0; i < len; i++) {
			auto it = m.find(s[i]);
			if (it == m.end())
				m.insert(pair<char,int> (s[i],1));
			else
			{
				m[s[i]]++;
			}
		}

		//构建huffmantree
		int size = m.size();
		vector<int> value;
		vector<char> key;
		for (auto it = m.begin(); it != m.end(); it++) {
			key.push_back(it->first);
			value.push_back(it->second);
		}
		BTreeNode* root = CreatHuffman(value,key,size);
		return huffmanCodeing(root,0);
	}
public:
	void main() {
		string s;
		cin >> s;
		cout << getMinCode(s);
	}
};
#pragma once
