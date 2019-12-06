#include "pch.h"
#define SORTALGORITHM_SEQUENTIAL_SEARCHST_H
#define SORTALGORITHM_SEQUENTIAL_SEARCHST_H
#include <vector>
#include <iostream>

using namespace std;
template <typename Key, typename Value>
class Binary_SearchST {
private:
	// 数组长度经常发生变化，采用指针
	Key * keys;
	Value * values;
	// 一个记录数组长度， 一个记录字典长度.
	int n;
	int length;

	// 重要的函数,可以调整数组的大小
	void resize(int capacity) {
		if (capacity <= n)
			return;
		// 临时指针
		Key * tmp_keys = new Key[capacity];
		Value * tmp_values = new Value[capacity];
		for (int i = 0; i < n; i++)
		{
			tmp_keys[i] = keys[i];
			tmp_values[i] = values[i];
		}
		// 删除原来的空间
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
	// 构造函数
	explicit Binary_SearchST(int capacity = 10) :n(0), length(capacity) {
		keys = new Key[capacity];
		values = new Value[capacity];
	}
	// delete指针指向的数组
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
		// 有可能没找到，但是要返回位置。
		return low;
	}
	// 根据key查找value;
	Value* get(Key key) {
		if (is_empty())
			return nullptr;
		int i=rank(key);
		if (i < n&&key = keys[i])
			return & values[i];
		return nullptr;
	}
	// 是否包含某个键
	bool contains(Key key) {
		return get(key) != nullptr;
	}
	// 删除
	void delete_element(Key key) {
		if (is_empty())
			return;
		int i = rank(key);
		// key not in the table
		if (i == n)
			return;
		if (keys[i] != key) 
			return;
		// 后面的元素往前移动一位
		for (int j = i; j < n - 1; j++) {
			keys[j] = keys[j + 1];
			values[j] = values[j + 1];
		}
		n--;
		// 动态调整数组长度
		if ((n > 0) && (n == length / 4)) {
			resize(length / 2);
		}
	}
	// 插入元素, 比较麻烦，要整体移动数组的元素
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
	// 最大最小值, 没有检查为空的情况，存在运行错误。
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
	// 选择第k大的值
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
	// 返回一个容器装着keys
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
