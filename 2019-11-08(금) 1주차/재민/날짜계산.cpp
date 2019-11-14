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

int a_e, a_s, a_m;
int ans = 1;

void go() {

	int e = 1;
	int s = 1;
	int m = 1;

	while (a_e != e || a_s != s || a_m != m) {
		e++;
		s++;
		m++;
		ans++;
		if (e > 15)
			e = 1;
		if (s > 28)
			s = 1;
		if (m > 19)
			m = 1;
	}



}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a_e >> a_s >> a_m;

	go();

	cout << ans << '\n';

	return 0;
}