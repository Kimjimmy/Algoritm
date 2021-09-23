#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

std::vector<std::string> words{ "hot","dot","dog","lot","log","cog" };
std::queue<std::string> que;
std::map<std::string, int> visited;

int solution(std::string begin, std::string target, std::vector<std::string>& words) {

	// words에 target이 없다면 return 0;
	auto it = std::find(words.begin(), words.end(), target);
	if (it == words.end())return 0;


	int answer = 0;
	que.push(begin);
	visited[begin] = 0;

	while (!que.empty()) {
		auto cur = que.front();
		if (cur == target)return visited[cur];
		que.pop();

		for (int i = 0; i < words.size(); i++) {
			int cnt = 0;
			for (int j = 0; j < words[i].length(); j++) {
				if (words[i][j] != cur[j]) cnt++;
				if (cnt == 2)break;
			}
			if (cnt == 1) { // if diffrence btw (word[i],cur) is just a word
				auto next = words[i];
				if (!visited[next]) {
					que.push(next);
					visited[next] = visited[cur] + 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	string begin = "hit";
	string target = "dog";

	cout << solution(begin, target, words);


	return 0;
}