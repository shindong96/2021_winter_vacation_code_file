#include <iostream>
#include <queue>
using namespace std;

/*
87. 섬나라 아일랜드(BFS 활용)
섬나라 아일랜드의 지도가 격자판의 정보로 주어집니다. 각 섬은 1로 표시되어 상하좌우와 대
각선으로 연결되어 있으며, 0은 바다입니다. 섬나라 아일랜드에 몇 개의 섬이 있는지 구하는
프로그램을 작성하세요.
1 1 0 0 0 1 0
0 1 1 0 1 1 0
0 1 0 0 0 0 0
0 0 0 1 0 1 1
1 1 0 1 1 0 0
1 0 0 0 1 0 0
1 0 1 0 1 0 0
만약 위와 같다면
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=20)이 주어집니다.
두 번째 줄부터 격자판 정보가 주어진다.
▣ 출력설명
첫 번째 줄에 섬의 개수를 출력한다.
*/

class node {
public:
	int x; 
	int y;

	node() {
		x = y = 0;
	}
	node(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int n, cnt;
int** a;
bool** flag;
queue<node> q;
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };

void BFS() {
	if (q.empty()) return;
	int size = q.size();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 8; j++) {
			if (q.front().x + dx[j] == -1 ||
				q.front().x + dx[j] == n ||
				q.front().y + dy[j] == -1 ||
				q.front().y + dy[j] == n) continue;
			if (a[q.front().y + dy[j]][q.front().x + dx[j]]==1
				&&!flag[q.front().y + dy[j]][q.front().x + dx[j]]) {
				node n(q.front().x + dx[j], q.front().y + dy[j]);
				q.push(n);
			}
			flag[q.front().y + dy[j]][q.front().x + dx[j]] = true;
		}
		q.pop();
	}
	BFS();
}

int main() {
	cin >> n;
	a = new int* [n];
	flag = new bool* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		flag[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			flag[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!flag[i][j]&&a[i][j]==1) {
				node n(j, i);
				q.push(n);
				BFS();
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}             //정형화된 방법은 재귀안쓰고 while(empty)써서 한방!