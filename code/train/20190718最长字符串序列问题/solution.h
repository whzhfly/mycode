#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
 //最长子序列问题
using namespace std;
class stringQuestion {   
public:
	//:字符串s和p，在s中删除最少的字符，使p为s的子串
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
		//开始判断最小
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
				//这里可以加个优化 一旦它长度大于之前的min 就break
			} 
			int val = lastequl[i] - righti +1;
			res = min(val, res);
		}
		return res-str2.size();
	}
	//递增问题
	//最长递增字串  Longest Continuous Increasing Subsequence 
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
	//最长递增子序列  Longest Increasing Subsequence
	int LIS1(vector<int>& nums) {  //dp[i]表示以nums[i]为结尾的最长递增子串的长度,每次从第一个开始寻找 o（n^2)
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

	//最长问题
	//两个字符串最长子串 Longest Continuous Common Subsequence  
	int LCCS(vector<int>& A, vector<int>& B){ //dp[i][j]表示数组A的前i个数字和数组B的前j个数字的最长子数组的长度,以i,j结尾的
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
	//最长公共子序列  Longest  Common Subsequence  
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
	//回文问题
	//验证回文   reverse   如果是字符串带空格的 就建立一个left和wright指针便利 遇到非字母数字就跳过Valid Palindrome 验证回文字符串
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
	//拆分回文  Valid Palindrome 验证回文字符串
	vector<vector<string>> partition(string s) {
		
	}
	//字符串添加多少为回文



	//字符串最长回文字串
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


	////字符串最长回文子序列 Longest Palindromic Subsequence  像这种有关极值的问题，最应该优先考虑的就是贪婪算法和动态规划，  直接将string翻转，然后把问题转换为 LCS 的解法也非常好
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
	//一维数组优化
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


	//字符串最短回文序列
	string shortestPalindrome(string s){
		
	}
};
#pragma once
