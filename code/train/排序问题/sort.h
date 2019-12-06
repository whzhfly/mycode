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
	//选择排序 冒泡是比他小就换 而选择是先记录下标 找到最小再换   时间复杂度n^2
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

	//c插入排序 类似大牌  时间复杂度(n^2)/4  
	void InsertSort(vector<int>& a,int n) {
		if (n <= 0)
			return;
		int i,j,tmp;
		for (int i = 1; i < n; i++) {
			if (a[i] < a[i - 1])//需要插入
			{
				tmp = a[i];//设置哨兵
				for (j = i - 1; a[j] > tmp && j >= 0; j--)
					a[j + 1] = a[j];//记录后移动 
				a[j + 1] = tmp;
			}
		}
	}

	//希尔排序  基于插入排序 不同的是有个len值 先分组
	//swap的为间隔len值的点 结果：第一组的第i个值最小（每组i值） 最后一组最大
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

	//快速排序
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

	//归并排序
	//把a[i..m]和a[m+1...n]归并成有序的a
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
	//把a[s..t]归并到b[s...t]
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
	//从上到下归并  相邻合并
	void MergeSortUptoDown(vector<int>& a) {
		int N = a.size();
		for (int size = 1; size < N; size *= 2) //步长成倍递增 
			for (int lo = 0; lo < N - size; lo += size + size)//两两合并 
				Merge(a, lo, lo + size - 1, min(lo + size + size - 1, N - 1));//使用min,防止右边界越界 
	}

	//堆排序  //从小到大 大顶堆
	void HeadAdjust(vector<int>& a,int s,int m) {
		int tmp, j;
		tmp = a[s];
		for (int j = 2 * s; j <= m; j *= 2) {
			if (j < m && a[j] < a[j + 1])  //这里取反
				++j;
			if (tmp >= a[j])   //这里也取反
				break;
			a[s] = a[j];
			s = j;
		}
		a[s] = tmp;
	}
	void HeapSort(vector<int>& a, int  n) {
		int i;
		// 构建大根堆（从最后一个非叶子节点向上）
		for (int i = (n - 1) / 2; i >= 0; i--) 
			HeadAdjust(a, i, n - 1);
		// 调整大根堆
		for (int i = n - 1; i > 0; i--) {
			swap(a[0],a[i]);
			HeadAdjust(a, 0, i - 1);
		}
	}
};
#pragma once
