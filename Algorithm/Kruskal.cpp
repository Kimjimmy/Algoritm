#include<iostream>
#include<vector>
#include<algorithm>


int parent[1001];
int p_size[1001];

class Edge {
public:
	int node[2];
	int distance;
	int p;

	Edge(int a, int b, int _distance): distance(_distance) {
		node[0] = a;
		node[1] = b;
	};
	bool operator <(Edge& edge) {
		return distance < edge.distance;
	}
};

int findSet(int* parent, int x) {
	if (parent[x] != x) {
		parent[x] = findSet(parent, parent[x]);
	}
	return parent[x];
}
void Union(int* parent, int a, int b) {
	a = findSet(parent, a);
	b = findSet(parent, b);
	if (p_size[a] > p_size[b]) {
		parent[b] = a;
		p_size[a] = p_size[a] +p_size[b];
	}
	else {
		parent[a] = b;
		p_size[b] = p_size[b] + p_size[b];
	}
}


int main() {
	int n = 7;
	int m = 11;

	std::vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(5, 7, 73));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(4, 2, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 3, 20));
	v.push_back(Edge(6, 3, 37));
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 7, 12));


	// ������ ����� �������� �������� ����
	std::sort(v.begin(), v.end());

	// �� ����� �θ� ��带 �迭�� ��Ÿ��.
	// �ʱ⿡�� �ڱ� �ڽ��� �θ� ���� ����.
	for (int i = 0; i < 7; i++) {
		parent[i] = i;
	}
	std::fill_n(p_size, 7, 1);

	int sum = 0; // �Ÿ��� ��.

	//��� ������ ���Ͽ� ����Ŭ�� �߻����� �ʴ� ��� �׷����� �����ش�.
	for (int i = 0; i < v.size(); i++) {
		
		int a = v[i].node[0];
		int b = v[i].node[1];

	// ������ ������ ���� �ٸ� ������ ����϶� �� ����� ���� ������.
		if (findSet(parent, a) != findSet(parent, b) ){
			Union(parent,a,b);
			sum += v[i].distance;
		}
	}
	std::cout <<"�ּ� ���̴� :: "<< sum;
	return 0;
}