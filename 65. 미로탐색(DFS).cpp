#include <iostream>
using namespace std;

/*
65. 미로탐색(DFS)
7*7 격자판 미로를 탈출하는 경로의 가지수를 출력하는 프로그램을 작성하세요. 출발점은 격
자의 (1, 1) 좌표이고, 탈출 도착점은 (7, 7)좌표이다. 격자판의 1은 벽이고, 0은 통로이다. 격
자판의 움직임은 상하좌우로만 움직인다. 미로가 다음과 같다면
출 0 0 0 0 0 0
 0 1 1 1 1 1 0
 0 0 0 1 0 0 0
 1 1 0 1 0 1 1
 1 1 0 0 0 0 1
 1 1 0 1 1 0 0
 1 0 0 0 0 0 도착
위의 지도에서 출발점에서 도착점까지 갈 수 있는 방법의 수는 8가지이다.
▣ 입력설명
첫 번째 줄부터 7*7 격자의 정보가 주어집니다.
▣ 출력설명
첫 번째 줄에 경로의 가지수를 출력한다.*/int dx[4] = { 0, 0, -1, 1 };  //상하좌우
int dy[4] = { 1, -1, 0, 0 };class node {public: 	int value;	bool visit;	node() {		value = 9;		visit = false;	}	node(int n) {		value = n;		visit = false;	}};void DFS(node**, int, int, int, int*);int main() {
	node** a = new node * [9];
	int count = 0;
	for (int i = 0; i < 9; i += 8) a[i] = new node[9];
	for (int i = 1; i <= 7; i++) {
		a[i] = new node[9];
		for (int j = 1; j <= 7; j++) cin >> a[i][j].value;
	}
	a[1][1].visit = true;
    DFS(a, 7, 1, 1, &count);
	cout << count;
	delete[] a;
	return 0;
}

void DFS(node** a, int size, int x, int y, int* count) {
	if (x == size && y == size) {
		(*count)++;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (a[x + dx[i]][y + dy[i]].value == 0 && a[x + dx[i]][y + dy[i]].visit == false) {
			a[x + dx[i]][y + dy[i]].visit = true;
			DFS(a, size, x + dx[i], y + dy[i], count);
			a[x + dx[i]][y + dy[i]].visit = false;
		}
	}
	return;
}

/* for (int i = 0; i < 9; i++) {
	for (int j = 0; j < 9; j++) cout << a[i][j] << " ";
	cout << endl;
}*/