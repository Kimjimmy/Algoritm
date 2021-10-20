#include<iostream>
#include<vector>
#include<algorithm>


using std::cin; using std::cout;
using std::vector;
vector<vector<int>> triangle{ {7},{3,8},{8,1,0},{2,7,4,4},{4,5,2,6,5} };
int opt[501][501];

void dp() {
	int h = triangle.size();

	opt[0][0] = triangle[0][0];

	for (int i = 1; i < h; i++) {
		opt[i][0] = opt[i - 1][0] + triangle[i][0];
		opt[i][i] = opt[i - 1][i - 1] + triangle[i][i];
		for (int j = 1; j <= i - 1; j++) {
			if (opt[i - 1][j - 1] + triangle[i][j] > opt[i - 1][j] + triangle[i][j])
				opt[i][j] = opt[i - 1][j - 1] + triangle[i][j];
			else opt[i][j] = opt[i - 1][j] + triangle[i][j];
		}

	}
	cout << *std::max_element(opt[4], opt[4] + 5);

}


int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	dp();


	return 0;
}