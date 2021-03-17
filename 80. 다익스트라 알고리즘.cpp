#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
80. 다익스트라 알고리즘
아래의 가중치 방향그래프에서 1번 정점에서 모든 정점으로의 최소 거리비용을 출력하는 프로
그램을 작성하세요. (경로가 없으면 Impossible를 출력한다)
▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보와 거리비용이 주어진다.
▣ 출력설명
1번 정점에서 각 정점으로 가는 최소 비용을 2번 정점부터 차례대로 출력하세요.*/int** a;int* b;bool* c;int n, m;int cnt = 0;void dijkstra(int num);int main() {	cin >> n >> m;	a = new int* [n + 1];	b = new int[n + 1];	c = new bool[n + 1];	for (int i = 0; i < n + 1; i++) {		b[i] = 1000000;		c[i] = false;	}	for (int i = 0; i < n + 1; i++) {		a[i] = new int[n+1];		for (int j = 0; j < n + 1; j++) a[i][j] = 0;	}	for (int i = 0; i < m; i++) {		int num1, num2, k;		cin >> num1 >> num2 >> k;		a[num1][num2] = k;	}		b[1] = 0;	dijkstra(1);	for (int i = 2; i < n + 1; i++) {		if(b[i]== 1000000)			cout << i << " : impossible" << endl;		else cout << i <<" : "<< b[i]<<endl;	}	delete[] a;	delete b;	return 0;}void dijkstra(int num) {	c[num] = true;	if (cnt == m) return;	int min = 0;	for (int i = 1; i < n + 1; i++) {		if (a[num][i] != 0) {			b[i] = (b[i] > b[num] + a[num][i]) ? b[num] + a[num][i] : b[i];			cnt++;		}	}	for (int i = 1; i < n + 1; i++) {		if (c[i]==false)			min = (b[min] > b[i]) ? i : min;	}	if (min == 0) return;	dijkstra(min);	return;}   //벡터로 하면 연산줄이고, 간선의 우선순위 큐 사용해보기