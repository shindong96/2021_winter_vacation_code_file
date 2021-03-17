#include <iostream>
#include <vector>
#define UNVISITED 0
#define COME_AND_BACK 1
#define VISIT 2
using namespace std;

/*
70. 그래프 최단거리(BFS)
다음 그래프에서 1번 정점에서 각 정점으로 가는 최소 이동 간선수를 출력하세요.
1 2 5
3 4 6
▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보가 주어진다.
▣ 출력설명
1번 정점에서 각 정점으로 가는 최소 간선수를 2번 정점부터 차례대로 출력하세요.*/class vertex {
public:	int value;	vector<vertex*> vertex_list;	vertex() {		value = 0;	}	vertex(int n) {		value = n;	}};void BFS(vertex*, int*, int);int main() {
	int n, m;	cin >> n >> m;	vertex* a = new vertex[n + 1];	for (int i = 0; i < n + 1; i++) a[i].value = i;	for (int i = 0; i < m; i++) {		int b, c;		cin >> b >> c;		a[b].vertex_list.push_back(&a[c]);	}	for (int i = 2; i < n + 1; i++) {		int* count = new int(0);		BFS(&a[1], count, i);		cout << i << " : " << *count << endl;	}	delete[] a;	delete count;	return 0;}void BFS(vertex* v, int* count, int num) {
	if (v->vertex_list.size() == 0) {		*count = 100;		return;	}	if (v->value == num) {		*count += 1;		return;	}	int* cnt = new int[v->vertex_list.size()];	int min = 100;	for (int i = 0; i < v->vertex_list.size(); i++) {		cnt[i] = 1;		if (v->vertex_list[i]->value == num) { 			*count += 1;			return;		}	}	for (int i = 0; i < v->vertex_list.size(); i++) {		BFS(v->vertex_list[i], &cnt[i], num);		min = (cnt[i] > min) ? min : cnt[i];	}	delete[] cnt;	*count += min;	return;}                   //이건 DFS다..