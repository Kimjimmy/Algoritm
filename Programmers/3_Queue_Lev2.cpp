#include <string>
#include<iostream>
#include <vector>
#include<deque>
#include<queue>

// 고득점 kit [Queue]  다리를 지나가는 트럭
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


	// 앞에서부터 쓰기 위해 queue 로 옮겨준다. 물론 vector.front()로 값 가져오고 erase로 지우고 해도 된다. 이따가 해보자.
	for (const auto& elem : truck_weights) {
		truck.push(elem);
	}
	while(!truck.empty()|| !bridge.empty()){ // 트럭 큐도 비고 다리 큐도 빌때까지.
		
		for (int i = 0; i < bridge_length; i++) {

			if (truck.empty()) {
				while (!(bridge.front().second >= bridge_length)) { // 트럭이 지나가면
					clocking(bridge, bridge_length); // 다리위의 트럭들 시간 +1
					answer++;  // 총 걸린 시간 +1
				}
				bridge.pop_front(); // 다리 큐에서 트럭 삭제.
				break;
			}

			if (sum_of_trucks_weight + truck.front() <= weight) { // 다리 위 허용 무게보다 작을때 다리 큐에 트럭 push
				sum_of_trucks_weight += truck.front();
				bridge.push_back(make_pair(truck.front(),0));
				truck.pop();  // 다리 큐로 올라갔으니 트럭 큐에서 삭제.
				clocking(bridge,bridge_length); // 다리위의 트럭들 시간 +1
				answer++; // 총 걸린 시간 +1
				
			}
			else {
				clocking(bridge,bridge_length); // 다리위의 트럭들 시간 +1
				answer++;  // 총 걸린 시간 +1
			}
			
			if (bridge.front().second >= bridge_length) { // 트럭이 지나가면
				
				sum_of_trucks_weight -= bridge.front().first;  // 트럭 무게 합에서 지나간 트럭 무게 빼주고
				bridge.pop_front(); // 다리 큐에서 트럭 삭제.
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