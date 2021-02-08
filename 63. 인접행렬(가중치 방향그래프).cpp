#include <iostream>
#include <vector>
using namespace std;

/*
63. 인접행렬(가중치 방향그래프)
아래 그림과 같은 그래프 정보를 인접행렬로 표현해보세요.

▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보와 거리비용이 주어진다.
▣ 출력설명
인접행렬을 출력하세요.*/

int main() {
	int n, m;
	cin >> n >> m;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++) a[i][j] = 0;
	}
	int b, c, d;
	for (int i = 0; i < m; i++) {
		cin >> b >> c >> d;
		a[b-1][c-1] = d;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

/*
모범 답안

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[21][21];
int main() {
	freopen("input.txt", "rt", stdin);
	int n, m, a, b, c, i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a ,&b, &c);
		map[a][b]=c;
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}*/