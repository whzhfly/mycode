#include "pch.h"
#define SORTALGORITHM_SEQUENTIAL_SEARCHST_H
#define SORTALGORITHM_SEQUENTIAL_SEARCHST_H
#include <vector>
#include <iostream>

using namespace std;
template <typename Key, typename Value>

class SequentialSearchST 
	// ����һ���ڲ��ڵ���
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
	// �����ͷָ��
	Node * first;
	int n;
public:
	Value * get(Key key) {
		// Ϊ�˱�ʾû�в��ҵ���ֻ�ܷ���һ��ֵ��ָ�롣
		for(Node node=first;node!=NULL;node=node->next)
			if (node->key == key) {
				return &(node->value);
			}
		return nullptr;
	}
	void put(Key key, Value value) {
		// �����ڵ㣬�������key���򸲸�value����������һ���ڵ㡣
		for (Node node = first; node != NULL; node = node->next)
			if (node->key == key) {
				node->value = value;
				return;
			}
		// ����Ҳ����ڵ㣬����ͷ���
		first = new Node(key, value, first);
		n++;
		return;
	}
	int size()
	{
		return n;
	}
    // �ӿ�ʼɾ��ĳ���ڵ�
	void delete_element(Key key) {
		if (first->key == key)
		{
			// �����µ�ͷָ��
			Node * head = first->next;
			delete first;
			first = head;
			n--;
			return;
		}
		// ��������
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
    // ���ò��Һ���
	bool contains(Key key) {
		return get(key) != NULL;
	}
	// ����һ���ؼ��ֵļ���
	vector<Key> keys() {
		vector<Key> all_key;
		for (Node * p = first; p != NULL; p = p->next)
			all_key.push_back(p->key);
		return all_key;
	}
	bool is_empty() {
		return first == nullptr;
	}
	// ���캯��
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
