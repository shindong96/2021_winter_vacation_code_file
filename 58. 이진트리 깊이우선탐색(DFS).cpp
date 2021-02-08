#include <iostream>
#include <vector>
using namespace std;

/*
아래 그림과 같은 이진트리를 전위순회와 후위순회를 연습해보세요.
     1
  2     3
 4 5   6 7
전위순회 출력 : 1 2 4 5 3 6 7
중위순회 출력 : 4 2 5 1 6 3 7
후위순회 출력 : 4 5 2 6 7 3 1*/

class node {
public:
	int value;
	node* right;
	node* left;
	

	node() {
		value = 0;
		right = NULL;
		left = NULL;
	}

	node(int n) {
		value = n;
		right = NULL;
		left = NULL;
	}
};

class DFS {
public:
	node* first;
	vector<node*> node_list;

	DFS(int n) {
		first = new node(n);
		node_list.push_back(first);
	}

	void insert(int n) {
		int i = 0;
		node* nod = new node(n);
		while (i < node_list.size()) {
			if (node_list[i]->left == NULL) {
				node_list[i]->left = nod;
				node_list.push_back(nod);
				break;
			}
			else if (node_list[i]->right == NULL) {
				node_list[i]->right = nod;
				node_list.push_back(nod);
				break;
			}
			else i++;
		}
		return;
	}

	void preorder(node* nod) {
		if (nod == NULL) return;
		cout << nod->value << " ";
		preorder(nod->left);
		preorder(nod->right);
		return;
	}

	void inorder(node* nod) {
		if (nod == NULL) return;
		inorder(nod->left);
		cout << nod->value << " ";
		inorder(nod->right);
		return;
	}

	void postorder(node* nod) {
		if (nod == NULL) return;
		postorder(nod->left);
		postorder(nod->right);
		cout << nod->value << " ";
		return;
	}
};

int main() {
	DFS dfs(1);
	for (int i = 0; i < 6; i++) {
		int num;
		cin >> num;
		dfs.insert(num);
	}
	dfs.preorder(dfs.first);
	cout << endl;
	dfs.inorder(dfs.first);
	cout << endl;
	dfs.postorder(dfs.first);
	cout << endl;
	return 0;
}

/*
모범 답안

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
void D(int x){
	if(x>7) return;
	else{
		printf("%d ", x);
		D(x*2);
		D(x*2+1);
	}
}
int main(){
	freopen("input.txt", "rt", stdin);
	D(1);
	return 0;
}*/