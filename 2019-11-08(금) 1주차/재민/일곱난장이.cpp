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

int he[9];
int ans;
bool check[9];
vector<int> v;

void print() {

	v.clear();

	for (int i = 0; i < 9; i++) {
		if (check[i]) {
			v.push_back(he[i]);
		}
	}

	sort(v.begin(), v.end());

}

void go(int idx, int cnt,int sum) {

	if (cnt == 7) {

		if (sum == 100) {
			
			print();
			
		}

		return;
	}

	for (int i = idx; i < 9; i++) {
		if (!check[i]) {
			check[i] = true;
			int sub = sum + he[i];
			go(i,cnt + 1, sub);
			check[i] = false;
		}
	}


}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++) {
		cin >> he[i];
	}

	go(0, 0, 0);

	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}


	return 0;
}