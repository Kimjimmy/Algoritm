#include <string>
#include <vector>
#include<iostream>
#include<queue>
#include<cstring>
#include<map>


/*
 �ð� ���⵵: O(n+m)
 ���� ���⵵: O(n)
 ����� �˰���: BFS(�ʺ� �켱 Ž��)
 ����� �ڷᱸ��: ���� ����Ʈ, �迭
 */

using std::cout;


std::vector<std::string> words{ "hot","dot","dog","lot","log","cog" };
std::string begin;
std::string target;
std::queue<std::string> que;
std::map<std::string, int> visited;

int solution(std::string begin, std::string target, std::vector<std::string>& words) {
	int answer = 0;
	que.push(begin);
	visited[begin] = 0;

	while (!que.empty()) {

		if (que.front() == target) return visited[target];
		std::string temp = que.front();
		que.pop();

		for (size_t i = 0; i < words.size(); i++) {
			const char* next = words[i].c_str();
			const char* cur = temp.c_str();
			if (strspn(cur, next)==2&& visited[cur]==0) {
				que.push(next);
				visited[next] = visited[cur] + 1;
			}
		}

	}


	return visited[target];
}

int main() {
	begin = "hit";
	target = "cog";
	
	cout << solution(begin,target,words);


	return 0;
}


/*const char* cbegin = begin.c_str();

	while (!que.empty()) {

		for (int i = 0; i < words.size(); i++) {
			const char* next = words[i].c_str();
			if (strspn(next, cbegin) == 2) {
				que.push(words[i]);
				break;
			}
		}
	}*/