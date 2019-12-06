﻿// alibaba.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <algorithm>
#include <stdint.h>
#include<string>
using namespace std;

struct LinkNode
{
	uint64_t key;
	uint64_t value;
	LinkNode* next = NULL;
};

struct SkipLinkNode
{
	uint64_t key;
	int count;
	LinkNode* pointer = NULL;
	SkipLinkNode* next = NULL;
};

class SkipLinkList
{
public:
	SkipLinkList(int skipStep = 128);
	~SkipLinkList();
	bool simpleCheck();

public:
	void insert(uint64_t key, uint64_t value);
	bool find(uint64_t key, uint64_t& value);

private:
	LinkNode* _listHeader = NULL;
	SkipLinkNode* _skipListHeader = NULL;
	int _skipStep;
	int _itemCount;
};

SkipLinkList::SkipLinkList(int skipStep)
	: _skipStep(skipStep)
	, _listHeader(NULL)
	, _skipListHeader(NULL)
	, _itemCount(0)
{}


SkipLinkList::~SkipLinkList()
{
	LinkNode* node = _listHeader;
	while (node != NULL) {
		LinkNode* toDelNode = node;
		node = node->next;
		delete toDelNode;
	}

	SkipLinkNode* skipNode = _skipListHeader;
	while (skipNode != NULL) {
		SkipLinkNode* toDelNode = skipNode;
		skipNode = skipNode->next;
		delete toDelNode;
	}
}

bool SkipLinkList::simpleCheck()
{
	uint64_t lastKey = 0;
	int nodeCount = 0;
	LinkNode* node = _listHeader;
	while (node != NULL)
	{
		nodeCount++;
		if (node->key < lastKey)
		{
			return false;
		}
		lastKey = node->key;
		node = node->next;
	}
	if (nodeCount < _skipStep)
	{
		return (_skipListHeader == NULL);
	}

	lastKey = 0;
	int skipNodeCount = 0;
	int expectNodeCount = 0;
	SkipLinkNode* skipNode = _skipListHeader;
	while (skipNode != NULL)
	{
		skipNodeCount++;
		if (skipNode->key < lastKey)
		{
			return false;
		}
		lastKey = skipNode->key;
		expectNodeCount += skipNode->count;
		skipNode = skipNode->next;
	}
	return nodeCount == expectNodeCount &&
		skipNodeCount >= ((nodeCount + _skipStep - 1) / _skipStep);
}

/** 请完成下面这个函数，实现题目要求的功能 **/
void SkipLinkList::insert(uint64_t key, uint64_t value)
{
	// TODO:
	SkipLinkList* sklist=new SkipLinkList(_skipStep);
	int cnt = key / sklist->_skipStep;
	SkipLinkNode* head = sklist->_skipListHeader;
	while (cnt--)
	{
		head = head->next;
	}
	int cnt2 = key % sklist->_skipStep;
	cnt2--;
	LinkNode * head2 = head->pointer;
	while (cnt2--)
	{
		head2 = head2->next;
	}
	head2->value = value;
}

bool SkipLinkList::find(uint64_t key, uint64_t& value)
{
	// TODO:
	SkipLinkList* sklist = new SkipLinkList(_skipStep);
	int cnt = key / sklist->_skipStep;
	SkipLinkNode* head = sklist->_skipListHeader;
	while (cnt--)
	{
		head = head->next;
	}
	int cnt2 = key % sklist->_skipStep;
	cnt2--;
	LinkNode* head2 = head->pointer;
	while (cnt2--)
	{
		head2 = head2->next;
	}
	if(head2->value != value)
		return false;
	else
	{
		return true;
	}
}

/** 请完成上面的函数，实现题目要求的功能 **/

vector<string> splitString(const string& text, const string& sepStr) {
	vector<string> vec;
	string str(text);
	string sep(sepStr);
	size_t n = 0, old = 0;
	while (n != string::npos)
	{
		n = str.find(sep, n);
		if (n != string::npos)
		{
			vec.push_back(str.substr(old, n - old));
			n += sep.length();
			old = n;
		}
	}
	vec.push_back(str.substr(old, str.length() - old));
	return vec;
}
template <typename T>
bool stringToInteger(const string& text, T& value) {
	const char* str = text.c_str();
	char* endPtr = NULL;
	value = (T)strtol(str, &endPtr, 10);
	return (endPtr && *endPtr == 0);
}


bool testSkipLinkList(string inputParam) {
	vector<string> inputVec = splitString(inputParam, ":");
	if (inputVec.size() != 2 || (inputVec[0] != "list" && inputVec[0] != "count"))
	{
		cout << "input format error!" << endl;
		return false;
	}
	// prepare data
	vector<pair<uint64_t, uint64_t> > keyValueVec;
	if (inputVec[0] == "list") {
		vector<string> kvVec = splitString(inputVec[1], ";");
		for (size_t i = 0; i < kvVec.size(); i++) {
			vector<string> kvStr = splitString(kvVec[i], ",");
			uint64_t key, value;
			if (kvStr.size() != 2 ||
				!stringToInteger<uint64_t>(kvStr[0], key) ||
				!stringToInteger<uint64_t>(kvStr[1], value))
			{
				cout << "key-value list format error!" << endl;
				return false;
			}
			keyValueVec.push_back(make_pair(key, value));
		}
	}

	if (inputVec[0] == "count") {
		uint64_t count;
		if (!stringToInteger<uint64_t>(inputVec[1], count)) {
			cout << "count format error!" << endl;
			return false;
		}
		for (uint64_t i = 0; i < count; i++) {
			keyValueVec.push_back(make_pair(i, i));
		}
		random_shuffle(keyValueVec.begin(), keyValueVec.end());
	}

	uint64_t maxKey = 0;
	uint64_t value;

	SkipLinkList list(4);
	for (size_t i = 0; i < keyValueVec.size(); i++)
	{
		list.insert(keyValueVec[i].first, keyValueVec[i].second);

		// test find
		bool ret = list.find(keyValueVec[i].first, value);
		if (!ret || value != keyValueVec[i].second)
		{
			cout << "test find error!" << endl;
			return false;
		}
		// test replace
		list.insert(keyValueVec[i].first, keyValueVec[i].second + 1);
		ret = list.find(keyValueVec[i].first, value);
		if (!ret || value != keyValueVec[i].second + 1)
		{
			cout << "test replace error!" << endl;
			return false;
		}
		maxKey = max(maxKey, keyValueVec[i].first);
	}

	// test not exist key
	if (list.find(maxKey + 1, value))
	{
		cout << "find not exist error!" << endl;
		return false;
	}
	return list.simpleCheck();
}

int main() {
	bool res;
	string _inputParam;
	getline(cin, _inputParam);
	res = testSkipLinkList(_inputParam);
	if (res)
	{
		cout << "PASS" << endl;
	}
	else
	{
		cout << "FAIL" << endl;
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
