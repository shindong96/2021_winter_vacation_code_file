﻿#include <iostream>
using namespace std;

/*
61. 특정 수 만들기(DFS : MS 인터뷰)
N개의 원소로 구성된 자연수 집합이 주어지면, 집합의 원소와 ‘+’, ‘-’ 연산을 사용하여 특정
수인 M을 만드는 경우가 몇 가지 있는지 출력하는 프로그램을 작성하세요. 각 원소는 연산에
한 번만 사용합니다.
예를 들어 {2, 4, 6, 8}이 입력되고, M=12이면
2+4+6=12
4+8=12
6+8-2=12
2-4+6+8=12
로 총 4가지의 경우가 있습니다. 만들어지는 경우가 존재하지 않으면 -1를 출력한다.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=10)와 M(1<=M<=100) 주어집니다.
두 번째 줄에 집합의 원소 N개가 주어진다. 각 원소는 중복되지 않는다.
▣ 출력설명
첫 번째 줄에 “YES" 또는 ”NO"를 출력한다.*/

void DFS(int*, int, int);
int ch[100];
int m;

int main() {
	int n;
	cin >> n >> m;
	int* a = new int[2 * n + 1];
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[2 * n + 1 - i] = -1 * a[i];
	}
	DFS(a, 1, 2 * n);
	if (a[0] == 0) cout << "-1";
	else cout << a[0];
	delete[] a;
	return 0;
}

void DFS(int* a, int num, int size) {
	int sum1 = 0;
	if (num == size + 1) {
		for (int i = 1; i <= size; i++) {
			if (ch[i] == 1) sum1 += a[i];
		}
		for (int i = 1; i <= size; i++)
			if (ch[i] == 1 && ch[size + 1 - i] == 1) return;
		if (sum1 == m) a[0]++;
	}
	else {
		ch[num] = 1;
		DFS(a, num + 1, size);
		ch[num] = 0;
		DFS(a, num + 1, size);
	}
}            //check_array 안쓰고 누적을 넘겨보자

/*
모범 답안


#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int a[11], n, m, cnt=0;
void DFS(int L, int sum){
	if(L==n+1){
		if(sum==m){
			cnt++;
		}
	}
	else{
		DFS(L+1, sum+a[L]);
		DFS(L+1, sum);
		DFS(L+1, sum-a[L]);
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	int i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	DFS(1, 0);
	if(cnt==0) printf("-1\n");
	else printf("%d\n", cnt);
	return 0;
}



<경로출력코드>
#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
int a[11], n, m, cnt=0, path[10];
void DFS(int L, int sum){
	if(L==n+1){
		if(sum==m){
			cnt++;
			for(int i=1; i<L; i++){
				printf("%d ", path[i]);
			}
			puts("");
		}
	}
	else{
		path[L]=a[L];
		DFS(L+1, sum+a[L]);
		path[L]=0;
		DFS(L+1, sum);
		path[L]=-a[L];
		DFS(L+1, sum-a[L]);
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	int i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	DFS(1, 0);
	if(cnt==0) printf("-1\n");
	else printf("%d\n", cnt);
	return 0;
}*/