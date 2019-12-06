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
void SelectSort(vector<int> &a) {//选择排序 冒泡是比他小就换 而选择是先记录下标 找到最小再换   时间复杂度n^2
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
void InsertSort(vector<int> &a) {   // 插入排序 时间复杂度(n^2)/4  
	int i, j;
	int index;
	for (i = 1; i < a.size(); i++)
	{
		if (a[i] < a[i - 1])//需要插入
		{
			index= a[i];//设置哨兵
			for (j = i - 1; a[j] > index&&j>=0; j--)
				a[j + 1] = a[j];//记录后移动 
			a[j + 1] = index;
		}
	}
} 
void ShellSort(vector<int> &a)  //希尔排序   基于插入排序  不同的是有个len值 先分组  swap的为间隔len值的点 结果：第一组的第i个值最小（每组i值） 最后一组最大
{
	int i, j;
	int len = a.size();
	do {
		len = len / 3 + 1;
		for (int i = len; i < a.size(); i++) {
			if (a[i] < a[i - len])
			{
				int index = a[i];//保存值
				for (j = i - len; j > 0 && index < a[j]; j -= len)
					a[j + len] = a[j];
				a[j + len] = index;
			}
		}

	}while (len>1);
}

void Merge(vector<int> &a, int i, int m, int n) {//把a[i..m]和a[m+1...n]归并成有序的a
	int j, k, l;
    vector<int> b(a);
	for (j = m + 1, k = i; i <= m && j <= n; k++)  //i-m j-n
	{
		if (b[i] < b[j])
			a[k] = b[i++];//k值得是a中指针
		else
			a[k] = b[j++];
	}
	if (i <=m)//剩下b[i...m]
	{
		while (i <= m)
		{
			a[k++] = b[i++];
		}
	}//为什么这种不行
	/*if (i <= m)
	{
		for (l = 0; l <= m - i; l++)
			a[k + l] = b[i + l];
	}*/
	if (j <=n)//剩下b[j...n]
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
void MSort(vector<int> &a,  int s, int t) {//把a[s..t]归并到b[s...t]
	if(s<t)
	{
		int m = (s + t) / 2; //把a[s..t]分为[s...m]  [m+1....t]
		MSort(a, s, m);
		MSort(a, m + 1, t);
		Merge(a ,s, m, t);//把c归并到b中
	}
}
void MergeSort(vector<int> &a) {//递归式从下往上归并
	int n = a.size() - 1;
	MSort(a, 0, n);
}
void MergeSortUptoDown(vector<int> &a) {//从上到下归并  相邻合并
	int N = a.size();
	for (int size = 1; size < N; size *= 2) //步长成倍递增 
		for (int lo = 0; lo < N - size;lo+=size+size)//两两合并 
			Merge(a,lo,lo+size-1,min(lo+size+size-1,N-1));//使用min,防止右边界越界 
}
int Partition(vector<int> &a, int lo, int high)
{//把数组切分为a[lo..p-1] a[p] a[p+1..high]
	int p;
	p = a[lo];
	while (lo < high) { //从两端向中间扫描
		while (lo < high&&a[high] >= p)
			high--;
		swap(a[lo], a[high]);
		while (lo < high&&a[lo] <= p)
			lo++;
		swap(a[lo], a[high]);
	}
	return lo;
}
int Partition2(vector<int> &a, int lo, int high)//优化
{//把数组切分为a[lo..p-1] a[p] a[p+1..high]
	int p;
	p = a[lo];
	while (lo < high) { //从两端向中间扫描
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
			lo = p + 1;//尾递归
		}
	}
	else
		InsertSort(a);
}
void QuickSort(vector<int> &a) {
	QSort(a,0,a.size()-1);
}
void HeapAdjust(vector<int> &a, int s, int m) {//从小到大 大顶堆
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
void HeapAdjust2(vector<int> &a, int s, int m) {//从大到小 //小顶堆
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
		HeapAdjust(a, i, a.size()-1);//构成大顶堆
	for (i = a.size()-1; i > 0; i--)//将大顶堆排序  逆序转换 
	{
		swap(a[0], a[i]);
		HeapAdjust(a, 0, i - 1);
	}
}



