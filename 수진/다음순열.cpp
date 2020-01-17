#include<iostream>
#include<algorithm>
using namespace std;
#include <vector>


int main() {

	int n;
	vector <int> V;

	cin >> n;
	V.resize(n); //n크기로 벡터킉 설정

	for (int i = 0; i < n; i++) {
		cin >> V[i];


	}

	//다음 순열이 존재하면 벡터배열 다음순열로 변경
					//	(시작요소, 마지막요소)
	if (next_permutation(V.begin(), V.end())){

		for (int i = 0; i < n; i++) {
			cout << V[i] << " ";
		}
	}
	else {
		cout << "-1";
	}


	return 0;


}
