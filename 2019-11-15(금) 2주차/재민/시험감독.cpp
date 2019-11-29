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

int n, b, c;
vector<int> v;
int ans = 987654321;
bool check[1000001];

bool isend() {

	for (int i = 0; i < n; i++) {
		if (v[i] > 0) return false;
	}

	return true;


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		v[i] -= b;
		if (v[i] < 0) v[i] = 0;
	}

	long long total = n;
	long long sub = 0;

	for (int i = 0; i < n; i++) {

		long long t_sub = 0;
		
		t_sub = v[i] / c;

		if (v[i] % c != 0) t_sub++;

		sub += t_sub;


	}

	cout << total + sub << '\n';

	return 0;
}