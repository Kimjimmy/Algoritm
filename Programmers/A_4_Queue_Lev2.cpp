#include<iostream>
#include<vector>
#include<stack>

using std::endl;
using std::cout;

// using std::stack ( O(n) ) <----  instead of double for loop( O(n^2) )  which i used to solve.

std::vector<int> solution(std::vector<int> prices) {
	std::vector<int> answer(prices.size());

	std::stack<int> st;  // 이 stack 에는 vector<int> prices의 인덱스가 들어갈거다.
	// stack은 임의 원소 접근이 안되기 때문에 stack에 index를 저장하여 값을 찾아 볼때는 vector[인덱스] 형태로 할 것이다.
	// 이렇게 해서라도 stack을 사용하는 이유는 stack을 사용하지 않고 문제를 풀면 이중 for문으로 O(n^2) 의 시간복잡도를 가지기 때문이다.

	for (int i = 0; i < prices.size(); i++) {
		while (!st.empty() && prices[st.top()] > prices[i]) {

			answer[st.top()] = i - st.top();
			st.pop();
		}
		st.push(i);  // 현재 인덱스 push
	}
	while (!st.empty()) { // 스택에 남아있는 값은 값이 작아지지 않은 인덱스 들이다.
		answer[st.top()] = prices.size() - st.top() - 1;
		st.pop();
	}

	return answer;
}


int main() {
	std::vector<int> answer = { 1,2,3,2,3 };

	
	for(std::size_t i=0;i<answer.size();i++)
	cout << (solution(answer))[i] << endl;

	return 0;
}
