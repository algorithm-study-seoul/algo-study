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
			else if (sub_map[i][j] == 5) sum5 += map[i][j];
		}
	}

	int mx = max({ sum1,sum2,sum3,sum4,sum5 });
	int mn = min({ sum1,sum2,sum3,sum4,sum5 });

	if (ans > mx - mn) {
		ans = mx - mn;
	}

}

void make_map(int d1,int d2) {

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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (sub_map[i][j] != 0) continue;
			if (i >= 0 && i < s_row + d1 && j >= 0 && j <= s_col) {
				sub_map[i][j] = 1;
			}
			else if (i >= 0 && i <= s_row + d2 && j > s_col && j <= n - 1) {
				sub_map[i][j] = 2;
			}
			else if (i >= s_row + d1 && i <= n - 1 && j >= 0 && j < s_col - d1 + d2) {
				sub_map[i][j] = 3;
			}
			else if (i > s_row + d2 && i <= n - 1 && j >= s_col - d1 + d2 && j <= n - 1) {
				sub_map[i][j] = 4;
			}
		}
	}

	cal_min();

	printf("s_row : %d s_col : %d\n", s_row, s_col);
	printf("d1 : %d d2 : %d\n", d1, d2);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", sub_map[i][j]);
		}
		printf("\n");
	}
	printf("\n");


}

void go(int row,int col,int curv,int b_dir,int d1,int d2) {

	if (curv >= 5) {
		return;
	}

	check[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int nx = row + dx[i];
		int ny = col + dy[i];
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


	return 0;
}