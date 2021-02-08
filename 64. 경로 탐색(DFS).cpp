﻿#include <iostream>
using namespace std;

/*
64. 경로 탐색(DFS)
방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 모든 경로의 가지 수를 출력하는 프
로그램을 작성하세요. 아래 그래프에서 1번 정점에서 5번 정점으로 가는 가지 수는
1 2 3 4 5
1 2 5
1 3 4 2 5
1 3 4 5
1 4 2 5
1 4 5
총 6 가지입니다.
▣ 입력설명
첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연
결정보가 주어진다.
▣ 출력설명
총 가지수를 출력한다.
*/

void DFS(int** a, bool* visit, int num, int size, int* count) {
	if (a[num][size - 1] == 1) (*count)++;
	for (int i = 0; i < size-1; i++) {
		if (visit[i] == false && a[num][i] == 1) {
			visit[i] = true;
			DFS(a, visit, i, size, count);
			visit[i] = false;
		}
	}
	return;
}

int main() {
	int n, m, count = 0;
	cin >> n >> m;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++) a[i][j] = 0;
	}
	for (int i = 0; i < m; i++) {
		int b, c;
		cin >> b >> c;
		a[b - 1][c - 1] = 1;
	}
	if (a[0][n-1] == 1) count++;
	for (int i = 0; i < n-1; i++) {
		bool* visit = new bool[n];
		for (int j = 0; j < n; j++) visit[j] = false;
		visit[0] = true;
		if (a[0][i] == 1) {
			visit[i] = true;
			DFS(a, visit, i, n, &count);
		}
		delete[] visit;
	}
	cout << count;
	delete[] a;
	return 0;
}   //돌아갈 때 플래그 초기화

/*
모범 답안


#include<stdio.h>
int map[30][30], ch[30], cnt=0, n;
void DFS(int v){
	int i;
	if(v==n){
		cnt++;
	}
	else{
		for(i=1; i<=n; i++){
			if(map[v][i]==1 && ch[i]==0){
				ch[i]=1;
				DFS(i);
				ch[i]=0;
			}
		}
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	int m, i, j, a, b, c;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		map[a][b]=1;
	}
	ch[1]=1;
	DFS(1);
	printf("%d\n", cnt);
	return 0;
}




<경로도 함께 출력하는 코드>
#include<stdio.h>
int map[30][30], ch[30], cnt=0, n, path[30];
void DFS(int v, int L){
	int i, j;
	if(v==n){
		cnt++;
		for(j=0; j<L; j++){
			printf("%d ", path[j]);
		}
		puts("");
	}
	else{
		for(i=1; i<=n; i++){
			if(map[v][i]==1 && ch[i]==0){
				ch[i]=1;
				path[L]=i;
				DFS(i, L+1);
				ch[i]=0;
			}
		}
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	int m, i, j, a, b, c;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		map[a][b]=1;
	}
	ch[1]=1;
	path[0]=1;
	DFS(1, 1);
	printf("%d\n", cnt);
	return 0;
}*/