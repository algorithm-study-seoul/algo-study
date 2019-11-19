// https://www.acmicpc.net/problem/10971
// 도시의 범위가 더 컸다면 시간초과 발생했을 문제.. 최적화 필요함

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 10;
int N, ans = 987654321;
int dist[MAX][MAX];
bool check[MAX];
vector<int> v;

// 순회가능한지 확인하는 함수, 가능하면 순회에 필요한 최소비용을 반환
int connected() {
	int sum = 0;
	if (dist[v[v.size() - 1]][v[0]] == 0) return 0;	// 마지막과 처음이 연결되어 있지 않다면 0 반환
	for (int i = 0; i < v.size() - 1; i++) {
		if (dist[v[i]][v[i + 1]] == 0) return 0;	// 순회경로중 연결되어 있지 않다면 0 반환
		else sum += dist[v[i]][v[i + 1]];		// 연결되어 있다면 비용을 더함
	}
	return sum + dist[v[v.size() - 1]][v[0]];
}

void brute(int cnt) {
	if (cnt == N) {
		int ret = connected();
		if (ret > 0) {
			ans = min(ans, ret);
		}
		return;
	}

	for (int i = 0; i < N; i++) {
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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> dist[i][j];
		}
	}

	brute(0);
	cout << ans << '\n';
	return 0;
}