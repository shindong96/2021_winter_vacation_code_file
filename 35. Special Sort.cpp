﻿#include <iostream>
#include <cmath>
using namespace std;

/*
35. Special Sort(구글 인터뷰)
N개의 정수가 입력되면 당신은 입력된 값을 정렬해야 한다.
음의 정수는 앞쪽에 양의정수는 뒷쪽에 있어야 한다. 또한 양의정수와 음의정수의 순서에는
변함이 없어야 한다.
▣ 입력설명
첫 번째 줄에 정수 N(5<=N<=100)이 주어지고, 그 다음 줄부터 음수를 포함한 정수가 주어진
다. 숫자 0은 입력되지 않는다.
▣ 출력설명
정렬된 결과를 출력한다.*/int main() {
	int n;	cin >> n;	int* a = new int[n];	int* b = new int[n];	int minus_count = 0;	int plus_count = 0;	for (int i = 0; i < n; i++) {		int sub;		cin >> sub;		if (sub < 0) {			a[minus_count] = sub;			minus_count++;		}		else {			b[plus_count] = sub;			plus_count++;		}	}	for (int i = 0; i < plus_count; i++) {		a[i + minus_count] = b[i];	}	for (int i = 0; i < n; i++) cout << a[i] << " ";	return 0;}/*모범 답안#include<stdio.h>
int main() {
	freopen("input.txt", "rt", stdin);
	int a[101], n, tmp, min, i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<n-1; i++){
		for(j=0; j<n-i-1; j++){
			if(a[j]>0 && a[j+1]<0){
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
}
*/