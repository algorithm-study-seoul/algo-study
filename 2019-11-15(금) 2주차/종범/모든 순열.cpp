// https://www.acmicpc.net/problem/10974

#include<iostream>
#include<vector>

using namespace std;

const int MAX = 9;
int N;
bool check[MAX];
vector<int> v;

void brute(int cnt) {
	if (cnt == N) {
		for (auto j : v) {
			cout << j << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (check[i] == true) continue;
		check[i] = true;
		v.push_back(i);
		brute(cnt + 1);
		v.pop_back();
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	brute(0);
	return 0;
}