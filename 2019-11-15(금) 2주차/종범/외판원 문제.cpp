// https://www.acmicpc.net/problem/10971
// ������ ������ �� �Ǵٸ� �ð��ʰ� �߻����� ����.. ����ȭ �ʿ���

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 10;
int N, ans = 987654321;
int dist[MAX][MAX];
bool check[MAX];
vector<int> v;

// ��ȸ�������� Ȯ���ϴ� �Լ�, �����ϸ� ��ȸ�� �ʿ��� �ּҺ���� ��ȯ
int connected() {
	int sum = 0;
	if (dist[v[v.size() - 1]][v[0]] == 0) return 0;	// �������� ó���� ����Ǿ� ���� �ʴٸ� 0 ��ȯ
	for (int i = 0; i < v.size() - 1; i++) {
		if (dist[v[i]][v[i + 1]] == 0) return 0;	// ��ȸ����� ����Ǿ� ���� �ʴٸ� 0 ��ȯ
		else sum += dist[v[i]][v[i + 1]];		// ����Ǿ� �ִٸ� ����� ����
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