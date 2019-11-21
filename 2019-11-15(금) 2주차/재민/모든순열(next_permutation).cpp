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

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		v.push_back(i);
	}

	do {

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << ' ';
		}

		cout << '\n';


	} while (next_permutation(v.begin(), v.end()));

	
	

	return 0;
}