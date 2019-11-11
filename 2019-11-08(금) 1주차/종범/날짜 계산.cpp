// https://www.acmicpc.net/problem/1476

#include<iostream>

using namespace std;

int E, S, M, ans = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> E >> S >> M;

	int e = 1, s = 1, m = 1;

	while (true) {
		if (e == E && s == S && m == M) {
			cout << ans << '\n';
			break;
		}

		e = e + 1 > 15 ? 1 : e + 1;
		s = s + 1 > 28 ? 1 : s + 1;
		m = m + 1 > 19 ? 1 : m + 1;
		ans++;
	}

	return 0;
}