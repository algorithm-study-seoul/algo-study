// https://www.acmicpc.net/problem/13458
// ���͵� Ǯ ����

#include<iostream>
#include<vector>

using namespace std;

int N;
long long ans;		// int���� �ʰ� �������ϸ� ���ذ����� ����
vector<int> v;
int B, C;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	cin >> B >> C;

	for (int i = 0; i < v.size(); i++) {
		int temp = v[i];

		ans++;
		temp = temp - B;
		if (temp > 0) {
			if(temp % C == 0)
				ans += temp / C;
			else {
				ans += temp / C + 1;
			}
		}
	}
	
	cout << ans << '\n';

	return 0;
}