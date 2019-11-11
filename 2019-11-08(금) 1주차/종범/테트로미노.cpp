// https://www.acmicpc.net/problem/14500

#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 501;
int N, M, ans = -987654321;
int MAP[MAX][MAX];
bool check[MAX][MAX];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void tetromino_1(int x, int y) {		// ㅜ 모양
	int sum = 0;
	sum = MAP[x][y] + MAP[x][y + 1] + MAP[x][y + 2] + MAP[x + 1][y + 1];
	ans = max(sum, ans);
}

void tetromino_2(int x, int y) {		// ㅗ 모양
	int sum = 0;
	sum = MAP[x][y] + MAP[x][y + 1] + MAP[x][y + 2] + MAP[x - 1][y + 1];
	ans = max(sum, ans);
}

void tetromino_3(int x, int y) {		// ㅏ 모양
	int sum = 0;
	sum = MAP[x][y] + MAP[x + 1][y] + MAP[x + 2][y] + MAP[x + 1][y + 1];
	ans = max(sum, ans);
}

void tetromino_4(int x, int y) {		// ㅓ 모양
	int sum = 0;
	sum = MAP[x][y] + MAP[x + 1][y - 1] + MAP[x + 1][y] + MAP[x + 2][y];
	ans = max(sum, ans);
}

// bfs는 동시에 퍼지기 때문에 불가
// 어느 한 좌표에서 형성될 수 있는 모든 테트로미노 모형의 숫자 합을 구하는 함수
void dfs(int x, int y, int sum, int depth) {

	if (depth == 4) {	// 기저조건 : 어디든 깊이가 4만큼 뻗었을 때, 숫자의 합중 더 큰값을 ans에 넣는다
		ans = max(ans, sum);
		return;
	}

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
			if (check[nx][ny] == false) {
				check[nx][ny] = true;
				dfs(nx, ny, sum + MAP[nx][ny], depth + 1);
				check[nx][ny] = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = true;
			dfs(i, j, MAP[i][j], 1);
			check[i][j] = false;

			if (j + 2 < M && i + 1 < N) tetromino_1(i, j);	// ㅜ
			if (i - 1 >= 0 && j + 2 < M) tetromino_2(i, j);	// ㅗ
			if (i + 2 < N && j + 1 < M) tetromino_3(i, j);	// ㅏ
			if (i + 2 < N && j - 1 >= 0) tetromino_4(i, j);	// ㅓ

		}
	}

	cout << ans << '\n';
	return 0;
}