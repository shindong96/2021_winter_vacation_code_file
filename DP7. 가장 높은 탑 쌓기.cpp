#include <iostream>
#include <algorithm>
using namespace std;

/*
가장 높은 탑 쌓기
밑면이 정사각형인 직육면체 벽돌들을 사용하여 탑을 쌓고자 한다. 탑은 벽돌을 한 개씩 아래
에서 위로 쌓으면서 만들어 간다. 아래의 조건을 만족하면서 가장 높은 탑을 쌓을 수 있는 프
로그램을 작성하시오.
(조건1) 벽돌은 회전시킬 수 없다. 즉, 옆면을 밑면으로 사용할 수 없다.
(조건2) 밑면의 넓이가 같은 벽돌은 없으며, 또한 무게가 같은 벽돌도 없다.
(조건3) 벽돌들의 높이는 같을 수도 있다.
(조건4) 탑을 쌓을 때 밑면이 좁은 벽돌 위에 밑면이 넓은 벽돌은 놓을 수 없다.
(조건5) 무게가 무거운 벽돌을 무게가 가벼운 벽돌 위에 놓을 수 없다.
▣ 입력설명
입력 파일의 첫째 줄에는 입력될 벽돌의 수가 주어진다. 입력으로 주어지는 벽돌의 수는 최대
100개이다. 둘째 줄부터는 각 줄에 한 개의 벽돌에 관한 정보인 벽돌 밑면의 넓이, 벽돌의 높
이 그리고 무게가 차례대로 양의 정수로 주어진다. 각 벽돌은 입력되는 순서대로 1부터연속적
인 번호를 가진다.
▣ 출력설명
첫 번째 줄에 가장 높이 쌓을 수 있는 탑의 높이를 출력한다.*/class node {public: 	int width;	int height;	int weight;	node() {		width = height = weight = 0;	}	node(int width, int height, int weight) {		this->width = width;		this->height = height;		this->weight = weight;	}	bool operator <(const node& n) {		return width > n.width;	}};int n, max_height;node* nod;int* a;int main() {	cin >> n;	nod = new node[n];	a = new int[n];	for (int i = 0; i < n; i++) 		cin >> nod[i].width >> nod[i].height >> nod[i].weight;	sort(nod, nod + n);	for (int i = 0; i < n; i++) {		int height = 0;		for (int j = i - 1; j >= 0; j--) {			if (nod[i].weight < nod[j].weight)				height = height > a[j] ? height : a[j];		}		a[i] = nod[i].height + height;		max_height = max_height > a[i] ? max_height : a[i];	}	cout << max_height;	return 0;}                      //우선순위 큐를 쓰면 가능할 것 같다.(DP큰 것 순, 같으면 weight가 큰 것 순)/* 잘못된 코드int n, max_height, max_weight;node* nod;bool* flag;int main() {	cin >> n;	nod = new node[n];	for (int i = 0; i < n; i++) {		cin >> nod[i].width >> nod[i].height >> nod[i].weight;		max_weight = (max_weight > nod[i].weight) ? max_weight : nod[i].weight;	}	flag = new bool[max_weight];	sort(nod, nod + n);	for (int i = 0; i < n; i++)cout << nod[i].weight << " ";	cout << endl;	for (int i = 0; i < n; i++) {		if (!flag[nod[i].weight]) break;		cout << nod[i].weight << " ";		int sum_height = nod[i].height;		int weight = nod[i].weight;		for (int j = i+1; j < n; j++) {			if (weight > nod[j].weight) {				cout << nod[j].weight << " ";				sum_height += nod[j].height;				flag[nod[j].weight] = false;				weight = nod[j].weight;			}		}		cout << endl;		max_height = max_height > sum_height ? max_height : sum_height;	}	cout << max_height;	return 0;}*/