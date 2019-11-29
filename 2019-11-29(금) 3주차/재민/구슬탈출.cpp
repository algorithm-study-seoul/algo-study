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

typedef struct{

	int row;
	int col;
	int ch;
	int pw;

}BC;

int T, m, a;
int ans = 0;
int map[8][11][11];
vector<int> mv1, mv2;
vector<int> sum1, sum2;
vector<BC> bc;
bool check[11][11];
int dx[] = { 0,0,1,0,-1 };
int dy[] = { 0,-1,0,1,0 };

void spread(int row,int col,int depth,int idx) {

	if (depth == bc[idx].ch) {

		return;
	}

	map[idx][row][col] = idx + 1;
	check[row][col] = true;

	for (int i = 1; i < 5; i++) {
		int nx = row + dx[i];
		int ny = col + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= 10 && ny <= 10) {
			if (!check[nx][ny]) {
				check[nx][ny] = true;
				map[idx][nx][ny] = idx + 1;
				spread(nx, ny, depth + 1, idx);
				check[nx][ny] = false;
			}
		}
	}
	




}

void go() {

	for (int i = 0; i < bc.size(); i++) {
		memset(check, false, sizeof(check));
		spread(bc[i].row, bc[i].col,0, i);
	}

	int a_row = 1;
	int a_col = 1;
	int b_row = 10;
	int b_col = 10;


	for (int i = 0; i < m + 1; i++) {

		int n_a_row = a_row + dy[mv1[i]];
		int n_a_col = a_col + dx[mv1[i]];
		int n_b_row = b_row + dy[mv2[i]];
		int n_b_col = b_col + dx[mv2[i]];

		//printf("a_row : %d a_col : %d\n", n_a_row, n_a_col);
		//printf("b_row : %d b_col : %d\n", n_b_row, n_b_col);

		int a_p = 0;
		int b_p = 0;

		vector<int> a, b;

		for (int i = 0; i < bc.size(); i++) {
			if (map[i][n_a_row][n_a_col] > 0) {
				a.push_back(i);
			}
		}

		for (int i = 0; i < bc.size(); i++) {
			if (map[i][n_b_row][n_b_col] > 0) {
				b.push_back(i);
			}
		}

		if (!a.empty() && b.empty()) {
			
			int temp = 0;

			for (int i = 0; i < a.size(); i++) {
				if (bc[a[i]].pw > temp) {
					temp = bc[a[i]].pw;
				}
			}

			a_p = temp;

		}

		else if (a.empty() && !b.empty()) {

			int temp = 0;

			for (int i = 0; i < b.size(); i++) {
				if (bc[b[i]].pw > temp) {
					temp = bc[b[i]].pw;
				}
			}

			b_p = temp;


		}

		else if (!a.empty() && !b.empty()) {

			int temp = 0;
			
			for (int i = 0; i < a.size(); i++) {
				for (int j = 0; j < b.size(); j++) {
					int a_pw = bc[a[i]].pw;
					int b_pw = bc[b[j]].pw;

					if (a[i] == b[j]) {
						a_pw /= 2;
						b_pw /= 2;
					}

					if (a_pw + b_pw > temp) {
						temp = a_pw + b_pw;
						a_p = a_pw;
						b_p = b_pw;
					}

				}
			}


		}


		a_row = n_a_row;
		a_col = n_a_col;
		b_row = n_b_row;
		b_col = n_b_col;

		sum1.push_back(a_p);
		sum2.push_back(b_p);


	}



}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		ans = 0;
		sum1.clear();
		sum2.clear();
		mv1.clear();
		mv2.clear();
		bc.clear();
		memset(map, 0, sizeof(map));

		cin >> m >> a;
		mv1.push_back(0);
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			mv1.push_back(x);
		}
		mv2.push_back(0);
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			mv2.push_back(x);
		}
		for (int i = 0; i < a; i++) {
			int r, c, ch, pw;
			cin >> r >> c >> ch >> pw;

			BC b;

			b.row = c;
			b.col = r;
			b.ch = ch;
			b.pw = pw;
			bc.push_back(b);

		}
		go();

		for (int i = 0; i < sum1.size(); i++) {
			ans += sum1[i];
			ans += sum2[i];
		}

		cout << "#" << test_case << " " << ans << '\n';

	}

	return 0;
}