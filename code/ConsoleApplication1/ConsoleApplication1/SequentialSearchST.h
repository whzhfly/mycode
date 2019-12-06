#include "pch.h"
#define SORTALGORITHM_SEQUENTIAL_SEARCHST_H
#define SORTALGORITHM_SEQUENTIAL_SEARCHST_H
#include <vector>
#include <iostream>

using namespace std;
template <typename Key, typename Value>

class SequentialSearchST 
	// 定义一个内部节点类
{
private:
	class Node {
	public: 
		Key key;
		Value value;
		Node * next;
	public:
		Node(Key key, Value value,Node * next){
			this->key = key;
			this->value = value;
			this->next = next;
		}
	};
	// 链表的头指针
	Node * first;
	int n;
public:
	Value * get(Key key) {
		// 为了表示没有查找到，只能返回一个值的指针。
		for(Node node=first;node!=NULL;node=node->next)
			if (node->key == key) {
				return &(node->value);
			}
		return nullptr;
	}
	void put(Key key, Value value) {
		// 遍历节点，如果存在key，则覆盖value，否则新增一个节点。
		for (Node node = first; node != NULL; node = node->next)
			if (node->key == key) {
				node->value = value;
				return;
			}
		// 如果找不到节点，更新头结点
		first = new Node(key, value, first);
		n++;
		return;
	}
	int size()
	{
		return n;
	}
    // 从开始删除某个节点
	void delete_element(Key key) {
		if (first->key == key)
		{
			// 保存新的头指针
			Node * head = first->next;
			delete first;
			first = head;
			n--;
			return;
		}
		// 遍历链表
		Node * p = first;
		Node * q = first->next;
		while (q != NULL) {
			if (q->key == key)
			{
				p->next = q->next;
				delete q;
				q=p->next;
				n--;
				return;
			}
			p = p->next;
			q = q->next;
		}
		std::cout << "The key isn't in the ST." << endl;
		return;		
	}
    // 利用查找函数
	bool contains(Key key) {
		return get(key) != NULL;
	}
	// 返回一个关键字的集合
	vector<Key> keys() {
		vector<Key> all_key;
		for (Node * p = first; p != NULL; p = p->next)
			all_key.push_back(p->key);
		return all_key;
	}
	bool is_empty() {
		return first == nullptr;
	}
	// 构造函数
	SequentialSearchST() :n(0), first(nullptr) {
		
	}
	~SequentialSearchST() {
		for (Node * node = first; node != NULL;)
		{
			Node* to_delete = node;
			node = node->next;
			delete to_delete;
		}
	}
};
