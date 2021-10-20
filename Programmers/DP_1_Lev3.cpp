#include<iostream>
#include<vector>
#include<unordered_set>

using std::cin; using std::cout;
using std::vector;

int n, number;
vector<std::unordered_set<int>> opt; // opt[1] �� n�� 1�� ����ؼ� ��Ÿ���� �ִ� ���� ����... opt[n] = n�� n�� ����ؼ� ��Ÿ���� �ִ� ���� ����.

void dp() {

	opt[0].insert(0);
	opt[1].insert(n);

	int input = n;
	for (int i = 2; i <= 8; i++) {

		for (int k = 1; k < i; k++) {
			for (std::unordered_set<int>::iterator itr = opt[i - k].begin(); itr != opt[i - k].end(); itr++) {
				for (std::unordered_set<int>::iterator itr2 = opt[k].begin(); itr2 != opt[k].end(); itr2++) {
					opt[i].insert((*itr)*(*itr2));
					opt[i].insert(*itr + (*itr2));
					opt[i].insert(*itr - (*itr2));

					if (*itr != 0) {
						opt[i].insert((*itr2) / *itr);
					}
				}
			}
		}
		input = input * 10 + n;
		opt[i].insert(input);
		/*cout << "opt[" << i << "] ��° U_set�� ��� �ִ� ���Ҵ� ? : " << '\n';
		for (auto elem : opt[i]) {
			cout << elem << " ";
		}
		cout << '\n';
		*/
	}

}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	opt.resize(8 + 1); // 8���� ũ�� -1 ����� ����. �ε��� 1 ���� ���� ���� 8+1�� resize

	dp();


	return 0;
}