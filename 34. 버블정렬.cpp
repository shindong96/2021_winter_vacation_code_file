﻿#include <iostream>
using namespace std;

/*
34. 버블정렬
N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
정렬하는 방법은 버블정렬입니다.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 각 자연수는 정수형 범위 안에
있습니다.
▣ 출력설명
오름차순으로 정렬된 수열을 출력합니다.*/int main() {
	int n;	cin >> n;	int* a = new int[n];	for (int i = 0; i < n; i++) cin >> a[i];	for(int j=0;j<n-1;j++){		for (int i = 0; i < n - (j+1); i++) {			if (a[i] > a[i + 1]) {				int tmp = a[i];				a[i] = a[i + 1];				a[i + 1] = tmp;			}		}	}	for (int i = 0; i < n; i++) cout << a[i] << " ";	delete[] a;}/*모범 답안#include <stdio.h>
int main() {
	freopen("input.txt", "rt", stdin);
	int a[101], n, i, j, tmp;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}*/