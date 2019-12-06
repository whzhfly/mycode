#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<stack>
#include<deque>
#include<queue>
using namespace std;
void helper130(vector<vector<char>>& board, vector<vector<char>>& res, int i, int j) {
	res[i][j] = 'O';
	if (i-1>=0&&board[i - 1][j] == 'O' && res[i - 1][j] == 'X')
		helper130(board, res, i - 1, j);
	if (i+1<board.size()&&board[i + 1][j] == 'O' && res[i + 1][j] == 'X')
		helper130(board, res, i + 1, j);
	if (j-1>=0&&board[i][j - 1] == 'O' && res[i][j - 1] == 'X')
		helper130(board, res, i, j - 1);
	if (j+1<board[0].size()&&board[i][j + 1] == 'O' && res[i][j + 1] == 'X')
		helper130(board, res, i, j + 1);
}
class solution {
public:
	static void solve130(vector<vector<char>>& board) {
		if (board.size()<1 || board[0].size() < 1)
			return;
		int row = board.size() - 1;
		int col = board[0].size() - 1;
		vector<vector<char>> res(board.size(), vector<char>(board[0].size(), 'X'));
		for (int i = 0; i <=col; i++) {
			if (board[0][i] == 'O' && res[0][i] == 'X')
				helper130(board, res, 0, i);
		}
		for (int i = 0; i <=col; i++) {
			bool cna = board[row][i] == 'O' && res[row][i] == 'X';
			if (cna)
				helper130(board, res, row, i);
		}
		for (int i = 1; i < row; i++) {
			if (board[i][0] == 'O' && res[i][0] == 'X')
				helper130(board, res, i, 0);
		}
		for (int i = 1; i <row; i++) {
			if (board[i][col] == 'O' && res[i][col] == 'X')
				helper130(board, res, i, col );
		}
		for (int i = 0; i <=row; i++) {
			for (int j = 0; j <=col; j++) {
				board[i][j] = res[i][j];
				cout << board[i][j]<<" ";
			}
			cout << endl;
		}
	}
};
#pragma once
