// https://www.acmicpc.net/problem/10819

#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int MAX = 9;
int N, ans = -987654321;
bool check[MAX];
vector<int> v, Input;

int solution() {
	int sum = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		sum += abs(v[i] - v[i + 1]);
	}
	return sum;
}

void brute(int cnt) {
	if (cnt == N) {
		ans = max(ans, solution());
		return;
	}

	for (int i = 0; i < Input.size(); i++) {
		if (check[i] == true) continue;
		check[i] = true;
		v.push_back(Input[i]);
		brute(cnt + 1);
		check[i] = false;
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		Input.push_back(num);
	}
	brute(0);
	cout << ans << '\n';
	return 0;

}