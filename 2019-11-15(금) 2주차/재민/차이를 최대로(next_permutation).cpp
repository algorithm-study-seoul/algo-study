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
vector<int> v;
int ans = 0;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	do {

		int sum = 0;

		for (int i = 0; i < n - 1; i++) {
			sum += abs(v[i] - v[i + 1]);
		}

		if (sum > ans) ans = sum;
		

	} while (next_permutation(v.begin(),v.end()));
	
	cout << ans << '\n';

	return 0;
}