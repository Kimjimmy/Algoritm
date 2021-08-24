#include<iostream>
#include<vector>
#include<stack>

using std::endl;
using std::cout;

// using std::stack ( O(n) ) <----  instead of double for loop( O(n^2) )  which i used to solve.

std::vector<int> solution(std::vector<int> prices) {
	std::vector<int> answer(prices.size());

	std::stack<int> st;  // �� stack ���� vector<int> prices�� �ε����� ���Ŵ�.
	// stack�� ���� ���� ������ �ȵǱ� ������ stack�� index�� �����Ͽ� ���� ã�� ������ vector[�ε���] ���·� �� ���̴�.
	// �̷��� �ؼ��� stack�� ����ϴ� ������ stack�� ������� �ʰ� ������ Ǯ�� ���� for������ O(n^2) �� �ð����⵵�� ������ �����̴�.

	for (int i = 0; i < prices.size(); i++) {
		while (!st.empty() && prices[st.top()] > prices[i]) {

			answer[st.top()] = i - st.top();
			st.pop();
		}
		st.push(i);  // ���� �ε��� push
	}
	while (!st.empty()) { // ���ÿ� �����ִ� ���� ���� �۾����� ���� �ε��� ���̴�.
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
