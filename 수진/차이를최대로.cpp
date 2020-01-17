#include<iostream>
#include<algorithm>
using namespace std;
#include <list>

int n;
list <int> V;
list <int> nV;

//n의 개수가 홀수 -> min max min max 순으로 가서 마지막 남은 요소 비교후 왼쪽 오른쪽 저장 결정
//n의 개수가 짝수 -> max min max min 순으로 가서 마지막 남은 요소 비교후 왼쪽 오른쪽 저장 결정


//리스트에서 원소하나 삭제시 iterator를 사용하여 순회 중 삭제를 한다.
void deletenum(int num) {
	std::list<int>::iterator iter = V.begin();

	while (iter != V.end()) {
		if (*iter == num) {
			iter = V.erase(iter++);
			break;
		}
		else {
			++iter;

		}
	}


}
int main() {


	cin >> n;


	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		V.push_back(a);
	}


	//중복삭제되는 점 고치기
	for (int i = 0; i < n;i++) {
		if (n % 2 == 0) {
			if (i % 2 == 0) {
				int max = *max_element(V.begin(), V.end());
				deletenum(max);
				//V.erase(max_element(V.begin(), V.end()));
				nV.push_back(max);
				//cout << i << "-" << max << ", ";

			}
			else {
				int min = *min_element(V.begin(), V.end());
				deletenum(min);

				//V.erase(min_element(V.begin(), V.end()));
				nV.push_back(min);
				//cout << i << "-" << min << ", ";

			}
		}
		else {
			if (i % 2 == 0) {
				int min = *min_element(V.begin(), V.end());
				deletenum(min);

				//V.erase(min_element(V.begin(), V.end()));
				nV.push_back(min);
				//cout << i << "-" << min << ", ";

			}
			else {
				
				int max = *max_element(V.begin(), V.end());
				deletenum(max);
				//V.erase(max_element(V.begin(), V.end()));
				nV.push_back(max);
				//cout << i << "-" << max << ", ";
			}
		}
		if (V.size() == 1) {
			break;
		}
		
	}
	
	//cout << "\n";

	if (V.size() == 1) {

		if (abs(nV.front() - V.back()) > abs(nV.back() - V.back())) {
			nV.push_front(V.back());

		}
		else {
			nV.push_back(V.back());
		}
	}

	int sum = 0;
	for (int i = 0; i < n-1; i+=1) {
		int a = nV.front();
		nV.pop_front();
		int b = nV.front();
	//	cout << a << " ";
		sum += abs(a - b);

		
	}
	//cout << "\n";
	cout << sum;
	return 0;


}
