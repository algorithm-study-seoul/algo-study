#include<iostream>
#include<algorithm>
using namespace std;


int E, S, M;

int main() {

	cin >> E >> S >> M;

	for (int i = 1;; i++) {
		if ((i - E) % 15 == 0 && (i - S) % 28 == 0 && (i - M) % 19 == 0) {
			cout << i << endl;
			break;
		}
	}

	return 0;


}
