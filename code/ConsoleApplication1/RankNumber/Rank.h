#include "pch.h"
#include <iostream>
#include<queue>
#include<vector>
#define MAXLENGTHSORT 7
#define MAXSIZE 20
using namespace std;

void Show(vector<int> a) {
	if (a.size() < 1)
		return;
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}
void SelectSort(vector<int> &a) {//ѡ������ ð���Ǳ���С�ͻ� ��ѡ�����ȼ�¼�±� �ҵ���С�ٻ�   ʱ�临�Ӷ�n^2
	int len = a.size();
	if (a.size() < 1)
		return;
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (a[min] > a[j])
				min = j;
		}
		if (min != i)
			swap(a[i], a[min]);
	}
}
void InsertSort(vector<int> &a) {   // �������� ʱ�临�Ӷ�(n^2)/4  
	int i, j;
	int index;
	for (i = 1; i < a.size(); i++)
	{
		if (a[i] < a[i - 1])//��Ҫ����
		{
			index= a[i];//�����ڱ�
			for (j = i - 1; a[j] > index&&j>=0; j--)
				a[j + 1] = a[j];//��¼���ƶ� 
			a[j + 1] = index;
		}
	}
} 
void ShellSort(vector<int> &a)  //ϣ������   ���ڲ�������  ��ͬ�����и�lenֵ �ȷ���  swap��Ϊ���lenֵ�ĵ� �������һ��ĵ�i��ֵ��С��ÿ��iֵ�� ���һ�����
{
	int i, j;
	int len = a.size();
	do {
		len = len / 3 + 1;
		for (int i = len; i < a.size(); i++) {
			if (a[i] < a[i - len])
			{
				int index = a[i];//����ֵ
				for (j = i - len; j > 0 && index < a[j]; j -= len)
					a[j + len] = a[j];
				a[j + len] = index;
			}
		}

	}while (len>1);
}

void Merge(vector<int> &a, int i, int m, int n) {//��a[i..m]��a[m+1...n]�鲢�������a
	int j, k, l;
    vector<int> b(a);
	for (j = m + 1, k = i; i <= m && j <= n; k++)  //i-m j-n
	{
		if (b[i] < b[j])
			a[k] = b[i++];//kֵ����a��ָ��
		else
			a[k] = b[j++];
	}
	if (i <=m)//ʣ��b[i...m]
	{
		while (i <= m)
		{
			a[k++] = b[i++];
		}
	}//Ϊʲô���ֲ���
	/*if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
			a[k + l] = b[i + l];
	}*/
	if (j <=n)//ʣ��b[j...n]
	{
		while (j <= m)
		{
			a[k++] = b[i++];
		}
	}
	/*if (j <= n)
	{
		for (l = 0; l <= n - j; l++)
			a[k + l] = b[j + l];
	}*/
}
void MSort(vector<int> &a,  int s, int t) {//��a[s..t]�鲢��b[s...t]
	if(s<t)
	{
		int m = (s + t) / 2; //��a[s..t]��Ϊ[s...m]  [m+1....t]
		MSort(a, s, m);
		MSort(a, m + 1, t);
		Merge(a ,s, m, t);//��c�鲢��b��
	}
}
void MergeSort(vector<int> &a) {//�ݹ�ʽ�������Ϲ鲢
	int n = a.size() - 1;
	MSort(a, 0, n);
}
void MergeSortUptoDown(vector<int> &a) {//���ϵ��¹鲢  ���ںϲ�
	int N = a.size();
	for (int size = 1; size < N; size *= 2) //�����ɱ����� 
		for (int lo = 0; lo < N - size;lo+=size+size)//�����ϲ� 
			Merge(a,lo,lo+size-1,min(lo+size+size-1,N-1));//ʹ��min,��ֹ�ұ߽�Խ�� 
}
int Partition(vector<int> &a, int lo, int high)
{//�������з�Ϊa[lo..p-1] a[p] a[p+1..high]
	int p;
	p = a[lo];
	while (lo < high) { //���������м�ɨ��
		while (lo < high&&a[high] >= p)
			high--;
		swap(a[lo], a[high]);
		while (lo < high&&a[lo] <= p)
			lo++;
		swap(a[lo], a[high]);
	}
	return lo;
}
int Partition2(vector<int> &a, int lo, int high)//�Ż�
{//�������з�Ϊa[lo..p-1] a[p] a[p+1..high]
	int p;
	p = a[lo];
	while (lo < high) { //���������м�ɨ��
		while (lo < high&&a[high] >= p)
			high--;
		a[lo] = a[high];//swap(a[lo], a[high]);
		while (lo < high&&a[lo] <= p)
			lo++;
		a[high] = a[lo];//swap(a[lo], a[high]);
	}
	a[lo] = p;
	return lo;
}

void QSort(vector<int> &a, int lo, int high)
{
	int p;
	if (lo >= high)
		return;
	p = Partition2(a,lo,high);
	QSort(a, lo, p - 1);
	QSort(a, p+1,high);
}
void QSort1(vector<int> &a, int lo, int high)//youhua
{
	int p;
	if ((high - lo) > MAXLENGTHSORT) {
		while (lo < high) {
			p = Partition2(a, lo, high);
			QSort1(a, lo, p - 1);
			lo = p + 1;//β�ݹ�
		}
	}
	else
		InsertSort(a);
}
void QuickSort(vector<int> &a) {
	QSort(a,0,a.size()-1);
}
void HeapAdjust(vector<int> &a, int s, int m) {//��С���� �󶥶�
	int tmp, j;
	tmp = a[s];
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m&&a[j] < a[j + 1])
			++j;
		if (tmp >= a[j])
			break;
		a[s] = a[j];
		s = j;
	}
	a[s] = tmp;
}
void HeapAdjust2(vector<int> &a, int s, int m) {//�Ӵ�С //С����
	int tmp, j;
	tmp = a[s];
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m&&a[j] >a[j + 1])
			++j;
		if (tmp <= a[j])
			break;
		a[s] = a[j];
		s = j;
	}
	a[s] = tmp;
}
void HeapSort(vector<int> &a) {
	int i;
	for (i = (a.size()-1) / 2; i >= 0; i--)
		HeapAdjust(a, i, a.size()-1);//���ɴ󶥶�
	for (i = a.size()-1; i > 0; i--)//���󶥶�����  ����ת�� 
	{
		swap(a[0], a[i]);
		HeapAdjust(a, 0, i - 1);
	}
}



