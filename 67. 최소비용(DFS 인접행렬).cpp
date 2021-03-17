#include <iostream>
using namespace std;

67. 최소비용(DFS : 인접행렬)
가중치 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 최소비용을 출력하는 프로그
램을 작성하세요.
▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보가 주어진다.
▣ 출력설명
총 가지수를 출력한다.*/

void DFS(int**,bool*, int, int, int*, int*);

int main() {
	int n, m, sum = 0, min=100000000;
	cin >> n >> m;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++)a[i][j] = 0;
	}
	for (int i = 0; i < m; i++) {
		int b, c, k;
		cin >> b >> c >> k;
		a[b - 1][c - 1] = k;
	}
	min = (a[0][n - 1] != 0) ? a[0][n - 1] : min;
	for (int i = 1; i < n - 1; i++) {
		sum = 0;
		bool* visit = new bool[n];
		for (int j = 0; j < n; j++) visit[j] = false;
		if (a[0][i] != 0) {
			visit[0] = true;
			sum += a[0][i];
			DFS(a, visit, i, n, &sum, &min);
		}
		delete[] visit;
	}
	
	cout << min;
	delete[] a;
	return 0;
}

void DFS(int** a, bool* visit, int num, int size, int* sum, int* min) {
	if (a[num][size - 1] != 0) {
		*sum += a[num][size - 1];
		*min = *min < *sum ? *min : *sum;
		*sum -= a[num][size - 1];
	}
	for (int i = 1; i < size - 1; i++) {
		if (a[num][i] != 0 && visit[i] == false) {
			visit[i] = true;
			*sum += a[num][i];
			DFS(a, visit, i, size, sum, min);
			visit[i] = false;
			*sum -= a[num][i];
		}
	}
}        //bool배열 밖으로!, 48번에 조건을 바꿔서 num==size하면 49,51문장 필요없음!