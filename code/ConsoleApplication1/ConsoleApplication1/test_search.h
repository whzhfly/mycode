#include "pch.h"
#define SORTALGORITHM_TEST_SEARCH_H
#include "Binary_SearchST.h"
#include "SequentialSearchST.h"
#include <string>
#include <fstream>
#include <memory>

using namespace std;

// �򵥲���һ�»�����������ķ��ű�
/*void test_sqequential_search_ST(string file_name) {
	// ����ֻ��ָ��Ƚϰ�ȫ
	auto st = make_shared<SequentialSearchST<string, int>>();
	// SequentialSearchST<string, int>* st = new SequentialSearchST<string, int>();
	ifstream input(file_name);
	int count = 0;
	string input_char;
	while (input >> input_char) {
		st->put(input_char, count);
		count++;
	}
	cout << "The original ST:" << st->size() << endl;
	for (auto node : st->keys()) {
		cout << node << " " << *(st->get(node)) << endl;
	}
	// ����ɾ������
	st->delete_element("L");
	st->delete_element("H");
	cout << "Delete key \"L\" and \"H\": " << st->size() << endl;
	for (auto node : st->keys()) {
		cout << node << " " << *(st->get(node)) << endl;
	}
	cout << "Is St contains \"X\":" << st->contains("X") << endl;
	cout << "Is ST empty?" << st->is_empty() << endl;
	// delete st;
}*/

// �򵥲���һ�»�����������ķ��ű������ǲ����˶��ֲ��ҷ���
/*void test_binary_searchST(string file_name) {
	auto st = make_shared<Binary_SearchST<string, int> >();
	ifstream input(file_name);
	int count = 0;
	string input_string;
	while (input >> input_string) {
		st->put(input_string, count);
		count++;
	}

	// �������ű�Ӧ��������ġ�
	for (string key : st->all_keys()) {
		cout << key << " " << *(st->get(key)) << endl;
	}
}
// �÷��ű�ͳ�Ƶ��ʳ��ִ����Ĳ��Գ���
/*void Frequency_Counter(string input_min_len, string filename) {
	// �ļ�������
	ifstream input(filename);
	int min_len = stoi(input_min_len);
	SequentialSearchST<string, int> ST;
	// ���ļ����ж�ȡ���еĵ��ʣ�ֱ���ļ���ĩβ��
	string word;
	while (input >> word) {
		if (word.size() < min_len) {
			continue;
		}
		// �����㷨�ǳ���ʱ����ΪҪ��������
		if (ST.contains(word)) {
			ST.put(word, (*ST.get(word)) + 1);
		}
		else {
			ST.put(word, 1);
		}
	}
	// �ҵ�����Ƶ�����ĵ���
	string max = " ";
	ST.put(max, 0);
	for (auto key : ST.keys()) {
		if (*(ST.get(key)) > *(ST.get(max))) {
			max = key;
		}

	}
	cout << "The most frequency word is " << max << " and it appends " << *(ST.get(max)) << " times!" << endl;
}*/
