#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10

int n;
int map[MAX][MAX];
bool v[MAX];
int mins=1e9; //최소비용
int start;

void dfs(int index,int sum, int count) {


	if (count == n) {
		
		if (map[index][start] != 0) {
			sum += map[index][start];
			if (mins > sum) {
				mins = sum;
			}

		}
		//cout << "\n";

	}

	else {
		for (int i = 0; i < n; i++) {
			if (!v[i] && map[index][i]!=0) {
				v[i] = true;
				sum += map[index][i];
				//cout << i << " ";
				dfs(i, sum, ++count);
				v[i] = false;
				count--;
				sum -= map[index][i];
			}
		}
		
	}
	
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (start = 0; start < n; start++) {
		v[start] = true;
		dfs(start,0,1);
		v[start] = false;

	}
	cout << mins;


	return 0;
}