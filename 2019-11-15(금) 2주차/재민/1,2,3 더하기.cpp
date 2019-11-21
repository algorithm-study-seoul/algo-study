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

int T, n;
bool check[4];
int cnt = 0;

void go(int sum) {

	if (sum == n) {
		cnt++;
		return;
	}

	if (sum > n) {
		return;
	}

	for (int i = 1; i <= 3; i++) {
		go(sum + i);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cnt = 0;
		go(0);
		cout << cnt << '\n';
	}

	return 0;
}