#include<iostream>
#include<algorithm>
#include <queue>

// ��������� radix Sort ���� �˰� �����ϰ� ���� Ǯ����. �Ʒ��� �ڵ�� radix ����.

// ���� Q 10989.
// �������� ������ N (1 <= N <= 10,000,000 ) �� �־����ٰ� ������ ���Դ�.
// �켱 ������ ũ�Ⱑ õ������ ũ�� ������ o(n^2) �˰������� Ǯ�� �ȵȴ�.
// �����ٳ� nlogn ���ٰ� õ���� �־ 2���� ���� �Ѵ´�. ä�� �ý��ۿ����� 2��� ������ ����ó���� �� ������ ���� ���귮�̴�.
// �׷��� ������ �̷� ������ ���������� �־����� �̱⶧���� ī���� ����(�������)�� ���� �˰����� ����ϸ� ������ �ذ� �� �� �ִ�.
// ��� ���� ���� ��쿡�� ������ ������ (N) �� ������ �ƹ��� ���ٰ� �ϴ���,
// Ư�� ���� ������ �־����� ȿ�������� ������ Ǯ���ֵ��� ���ش�.

using std::endl;
using std::cout;
using std::cin;

int input[10001] = { 0, };
std::queue<int> que[10];

void radixSort(int* arr, int n) {
	// ���� ū�� ���ϰ�
	int maxNumber=0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > maxNumber) {
			maxNumber = arr[i];
		}
	}
	// ���� ū���� �ڸ���( ���� ū �ڸ��� ) ���ϰ�
	int radix=1;
	while (maxNumber >= radix) {
		radix *= 10;
	}  // ���� ū ���� �ڸ��� ���ϱ�.
	// for (; radix < maxValue; radix *= 10) {}

	// 0~9���� �ִ� que�� ����.
	for (int i = 1; i < radix; i *= 10) {
		for (int j = 0; j < n; j++) { // �� ���鼭 
			if (arr[j] < i) {  // i ���� ������ que[0]�� �־��ش�.
				que[0].push(arr[j]);
			}
			else {
				que[(arr[j] / i) % 10].push(arr[j]);

			}
		}
		// que ������ ������� ������,���� �ڸ��� �豳.
		for (int z = 0,p=0; z < 10; z++) {
			while (!que[z].empty()) {
				arr[p] = que[z].front();  // �� ���� ����.
				que[z].pop();  // front()�� ���ϸ� ���ִ� pop()���� que�� ���Ҹ� �������� ������ while�� ���ѷ����� ���� �ȴ�.
				p++;
			}
		}
	}
}

int main() {
	int n = 0;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	radixSort(input,n);

	for (int i = 0; i < 10001; i++) {
		while (input[i] != 0) {
			cout << input[i] << '\n';
			input[i]--;
		}
	}

	return 0;
}