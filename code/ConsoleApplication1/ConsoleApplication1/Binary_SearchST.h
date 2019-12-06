#include "pch.h"
#define SORTALGORITHM_SEQUENTIAL_SEARCHST_H
#define SORTALGORITHM_SEQUENTIAL_SEARCHST_H
#include <vector>
#include <iostream>

using namespace std;
template <typename Key, typename Value>
class Binary_SearchST {
private:
	// ���鳤�Ⱦ��������仯������ָ��
	Key * keys;
	Value * values;
	// һ����¼���鳤�ȣ� һ����¼�ֵ䳤��.
	int n;
	int length;

	// ��Ҫ�ĺ���,���Ե�������Ĵ�С
	void resize(int capacity) {
		if (capacity <= n)
			return;
		// ��ʱָ��
		Key * tmp_keys = new Key[capacity];
		Value * tmp_values = new Value[capacity];
		for (int i = 0; i < n; i++)
		{
			tmp_keys[i] = keys[i];
			tmp_values[i] = values[i];
		}
		// ɾ��ԭ���Ŀռ�
		delete [] keys;
		delete [] values;
		keys = tmp_keys;
		values = tmp_values;
		tmp_keys = nullptr;
		tmp_values = nullptr;
		length = capacity;
		return;
	}
public:
	// ���캯��
	explicit Binary_SearchST(int capacity = 10) :n(0), length(capacity) {
		keys = new Key[capacity];
		values = new Value[capacity];
	}
	// deleteָ��ָ�������
	Binary_SearchST(){
		delete [] keys;
		delete [] values;
	}
	int size()
	{
		return n;
	}
	bool is_empty()
	{
		return n == 0;
	}
	int rank(Key keys) {
		int low = 0;
		int high = n - 1;
		while (low<=high)
		{
			int mid = (low + high) / 2;
			if (keys < keys[mid])
				high = mid - 1;
			else if (keys > keys[mid])
			{
				low = mid + 1;
			}
			else
				return mid;
		}
		// �п���û�ҵ�������Ҫ����λ�á�
		return low;
	}
	// ����key����value;
	Value* get(Key key) {
		if (is_empty())
			return nullptr;
		int i=rank(key);
		if (i < n&&key = keys[i])
			return & values[i];
		return nullptr;
	}
	// �Ƿ����ĳ����
	bool contains(Key key) {
		return get(key) != nullptr;
	}
	// ɾ��
	void delete_element(Key key) {
		if (is_empty())
			return;
		int i = rank(key);
		// key not in the table
		if (i == n)
			return;
		if (keys[i] != key) 
			return;
		// �����Ԫ����ǰ�ƶ�һλ
		for (int j = i; j < n - 1; j++) {
			keys[j] = keys[j + 1];
			values[j] = values[j + 1];
		}
		n--;
		// ��̬�������鳤��
		if ((n > 0) && (n == length / 4)) {
			resize(length / 2);
		}
	}
	// ����Ԫ��, �Ƚ��鷳��Ҫ�����ƶ������Ԫ��
	void put(Key key, Value value) {
		int i = rank(key);
		//key in the table
		if (i < n&&keys[i] == key)
		{
			value[i] = value;
			return;
		}
		//key not in the table
		if (n == length)
			resize(2 * length);
		for (int j = n; j > i; j--)
		{
			keys[j] = keys[j - 1];
			value[j] = value[j - 1];
		}
		keys[i] = key;
		value[i] = value;
		n++;
	}
	// �����Сֵ, û�м��Ϊ�յ�������������д���
	Key min_key() {
		return keys[0];
	}
	Key max_key() {
		return keys[n - 1];
	}
	void delete_min() {
		delete_element(keys[0]);
	}
	void delete_max() {
		delete_element(max_key());
	}
	// ѡ���k���ֵ
	Key select(int k) {
		return keys[k];
	}
	Key floor(Key key) {
		int i = rank(key);
		if (i < n&&key == key[i])
			return key[i];
		if (i == 0)
			return keys[i];
		else return keys[i - 1];
	}
	Key ceiling(Key key) {
		int i = rank(key);
		return keys[i];
	}
	int size(Key lo, Key hi) {
		if (lo > hi)
			return 0;
		if (contains(hi))
			return rank(hi) - rank(lo) + 1;
		else
			return rank(hi) - rank(lo);
	}
	// ����һ������װ��keys
	std::vector<Key> all_keys(Key lo, Key hi) {
		std::vector<Key> keys_queue;
		if (lo > hi)
			return keys_queue;
		for (int i = rank(lo); i < rank(hi); i++)
			keys_queue.push_back(keys[i]);
		if (contains(hi)) 
			keys_queue.push_back(hi);
		return keys_queue;
	}
	std::vector<Key> all_keys() {
		return all_keys(min_key(), max_key());
	}
};
