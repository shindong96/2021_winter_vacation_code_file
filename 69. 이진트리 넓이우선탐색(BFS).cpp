#include <iostream>
#include <vector>
using namespace std;

/*
69. 이진트리 넓이우선탐색(BFS)
아래 그림과 같은 이진트리를 넓이우선탐색해 보세요. 간선 정보 6개를 입력받아 처리해보세
요.
   1 
 2   3
4 5 6 7
넓이 우선 탐색 : 1 2 3 4 5 6 7
*/

class vertex {
public:
	int value;
	vector<vertex*> vertex_list;

	vertex() {
		value = 0;
	}

	vertex(int n) {
		value = n;
	}
};

void BFS(vertex* v) {
	if (v->vertex_list.size() == 0) return;
	for (int i = 0; i < v->vertex_list.size(); i++)
		cout << v->vertex_list[i]->value << " ";
	for (int i = 0; i < v->vertex_list.size(); i++)
		BFS(v->vertex_list[i]);
}

int main() {
	vertex* a = new vertex[8];
	for (int i = 1; i <= 7; i++) a[i].value = i;
	for (int i = 0; i < 6; i++) {
		int b, c;
		cin >> b >> c;
		a[b].vertex_list.push_back(&a[c]);
	}
	cout << a[1].value << " ";
	BFS(&a[1]);
	delete[] a;
	return 0;
}             //BFS가 뭔지 공부, queue쓰는게 정석