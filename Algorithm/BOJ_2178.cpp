#include<iostream>
#include<queue>


using namespace std;

unsigned int n, m;
char a;
queue<pair<int,int>> q;
int level;
bool visited[100][100] = { false, };
int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,1,0,-1 };

template<typename T>
int Bfs(T& arr) {
	int row=0, col = 0;
	q.push(make_pair(row,col));
	visited[row][col] = true;
	while (!q.empty()) {
		
		row = q.front().first;
		col = q.front().second;
		if (row == n - 1 && col == m - 1) return arr[row][col];
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			
			int next_row = row + dir_x[i];
			int next_col = col + dir_y[i];
			if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m && arr[next_row][next_col] == 1) {
				if (!visited[next_row][next_col]) {
					arr[next_row][next_col]= arr[row][col]+1;
					q.push(make_pair(next_row, next_col));
					
				}
			}
		}
		
	}
	
	return 0;
}

int main() {

	cin >> n >> m;
	int** arr = new int*[n];

	cin.ignore(10, '\n');
	for (unsigned int i = 0; i < n; i++) {
		arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			a=cin.get();
			arr[i][j] = a - '0';
		}
		cin.ignore(10, '\n');
	}
	cout << Bfs(arr);
	return 0;
}