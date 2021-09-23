#include <string>
#include <vector>
#include<iostream>

using namespace std;


int solution(vector<int> numbers, int target) {


	if (numbers.size() == 0 && target == 0) {
		return 1;
	}
	else if (numbers.size() == 0) {
		return 0;
	}

	int temp = numbers[0];
	numbers.erase(numbers.begin());

	return solution(numbers, target + temp) + solution(numbers, target - temp);

}

int main() {
	vector<int> numbers = { 3,2,3,2,1 };

	cout << solution(numbers, 5);

	return 0;
}