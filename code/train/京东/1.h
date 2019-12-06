#include<iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int limit = 1002;
int solution1() {
	int N, M;
	cin >> N >> M;
	int map[limit][limit];
	int visit[limit];
	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x, y;
		map[x][y] = 1;
		map[y][x] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visit[i])
			continue;
		visit[i] = ++cnt;
		for (int j = i + 1; j <= N; j++) {
			if (map[i][j] == 1) {
				if (visit[i] != 0) {
					cout << "NO";
					return 0;
				}
				visit[i] = cnt;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (visit[i] == visit[j] && map[i][j] || visit[i] != visit[j] && !map[i][j]) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}

int solutin2() {

}
#pragma once
