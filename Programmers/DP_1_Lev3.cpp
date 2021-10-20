#include<iostream>
#include<vector>
#include<unordered_set>

using std::cin; using std::cout;
using std::vector;

int n, number;
vector<std::unordered_set<int>> opt; // opt[1] 은 n을 1번 사용해서 나타낼수 있는 수의 집합... opt[n] = n을 n번 사용해서 나타낼수 있는 수의 집합.

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
		/*cout << "opt[" << i << "] 번째 U_set에 담겨 있는 원소는 ? : " << '\n';
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
	opt.resize(8 + 1); // 8보다 크면 -1 출력할 예정. 인덱스 1 부터 쓰기 위해 8+1로 resize

	dp();


	return 0;
}