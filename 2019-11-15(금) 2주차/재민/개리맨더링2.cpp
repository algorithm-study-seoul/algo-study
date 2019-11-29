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

int n;
int map[20][20];
int sub_map[20][20];
int dx[] = { -1, 1,-1,1 };
int dy[] = { -1, 1,1,-1 };
bool check[20][20];
int s_row, s_col;
int ans = 100000;
int t_row, t_col;
int r_row, r_col;
int l_row, l_col;
int d_row, d_col;

void cal_min() {

	int sum1 = 0;
	int sum2 = 0;
	int sum3 = 0;
	int sum4 = 0;
	int sum5 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sub_map[i][j] == 1) sum1 += map[i][j];
			else if (sub_map[i][j] == 2) sum2 += map[i][j];
			else if (sub_map[i][j] == 3) sum3 += map[i][j];
			else if (sub_map[i][j] == 4) sum4 += map[i][j];
			else if (sub_map[i][j] == 5 || sub_map[i][j] == 0) sum5 += map[i][j];
		}
	}

	int mx = max({ sum1,sum2,sum3,sum4,sum5 });
	int mn = min({ sum1,sum2,sum3,sum4,sum5 });

	if (ans > mx - mn) {
		ans = mx - mn;
	}

}


void bfs(int row, int col,int num) {

	queue<pair<int, int>>q;
	bool check2[20][20] = { false, };
	check2[row][col] = true;
	sub_map[row][col] = num;
	int t_dx[] = { -1,0,1,0 };
	int t_dy[] = { 0,1,0,-1 };

	q.push(make_pair(row, col));

	while (!q.empty()) {
		
		row = q.front().first;
		col = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = row + t_dx[i];
			int ny = col + t_dy[i];
			if (num == 1) {
				if (nx < l_row && nx >= 0 && ny <= t_col && ny >= 0 && sub_map[nx][ny] == 0 && !check2[nx][ny]) {
					sub_map[nx][ny] = num;
					check2[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
			else if (num == 2) {
				if (nx <= r_row && nx >= 0 && ny > t_col && ny < n && sub_map[nx][ny] == 0 && !check2[nx][ny]) {
					sub_map[nx][ny] = num;
					check2[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
			else if (num == 3) {
				if (nx >= l_row && nx < n && ny < d_col && ny >= 0 && sub_map[nx][ny] == 0 && !check2[nx][ny]) {
					sub_map[nx][ny] = num;
					check2[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
			else if (num == 4) {
				if (nx > r_row && nx < n && ny >= d_col && ny < n && sub_map[nx][ny] == 0 && !check2[nx][ny]) {
					sub_map[nx][ny] = num;
					check2[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}


	}


}

void make_map(int d1, int d2) {

	memset(sub_map, 0, sizeof(sub_map));

	d1 = d1 / 2;
	d2 = d2 / 2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j]) {
				sub_map[i][j] = 5;
			}
		}
	}
	

	bool t_end = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sub_map[i][j] == 5) {
				t_row = i;
				t_col = j;
				t_end = true;
				break;
			}
		}
		if (t_end) break;
	}

	bool d_end = false;

	for (int i = n - 1; i >= 0;i--) {
		for (int j = 0; j < n; j++) {
			if (sub_map[i][j] == 5) {
				d_row = i;
				d_col = j;
				d_end = true;
				break;
			}
		}
		if (d_end) break;
	}

	bool l_end = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sub_map[j][i] == 5) {
				l_row = j;
				l_col = i;
				l_end = true;
				break;
			}
		}
		if (l_end) break;
	}

	bool r_end = false;

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (sub_map[j][i] == 5) {
				r_row = j;
				r_col = i;
				r_end = true;
				break;
			}
		}
		if (r_end) break;
	}

	bfs(0, 0, 1);
	bfs(0, n - 1, 2);
	bfs(n - 1, 0, 3);
	bfs(n - 1, n - 1, 4);

	cal_min();


}

void go(int row, int col, int curv, int b_dir, int d1, int d2) {

	if (curv >= 4) {
		return;
	}

	check[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int nx, ny;
		if (curv == 0) {
			nx = row + dx[3];
			ny = col + dy[3];
		}
		else {
			nx = row + dx[i];
			ny = col + dy[i];
		}
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {

			if (nx == s_row && ny == s_col && curv >= 3) {

				if (i == 0 || i == 1)
					make_map(d1, d2 + 1);
				else if (i == 2 || i == 3)
					make_map(d1 + 1, d2);

				return;
			}


			if (!check[nx][ny]) {
				check[nx][ny] = true;
				if (b_dir != i) {
					if (i == 0) {
						go(nx, ny, curv + 1, i, d1, d2 + 1);
					}
					else if (i == 1) {
						go(nx, ny, curv + 1, i, d1, d2 + 1);
					}
					else if (i == 2) {
						go(nx, ny, curv + 1, i, d1 + 1, d2);
					}
					else if (i == 3) {
						go(nx, ny, curv + 1, i, d1 + 1, d2);
					}
				}
				else {
					if (i == 0) {
						go(nx, ny, curv, i, d1, d2 + 1);
					}
					else if (i == 1) {
						go(nx, ny, curv, i, d1, d2 + 1);
					}
					else if (i == 2) {
						go(nx, ny, curv, i, d1 + 1, d2);
					}
					else if (i == 3) {
						go(nx, ny, curv, i, d1 + 1, d2);
					}
				}
				check[nx][ny] = false;
			}
		}
	}



}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			memset(check, false, sizeof(check));
			s_row = i;
			s_col = j;
			go(i, j, 0, 0, 0, 0);
		}
	}

	cout << ans << '\n';


	return 0;
}