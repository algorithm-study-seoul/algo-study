// https://www.acmicpc.net/problem/17779
// ��ΰ��� ���� �̷��� ���� �ȵǴµ�..

#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

const int MAX = 20;
int N, ans = 987654321;
int MAP[MAX][MAX];
int CMAP[MAX][MAX];
int landNum[6];		// ���ű����� �� �ο����� ��� ���� ī��Ʈ�迭

// bfs Ȯ���� ���� �迭
int Dx[] = { 0,0,1,-1 };
int Dy[] = { 1,-1,0,0 };

// �밢������ �������� ���� �迭 -> 0:���ʾƷ�, 1:������ �Ʒ�
int dx[] = { 1, 1 };
int dy[] = { -1, 1 };

// �װ��� ���� ��ǥ�� �޾� �׵θ��� 5�� ����
void marking(int x, int y, int lx, int ly, int rx, int ry, int mx, int my) {
	for (int i = x, j = y; i <= lx, j >= ly; i++, j--) {
		CMAP[i][j] = 5;
	}
	for (int i = x, j = y; i <= rx, j <= ry; i++, j++) {
		CMAP[i][j] = 5;
	}
	for (int i = lx, j = ly; i <= mx, j <= my; i++, j++) {
		CMAP[i][j] = 5;
	}
	for (int i = rx, j = ry; i <= mx, j >= my; i++, j--) {
		CMAP[i][j] = 5;
	}
}

// ���ű� level ���� Ȯ��
void bfs(int sx, int sy, int level, int i, int j, int lx, int ly, int rx, int ry, int mx, int my) {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	CMAP[sx][sy] = level;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + Dx[k];
			int ny = y + Dy[k];

			if (level == 1) {
				if (nx >= 0 && nx < lx && ny >= 0 && ny <= j) {
					if (CMAP[nx][ny] == 0) {
						CMAP[nx][ny] = level;
						q.push(make_pair(nx, ny));
					}
				}
			}
			else if (level == 2) {
				if (nx >= 0 && nx <= rx && ny > j && ny < N) {
					if (CMAP[nx][ny] == 0) {
						CMAP[nx][ny] = level;
						q.push(make_pair(nx, ny));
					}
				}
			}
			else if (level == 3) {
				if (nx >= lx && nx < N && ny >= 0 && ny < my) {
					if (CMAP[nx][ny] == 0) {
						CMAP[nx][ny] = level;
						q.push(make_pair(nx, ny));
					}
				}
			}
			else if (level == 4) {
				if (nx > rx && nx < N && ny >= my && ny < N) {
					if (CMAP[nx][ny] == 0) {
						CMAP[nx][ny] = level;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

// ���ű����� ����ū �α����� ���� ���� �α����� ���� ��ȯ�ϴ� �Լ�
int solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			landNum[CMAP[i][j]] += MAP[i][j];
		}
	}
	landNum[5] += landNum[0];	// 5�������� ���� 5�� ��ŷ�������� 0���� �� �κе� 5�� ������

	int Max = -987654321, Min = 987654321;

	for (int i = 1; i < 6; i++) {
		if (landNum[i] > Max) Max = landNum[i];
		if (landNum[i] < Min) Min = landNum[i];
	}
	int ret = Max - Min;
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	
	// ���� ��� ��ǥ ���� 2�� for��
	for (int i = 0; i < N - 2; i++) {
		for (int j = 1; j < N - 1; j++) {

			int lx = i, ly = j;
			for (int d1 = 1; d1 <= 20; d1++) {	// ���� ����
				lx += dx[0];
				ly += dy[0];
				if (lx >= N - 1 || ly < 0) break;	// ���ʾƷ��� �������� �밢���� ���� ����

				int rx = i, ry = j;
				for (int d2 = 1; d2 <= 20; d2++) {	// ������ ����
					rx += dx[1];
					ry += dy[1];
					if (rx >= N - 1 || ry >= N) break;	// ������ �Ʒ��� �������� �밢���� ���� ����

					int mx = lx, my = ly;
					for (int cnt = 1; cnt <= d2; cnt++) {	// ���ʿ��� ������ ��ǥ���� d2��ŭ ���������� ������
						mx += dx[1];
						my += dy[1];
					}
					if (mx >= N) break;		// �߰����� ��ǥ ���ѹ���

					if (mx < N) {
						marking(i, j, lx, ly, rx, ry, mx, my);	// 5���� �׵θ��� ��ŷ
					
						bfs(0, 0, 1, i, j, lx, ly, rx, ry, mx, my);			// 1���� ��Ʈ����
						bfs(0, N - 1, 2, i, j, lx, ly, rx, ry, mx, my);		// 2����
						bfs(N - 1, 0, 3, i, j, lx, ly, rx, ry, mx, my);		// 3����
						bfs(N - 1, N - 1, 4, i, j, lx, ly, rx, ry, mx, my);	// 4����
						
						ans = min(ans, solution());

						memset(CMAP, 0, sizeof(CMAP));
						memset(landNum, 0, sizeof(landNum));
					}
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}