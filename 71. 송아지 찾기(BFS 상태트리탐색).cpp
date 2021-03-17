#include <iostream>
#include <cmath>
using namespace std;

/*
71. 송아지 찾기(BFS : 상태트리탐색)
현수는 송아지를 잃어버렸다. 다행히 송아지에는 위치추적기가 달려 있다. 현수의 위치와 송아
지의 위치가 직선상의 좌표 점으로 주어지면 현수는 현재 위치에서 송아지의 위치까지 다음과
같은 방법으로 이동한다.
현수는 스카이 콩콩을 타고 가는데 한 번의 점프로 앞으로 1, 뒤로 1, 앞으로 5를 이동할 수
있다. 최소 몇 번의 점프로 현수가 송아지의 위치까지 갈 수 있는지 구하는 프로그램을 작성
하세요.
▣ 입력설명
첫 번째 줄에 현수의 위치 S와 송아지의 위치 E가 주어진다. 직선의 좌표 점은 1부터 10,000
까지이다.
▣ 출력설명
점프의 최소횟수를 구한다.*/

int dx[3] = { 1,-1,5 };

void BFS(int*, int, int num);

int main() {
	int n, m;
	cin >> n >> m;
	int* result = new int(n);
	BFS(result, 0, m);
	delete result;
	return 0;
}

void BFS(int* result, int count, int m) {
	if (*result == m) {
		cout << count;
		return;
	}
	int* res = new int[3];
	int min = 0;
	for (int i = 0; i < 3; i++) {
		res[i] = *result + dx[i];
		min = (abs(res[i] - m) > abs(res[min] - m)) ? min : i;
	}
	BFS(&res[min], count+1, m);
	delete[] res;
	return;
}                //숫자가 달라지면 잘못된다...BFS를 써보자


/*규준씨 풀이

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number;
int nodenumber=2;
int c[21];
vector <int> a[21]; // 벡터 2차원 배열
vector <int> b(21) ;

void bfs(int start) {
   int min = 214700000;
   queue<int> q;
   q.push(start);
   c[start] = true;
   while (!q.empty()) { // 큐가 빌때까지
	  int copy = q.size();
	  for (int j = 0; j < copy; j++) {
		 int x = q.front(); // q의 첫번째 원소


		 if (b[x] > number)
			b[x] = number;

		 q.pop();


		 for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (!c[y]) { // 방문한 상태가 아니라면
			   q.push(y); // q에 담아줌
			   c[y] = true; // 방문처리

			}

		 }
	  }
	  number++;

   }
}

int main() {
   int N, M;
   int input1, input2;
   fill(b.begin(), b.end(), 214700000);

   cin >> N>>M;
   for (int i = 0; i < M; i++) {
	  cin >> input1;
	  cin >> input2;
	  a[input1].push_back(input2);
   }
   bfs(1);

   for(int i=2;i<=N;i++)
   cout <<i << " : " << b[i] << endl;
}*/