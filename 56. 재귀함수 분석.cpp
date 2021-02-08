﻿#include <iostream>
using namespace std;

/*
56. 재귀함수 분석
자연수 N이 주어지면 아래와 같이 출력하는 프로그램을 작성하세요. 재귀함수를 이용해서 출
력해야 합니다.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=20)이 주어집니다.
▣ 출력설명
첫 번째 줄에 재귀함수를 이용해서 출력하세요.*/void recursion(int num){	if (num == 1) {		cout << num << " ";		return;	}	else {		recursion(num - 1);		cout << num << " ";	}	return;}int main() {
	int n;	cin >> n;	recursion(n);	return 0;}/*모범 답안#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;

void DFS(int x){
	if(x==0) return;
	else{
		DFS(x-1);
		printf("%d ", x);
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	int n;
	scanf("%d", &n);
	DFS(n);
	return 0;
}*/