#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int MAX = 10;
typedef struct {
	int x;
	int y;
	int c;	// 충전 범위
	int p;	// 충전량
}BC;

int T, M, A;
int MAP[MAX][MAX];

int dx[] = { 0,-1,0,1,0 };
int dy[] = { 0,0,1,0,-1 };

vector<BC> bc;

int check_power(int ax, int ay, int bx, int by) {
	vector<int> possibleA(A, 0);
	vector<int> possibleB(A, 0);

	for (int i = 0; i < A; i++) {
		int distA = abs(bc[i].x - ax) + abs(bc[i].y - ay);
		int distB = abs(bc[i].x - bx) + abs(bc[i].y - by);
		if (distA <= bc[i].c) possibleA[i] = bc[i].p;
		if (distB <= bc[i].c) possibleB[i] = bc[i].p;
	}

	int sum = 0;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < A; j++) {
			if (i == j) {
				sum = max(sum, possibleA[i]);
				sum = max(sum, possibleB[i]);
			}
			else
				sum = max(sum, possibleA[i] + possibleB[j]);
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("sample_input.txt", "r", stdin);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> M >> A;

		vector<int> personA;
		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			personA.push_back(num);
		}
		vector<int> personB;
		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			personB.push_back(num);
		}

		for (int i = 0; i < A; i++) {
			BC temp;
			cin >> temp.y >> temp.x >> temp.c >> temp.p;
			temp.y -= 1; temp.x -= 1;
			bc.push_back(temp);
		}

		int ax = 0, ay = 0;
		int bx = 9, by = 9;
		int ans = check_power(ax, ay, bx, by);	// 시작점도 체크해봐야함

		for (int i = 0; i < M; i++) {
			ax += dx[personA[i]];
			ay += dy[personA[i]];
			bx += dx[personB[i]];
			by += dy[personB[i]];
			ans += check_power(ax, ay, bx, by);
		}

		cout << "#" << tc << ' ' << ans << '\n';
		bc.clear();
	}

	return 0;
}