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

typedef struct {

	int num;
	bool can_move = true;

}Block;

int n;
Block map[20][20];
Block temp_map[5][20][20];
int ans;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void move_map(int row,int col,int dir) {

	queue<pair<int, int>> q;

	q.push(make_pair(row, col));

	while (!q.empty()) {
		row = q.front().first;
		col = q.front().second;
		q.pop();
		int nx = row + dx[dir];
		int ny = col + dy[dir];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			if (map[nx][ny].num == 0) {
				map[nx][ny].num = map[row][col].num;
				map[row][col].num = 0;
				q.push(make_pair(nx, ny));
			}
			else if (map[nx][ny].num == map[row][col].num && map[row][col].can_move) {
				map[nx][ny].num = map[row][col].num + map[nx][ny].num;
				map[row][col].num = 0;
				map[row][col].can_move = false;
			}
		}
	}
	

}

void save_map(int cnt) {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp_map[cnt][i][j].num = map[i][j].num;
		}
	}

}

void load_map(int cnt) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j].num = temp_map[cnt][i][j].num;
		}
	}

}



void go(int cnt) {

	if (cnt == 5) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int temp = map[i][j].num;
				if (temp > ans) {
					ans = temp;
				}
			}
		}

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/

		return;
	}
	
	save_map(cnt);
	for (int i = 0; i < 4; i++) {

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j].can_move = true;
			}
		}

		if (i == 0) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (map[j][k].num != 0) {
						move_map(j, k, i);
					}
				}
			}
		}
		else if (i == 1) {
			for (int j = n - 1; j >= 0; j--) {
				for (int k = 0; k < n; k++) {
					if (map[k][j].num != 0) {
						move_map(k, j, i);
					}
				}
			}
		}
		else if (i == 2) {
			for (int j = n - 1; j >= 0; j--) {
				for (int k = 0; k < n; k++) {
					if (map[j][k].num != 0) {
						move_map(j, k, i);
					}
				}
			}
		}

		else if (i == 3) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (map[k][j].num != 0) {
						move_map(k, j, i);
					}
				}
			}	
		}

		go(cnt + 1);
		load_map(cnt);
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j].num;
		}
	}

	go(0);

	cout << ans << '\n';

	return 0;
}