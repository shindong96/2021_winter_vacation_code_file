#include <iostream>
#include <queue>
using namespace std;

/*
88. 미로의 최단거리 통로(BFS 활용)
7*7 격자판 미로를 탈출하는 최단경로의 경로수를 출력하는 프로그램을 작성하세요. 경로수는
출발점에서 도착점까지 가는데 이동한 횟수를 의미한다. 출발점은 격자의 (1, 1) 좌표이고, 탈
출 도착점은 (7, 7)좌표이다. 격자판의 1은 벽이고, 0은 도로이다.
격자판의 움직임은 상하좌우로만 움직인다. 미로가 다음과 같다면
출발 0 0 0 0 0 0
0 1 1 1 1 1 0
0 0 0 1 0 0 0
1 1 0 1 0 1 1
1 1 0 1 0 0 0
1 0 0 0 1 0 0
1 0 1 0 0 0 도착
위와 같은 경로가 최단 경로이며 경로수는 12이다.
▣ 입력설명
첫 번째 줄부터 7*7 격자의 정보가 주어집니다.
▣ 출력설명
첫 번째 줄에 최단으로 움직인 칸의 수를 출력한다. 도착할 수 없으면 -1를 출력한다.*/class node {public:	int x;	int y;	node() {		x = y = 0;	}	node(int x, int y) {		this->x = x;		this->y = y;	}};int cnt;int a[7][7];bool flag[7][7];bool r = false;int dx[4] = { 0,-1,1,0 };int dy[4] = { -1,0,0,1 };queue<node> q;void BFS() {	if (q.empty() || r) return;	int size = q.size();	for (int i = 0; i < size; i++) {		for (int j = 0; j < 4; j++) {			if (q.front().x + dx[j] == -1 ||				q.front().x + dx[j] == 7 ||				q.front().y + dy[j] == -1 ||				q.front().y + dy[j] == 7) continue;			if (q.front().y + dy[j] == 6 && q.front().x + dx[j] == 6) {				r = true;				cnt++;				return;			}			if (a[q.front().y + dy[j]][q.front().x + dx[j]] == 0
				&& !flag[q.front().y + dy[j]][q.front().x + dx[j]]) {				node n(q.front().x + dx[j], q.front().y + dy[j]);
				q.push(n);			}			flag[q.front().y + dy[j]][q.front().x + dx[j]] = true;		}		q.pop();	}	cnt++;	BFS();}int main() {
	for (int i = 0; i < 7; i++) {		for (int j = 0; j < 7; j++) {			cin >> a[i][j]; 			flag[i][j] = false;		}	}	node n(0, 0);	q.push(n);	BFS();	if (!r) cout << "-1";	else cout << cnt;	return 0;}