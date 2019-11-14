#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
int map[500][500];
bool check[500][500];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int ans = 0;
int ans2 = 0;
int mx = 0;
int sum = 0;

void dfs(int row, int col, int depth) {

	if (depth == 3) {

		//printf("row : %d col : %d\n", row, col);
		//printf("sum : %d\n", sum);
		if (sum > mx) {
			mx = sum;
		}

		return;
	}

	check[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int nx = row + dx[i];
		int ny = col + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (!check[nx][ny]) {
			check[nx][ny] = true;
			sum += map[nx][ny];
			dfs(nx, ny, depth + 1);
			sum -= map[nx][ny];
			check[nx][ny] = false;
		}
	}


}

int except(int row, int col) {

	vector<int> s;



	//で
	if (row - 1 >= 0 && col - 1 >= 0 && col + 1 < m) {
		int s1 = 0;
		s1 = map[row][col - 1] + map[row][col] + map[row][col + 1] + map[row - 1][col];
		s.push_back(s1);
	}

	//っ
	if (col - 1 >= 0 && row - 1 >= 0 && row + 1 < n) {
		int s2 = 0;
		s2 = map[row][col] + map[row][col - 1] + map[row - 1][col] + map[row + 1][col];
		s.push_back(s2);
	}

	//た
	if (row - 1 >= 0 && row + 1 < n && col + 1 < m) {
		int s3 = 0;
		s3 = map[row][col] + map[row - 1][col] + map[row + 1][col] + map[row][col + 1];
		s.push_back(s3);
	}

	//ぬ
	if (col - 1 >= 0 && row + 1 < n && col + 1 < m) {
		int s4 = 0;
		s4 = map[row][col] + map[row][col - 1] + map[row][col + 1] + map[row + 1][col];
		s.push_back(s4);
	}

	int ret = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] > ret)
			ret = s[i];
	}

	return ret;

}

void go() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int sum2;
			memset(check, false, sizeof(check));
			sum = map[i][j];
			dfs(i, j, 0);

			sum2 = except(i, j);

			ans = max(mx, sum2);

			if (ans > ans2) {
				ans2 = ans;
			}
		}
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	go();

	cout << ans2 << '\n';

	return 0;
}