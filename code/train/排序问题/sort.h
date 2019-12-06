#include <iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class sortqu {
public:
	void Show(vector<int> a) {
		if (a.size() < 1)
			return;
		for (int i = 0; i < a.size(); i++)
			cout << a[i] << " ";
		cout << endl;
	}
	//ѡ������ ð���Ǳ���С�ͻ� ��ѡ�����ȼ�¼�±� �ҵ���С�ٻ�   ʱ�临�Ӷ�n^2
	void SelectSort(vector<int>& a,int n) {
		if (n <= 0)
			return;
		for (int i = 0; i < n; i++) {
			int min = i;
			for (int j = i + 1; j < n; j++) {
				if (a[min] > a[j])
					min = j;
			}
			swap(a[i],a[min]);
		}
	}

	//c�������� ���ƴ���  ʱ�临�Ӷ�(n^2)/4  
	void InsertSort(vector<int>& a,int n) {
		if (n <= 0)
			return;
		int i,j,tmp;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1])//��Ҫ����
			{
				tmp = a[i];//�����ڱ�
				for (j = i - 1; a[j] > tmp && j >= 0; j--)
					a[j + 1] = a[j];//��¼���ƶ� 
				a[j + 1] = tmp;
			}
		}
	}

	//ϣ������  ���ڲ������� ��ͬ�����и�lenֵ �ȷ���
	//swap��Ϊ���lenֵ�ĵ� �������һ��ĵ�i��ֵ��С��ÿ��iֵ�� ���һ�����
	void ShellSort(vector<int>& a, int n) {
		int i, j;
		int len;
		do {
			len= len / 3 + 1;
			for (int i = len; i < n; i++) {
				if (a[i] < a[i - len]) {
					int tmp = a[i];
					for (int j = i - len; j > 0 && tmp < a[j]; j -= len) {
						a[j + len] = a[j];
					}
					a[j + len] = tmp;
				}
			}
		} while (len > 1);
	}

	//��������
	int  Parttion(vector<int>& a, int lo, int high) {
		int tmp = a[lo];
		while (lo<high)
		{
			while (lo<high&&a[high]>=tmp)
			{
				high--;
			}
			a[lo] = a[high];
			while (lo<high&&a[lo]<=tmp)
			{
				lo++;
			}
			a[high] = a[lo];
		}
		a[lo] = tmp;
		return lo;
	}
	void Qsort(vector<int> &a,int lo,int high) {
		int mid;
		if (lo >= high)
			return;
		mid = Parttion(a,lo,high);
		Qsort(a, lo, mid - 1);
		Qsort(a, mid + 1, high);
	}
	void QuickSort(vector<int>& a, int n) {
		Qsort(a,0,n-1);
	}

	//�鲢����
	//��a[i..m]��a[m+1...n]�鲢�������a
	void Merge(vector<int> &a ,int i,int m,int n) {
		int j, k, l;
		vector<int> b(a);
		for (j = m + 1, k = i; i <= m && j <= n; k++) {
			if (b[i] < b[j])
				a[k] = b[i++];
			else
			{
				a[k] = b[j++];
			}
		}
		if (i <= m) {
			while (i<=m)
			{
				a[k++] = b[i++];
			}
		}
		if (j <= n) {
			while (j<=n)
			{
				a[k++] = b[j++];
			}
		}
	}
	//��a[s..t]�鲢��b[s...t]
	void Msort(vector<int> & a,int s,int t) {
		if (s < t) {
			int mid = (s + t) / 2;
			Msort(a, s, mid);
			Msort(a, mid + 1, t);
			Merge(a,s,mid,t);
		}
	}
	void MergeSort(vector<int>& a, int n) {
		Msort(a, 0, n - 1);
	}
	//���ϵ��¹鲢  ���ںϲ�
	void MergeSortUptoDown(vector<int>& a) {
		int N = a.size();
		for (int size = 1; size < N; size *= 2) //�����ɱ����� 
			for (int lo = 0; lo < N - size; lo += size + size)//�����ϲ� 
				Merge(a, lo, lo + size - 1, min(lo + size + size - 1, N - 1));//ʹ��min,��ֹ�ұ߽�Խ�� 
	}

	//������  //��С���� �󶥶�
	void HeadAdjust(vector<int>& a,int s,int m) {
		int tmp, j;
		tmp = a[s];
		for (int j = 2 * s; j <= m; j *= 2) {
			if (j < m && a[j] < a[j + 1])  //����ȡ��
				++j;
			if (tmp >= a[j])   //����Ҳȡ��
				break;
			a[s] = a[j];
			s = j;
		}
		a[s] = tmp;
	}
	void HeapSort(vector<int>& a, int  n) {
		int i;
		// ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
		for (int i = (n - 1) / 2; i >= 0; i--) 
			HeadAdjust(a, i, n - 1);
		// ���������
		for (int i = n - 1; i > 0; i--) {
			swap(a[0],a[i]);
			HeadAdjust(a, 0, i - 1);
		}
	}
};
#pragma once
