#include <string>
#include<iostream>
#include <vector>
#include<deque>
#include<queue>

// ����� kit [Queue]  �ٸ��� �������� Ʈ��
using namespace std;  

template<typename T>
void clocking(T& t,int bridge_length) {

	for (size_t i = 0; i <= t.size()-1;i++) {
		t[i].second++;
	}
}
                  //   2              10           7,4,5,6
int solution(int bridge_length, int weight, vector<int> truck_weights) {

	int answer = 0;
	deque<pair<int,int>>bridge;
	queue<int> truck; 
	int sum_of_trucks_weight=0;


	// �տ������� ���� ���� queue �� �Ű��ش�. ���� vector.front()�� �� �������� erase�� ����� �ص� �ȴ�. �̵��� �غ���.
	for (const auto& elem : truck_weights) {
		truck.push(elem);
	}
	while(!truck.empty()|| !bridge.empty()){ // Ʈ�� ť�� ��� �ٸ� ť�� ��������.
		
		for (int i = 0; i < bridge_length; i++) {

			if (truck.empty()) {
				while (!(bridge.front().second >= bridge_length)) { // Ʈ���� ��������
					clocking(bridge, bridge_length); // �ٸ����� Ʈ���� �ð� +1
					answer++;  // �� �ɸ� �ð� +1
				}
				bridge.pop_front(); // �ٸ� ť���� Ʈ�� ����.
				break;
			}

			if (sum_of_trucks_weight + truck.front() <= weight) { // �ٸ� �� ��� ���Ժ��� ������ �ٸ� ť�� Ʈ�� push
				sum_of_trucks_weight += truck.front();
				bridge.push_back(make_pair(truck.front(),0));
				truck.pop();  // �ٸ� ť�� �ö����� Ʈ�� ť���� ����.
				clocking(bridge,bridge_length); // �ٸ����� Ʈ���� �ð� +1
				answer++; // �� �ɸ� �ð� +1
				
			}
			else {
				clocking(bridge,bridge_length); // �ٸ����� Ʈ���� �ð� +1
				answer++;  // �� �ɸ� �ð� +1
			}
			
			if (bridge.front().second >= bridge_length) { // Ʈ���� ��������
				
				sum_of_trucks_weight -= bridge.front().first;  // Ʈ�� ���� �տ��� ������ Ʈ�� ���� ���ְ�
				bridge.pop_front(); // �ٸ� ť���� Ʈ�� ����.
			}
		}
	}
		
		return answer+1;
}

int main() {
	vector<int> a(10, 10);
	cout << solution(100, 100, a);

	return 0;
}