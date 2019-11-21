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

int n;
int arr[10][10];
int ans = 987654321;
bool check[10];

bool isend(int start, int now) {

	if (start == now) {
		for (int i = 0; i < n; i++) {
			if (!check[i]) return false;
		}

		return true;
	}
	else
		return false;

}

void go(int sum,int start,int now) {

	if (isend(start,now)) {

		if (ans > sum) ans = sum;
		//printf("sum : %d\n", sum);

		return;
	}

	for (int i = 0; i < n; i++) {
		if (arr[now][i] > 0 && !check[i] && ans > sum) {
			check[i] = true;
			go(sum + arr[now][i], start, i);
			check[i] = false;
		}
	}



}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			arr[i][j] = x;
		}
	}

	for (int i = 0; i < n; i++) {
		memset(check, false, sizeof(check));
		go(0, i, i);
	}

	cout << ans << '\n';

	return 0;
}