﻿#include <iostream>
using namespace std;

/*
19. 분노 유발자
오늘은 수능이 끝난 다음날로 교장선생님은 1, 2학년 재학생들에게 강당에 모여 어벤져스 영
화를 보여준다고 하여 학생들이 강당에 모였습니다.
강당의 좌석은 영화관처럼 계단형이 아니라 평평한 바닥에 의자만 배치하고 학생들이 앉습니
다. 그런데 만약 앞자리에 앉은 키가 큰 학생이 앉으면 그 학생보다 앉은키가 작은 뒷자리 학
생은 스크린이 보이지 않습니다. 한 줄에 앉은키 정보가 주어지면 뒷사람 모두의 시야를 가려
영화 시청이 불가능하게 하는 분노유발자가 그 줄에 몇 명이 있는지 구하는 프로그램을 작성
하세요.
▣ 입력설명
첫 줄에 한 줄에 앉은 학생수 N(3<=N<=100)이 주어집니다.
두 번째 줄에 N명의 앉은 키 정보(45이상 100이하)가 앞 자리 학생부터 차례대로 주어집니다.
▣ 출력설명
자신의 뒷 사람 모두를 시청방해하는 학생수를 출력합니다.*/int main() {
	int n;	int count = 0;	cin >> n;	int* a = new int[n];	for (int i = 0; i < n; i++)	cin >> a[i];	for (int i = 0; i < n - 1; i++) {		int j;		for (j = i + 1; j < n; j++)	if (a[j] >= a[i]) break;		if (j == n) count++;	}	cout << count<<endl;	delete[] a;	return 0;}          //뒤에서부터 비교하면 max하나만 들고 움직이면 가능하다.---->엄청나다/*모범 답안#include<stdio.h>
int main(){
	//freopen("input.txt", "rt", stdin);
	int n, i, cnt=0, h[101], max;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &h[i]);
	}
	max=h[n];
	for(i=n-1; i>=1; i--){
		if(h[i]>max){
			max=h[i];
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
*/