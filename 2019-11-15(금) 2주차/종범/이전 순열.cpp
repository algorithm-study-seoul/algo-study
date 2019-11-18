// https://www.acmicpc.net/problem/10972

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 10001;
int N;
int arr[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	if (prev_permutation(arr, arr + N) == true) {
		for (int i = 0; i < N; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else
		cout << -1 << '\n';

	return 0;

}