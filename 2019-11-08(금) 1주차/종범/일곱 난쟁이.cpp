// https://www.acmicpc.net/problem/2309

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool flag;
bool check[9];
vector<int> v, ans;

int total_100() {
	int sum = 0;
	for (auto i : ans) {
		sum += i;
	}
	return sum;
}

void dfs(int cnt) {
	if (cnt == 7 && total_100() == 100) {
		flag = true;
		for (auto i : ans) {
			cout << i << '\n';
		}
		return;
	}

	if (flag) return;

	for (int i = 0; i < v.size(); i++) {
		if (check[i] == true) continue;
		check[i] = true;
		ans.push_back(v[i]);
		dfs(cnt + 1);
		check[i] = false;
		ans.pop_back();
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	dfs(0);

	return 0;
}