#include <iostream>
#include <vector>
using namespace std;

/*
66. 경로 탐색(DFS : 인접리스트 방법)
방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 모든 경로의 가지 수를 출력하는 프
로그램을 작성하세요. 아래 그래프에서 1번 정점에서 5번 정점으로 가는 가지 수는
1 2 3 4 5
1 2 5
1 3 4 5
1 4 2 5
1 4 5
총 6 가지입니다.
▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보가 주어진다.
▣ 출력설명
총 가지수를 출력한다.*/class node {public:	int value;	bool visit;	vector<node*> node_list;	node() {		value = 0;		visit = false;	}	node(int n) {		value = n;		visit = false;	}	void insert(node* nod) {		node_list.push_back(nod);	}	int size() {		return node_list.size();	}};void DFS(node, int, int*);int main() {
	int n, m, count = 0;	cin >> n >> m;	node* a = new node[n+1];	for (int i = 0; i < n + 1; i++) a[i].value = i;	for (int i = 0; i < m; i++) {		int b, c;		cin >> b >> c;		a[b].insert(&a[c]);	}	a[1].visit = true;	DFS(a[1], n, &count);	cout << count;	delete[] a;	return 0;}void DFS(node nod, int n, int* count) {
	for (int i = 0; i < nod.size(); i++) {		if (nod.node_list[i]->value == n) (*count)++;		else if (nod.node_list[i]->visit == false) {			nod.node_list[i]->visit = true;			DFS(*nod.node_list[i], n, count);			nod.node_list[i]->visit = false;		}	}}