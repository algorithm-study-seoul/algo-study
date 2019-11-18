// https://www.acmicpc.net/problem/9095

#include<iostream>

using namespace std;

int T, N, ans;

void brute(int sum) {
	if (sum == N) {
		ans++;
		return;
	}

	if (sum > N) return;

	for (int i = 1; i <= 3; i++) {
		brute(sum + i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		int sum = 0;
		brute(sum);
		cout << ans << '\n';
		ans = 0;
	}

	return 0;

}