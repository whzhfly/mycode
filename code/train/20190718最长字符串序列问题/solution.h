#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
 //�����������
using namespace std;
class stringQuestion {   
public:
	//:�ַ���s��p����s��ɾ�����ٵ��ַ���ʹpΪs���Ӵ�
	int getminvalue(string str1,string str2) {
		vector<int> dp(str1.size(), 0);
		vector<int> lastequl;
		int j = 0;
		for (int i = 0; i<str1.size(); i++) {
			if (str1[i] == str2[j]) {
				j++;
				dp[i]=j;
				if (j == str2.size()) {
					lastequl.push_back(i);
					break;
				}
			}
		}
		for (int i = lastequl[0]+1; i < str1.size(); i++) {
			if (str1[i] == str2[j - 1]) {
				lastequl.push_back(i);
			}
		}
		//��ʼ�ж���С
		int res = str1.size();
		for (int i = 0; i < lastequl.size(); i++) {
			int righti = lastequl[i];
			int rightj = str2.size() - 1;
			while (1)
			{
				if (str1[righti] == str2[rightj]) {
					rightj--;
				}
				if (rightj < 0) {
					break;
				}
				righti--;
				//������ԼӸ��Ż� һ�������ȴ���֮ǰ��min ��break
			} 
			int val = lastequl[i] - righti +1;
			res = min(val, res);
		}
		return res-str2.size();
	}
	//��������
	//������ִ�  Longest Continuous Increasing Subsequence 
	int LCIS(vector<int>& nums) {
		int cur=INT_MAX, cnt=0, res=0;
		for (auto i :nums) {
			if (i > cur)
				cnt++;
			else
				cnt = 1;
			res = max(res , cnt);
			cur = i;
		}
		return res;
	}
	//�����������  Longest Increasing Subsequence
	int LIS1(vector<int>& nums) {  //dp[i]��ʾ��nums[i]Ϊ��β��������Ӵ��ĳ���,ÿ�δӵ�һ����ʼѰ�� o��n^2)
		vector<int> dp(nums.size(), 1);
		int res = 0;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
			res = max(dp[i], res);
		}
		return res;        
	}
	int LIS2(vector<int>& nums) {

	}
	/****************************************************************************/

	//�����
	//�����ַ�����Ӵ� Longest Continuous Common Subsequence  
	int LCCS(vector<int>& A, vector<int>& B){ //dp[i][j]��ʾ����A��ǰi�����ֺ�����B��ǰj�����ֵ��������ĳ���,��i,j��β��
		int res = 0;
		vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
		for (int i = 1; i <= A.size(); i++) {
			for (int j = 1; j <= B.size(); j++) {
				dp[i][j] = (A[i - 1] == B[j - 1]) ? dp[i - 1][j - 1] + 1 : 0;
				res = max(res, dp[i][j]);
			}
		}
		return res;
	}
	//�����������  Longest  Common Subsequence  
	int LCS(vector<int>& A, vector<int>& B) {
		int res = 0;
		vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
		for (int i = 1; i <= A.size(); i++) {
			for (int j = 1; j <= B.size(); j++) {
				if (A[i - 1] == B[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j]= max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[A.size()][B.size()];
	}


	/****************************************/
	//��������
	//��֤����   reverse   ������ַ������ո�� �ͽ���һ��left��wrightָ����� ��������ĸ���־�����Valid Palindrome ��֤�����ַ���
	int reverse(int x) {
		int res = 0;
		while (x != 0) {
			if (res > INT_MAX / 10) return -1;
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}
	bool isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0)) return false;
		return reverse(x) == x;
	}
	//��ֻ���  Valid Palindrome ��֤�����ַ���
	vector<vector<string>> partition(string s) {
		
	}
	//�ַ�����Ӷ���Ϊ����



	//�ַ���������ִ�
	string longestPalindrome(string s) {
		string t = "$#";
		for (auto i : s) {
			t += i;
			t += '#';
		}
		int id=0, mx=0, resid=0, max=0;
		vector<int> dp(t.size(), 0);
		for (int i = 1; i < t.size(); i++) {
			dp[i] = mx > i ? min(dp[2*id-i],mx-i) : 1;
			while(t[i + dp[i]] == t[i - dp[i]])
				dp[i]++;
			if (mx < dp[i] + i)
			{
				mx = dp[i] + i;
				id = i;
			}
			if (max < dp[i])
			{
				max = dp[i];
				resid = i;
			}
		}
		return s.substr((resid - max) / 2, max - 1);
	}


	////�ַ�������������� Longest Palindromic Subsequence  �������йؼ�ֵ�����⣬��Ӧ�����ȿ��ǵľ���̰���㷨�Ͷ�̬�滮��  ֱ�ӽ�string��ת��Ȼ�������ת��Ϊ LCS �ĽⷨҲ�ǳ���
	int longestPalindromeSubseq1(string s) {
		int n = s.size();
		vector<vector<int>> dp(n, vector<int>(n));
		for (int i = n - 1; i >= 0; --i) {
			dp[i][i] = 1;
			for (int j = i + 1; j < n; ++j) {
				if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else {
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[0][n - 1];
	}
	//һά�����Ż�
	int longestPalindromeSubseq2(string s) {
		int n = s.size(), res = 0;
		vector<int> dp(n, 1);
		for (int i = n - 1; i >= 0; --i) {
			int len = 0;
			for (int j = i + 1; j < n; ++j) {
				int t = dp[j];
				if (s[i] == s[j]) {
					dp[j] = len + 2;
				}
				len = max(len, t);
			}
		}
		for (int num : dp) res = max(res, num);
		return res;
	}


	//�ַ�����̻�������
	string shortestPalindrome(string s){
		
	}
};
#pragma once
