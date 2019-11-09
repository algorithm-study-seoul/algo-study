// https://www.acmicpc.net/problem/12100

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 20;
int N, ans;
int MAP[MAX][MAX];
int CMAP[MAX][MAX];

vector<int> rotation;

void show() {

	cout << "----------------------------------" << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << CMAP[i][j] << ' ';
		cout << '\n';
	}
}

// 게임한번 진행시키고 max값을 찾아서 반환
int find_max() {
	int MAX = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (CMAP[i][j] > MAX) MAX = CMAP[i][j];
		}
	}
	return MAX;
}

// 맵의 N의 크기에 맞게 0을 붙여주는 함수
vector<int> plus_zero(vector<int> temp) {
	int size = N - temp.size();
	while (size--) {
		temp.push_back(0);
	}
	return temp;
}

// 같은수를 합치고 그중 발생한 빈공간을 없애며 원래 MAP에 길이에 맞게 0을 붙이는 함수
vector<int> zero_pass(vector<int> temp) {

	for (int k = 0; k < temp.size() - 1; k++) {
		if (temp[k] == temp[k + 1]) {
			temp[k] *= 2;
			temp[k + 1] = 0;
		}
	}

	vector<int> total;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == 0) continue;
		total.push_back(temp[i]);
	}

	total = plus_zero(total);
	return total;
}

void Left() {
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			if (CMAP[i][j] == 0) continue;
			temp.push_back(CMAP[i][j]);
		}

		if (temp.size() > 1)
			temp = zero_pass(temp);
		else if (temp.size() == 1)
			temp = plus_zero(temp);

		if (temp.size() >= 1) {
			for (int j = 0; j < N; j++) {
				CMAP[i][j] = temp[j];
			}
		}

	}
}

void Right() {
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = N - 1; j >= 0; j--) {
			if (CMAP[i][j] == 0) continue;
			temp.push_back(CMAP[i][j]);
		}

		if (temp.size() > 1)
			temp = zero_pass(temp);
		else if (temp.size() == 1)
			temp = plus_zero(temp);

		if (temp.size() >= 1) {
			int index = 0;
			for (int j = N - 1; j >= 0; j--) {
				CMAP[i][j] = temp[index];
				index++;
			}
		}
	}
}

void Down() {
	for (int j = 0; j < N; j++) {
		vector<int> temp;
		for (int i = N - 1; i >= 0; i--) {
			if (CMAP[i][j] == 0) continue;
			temp.push_back(CMAP[i][j]);
		}

		if (temp.size() > 1)
			temp = zero_pass(temp);
		else if (temp.size() == 1)
			temp = plus_zero(temp);

		if (temp.size() >= 1) {
			int index = 0;
			for (int i = N - 1; i >= 0; i--) {
				CMAP[i][j] = temp[index];
				index++;
			}
		}
	}
}

void Up() {
	for (int j = 0; j < N; j++) {
		vector<int> temp;
		for (int i = 0; i < N; i++) {
			if (CMAP[i][j] == 0) continue;
			temp.push_back(CMAP[i][j]);
		}

		if (temp.size() > 1)
			temp = zero_pass(temp);
		else if (temp.size() == 1)
			temp = plus_zero(temp);

		if (temp.size() >= 1) {
			for (int i = 0; i < N; i++) {
				CMAP[i][j] = temp[i];
			}
		}
	}
}

void play_board_game() {
	for (int i = 0; i < rotation.size(); i++) {
		int dir = rotation[i];

		if (dir == 0)		// 동쪽
			Right();
		else if (dir == 1) 	// 서쪽
			Left();
		else if (dir == 2)	// 남쪽
			Down();
		else				// 북쪽
			Up();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans = max(ans, CMAP[i][j]);
		}
	}

}

// 맵복사 함수
void copy_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			CMAP[i][j] = MAP[i][j];
		}
	}
}

// 조합 dfs
void dfs(int cnt) {
	if (cnt == 5) {
		copy_map();
		play_board_game();
		return;
	}

	// 0동, 1서, 2남, 3북
	for (int i = 0; i < 4; i++) {
		rotation.push_back(i);
		dfs(cnt + 1);
		rotation.pop_back();
	}

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

	dfs(0);

	cout << ans << '\n';

	return 0;
}
