﻿#include <iostream>
using namespace std;

/*
11. 숫자의 총 개수(small)
자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자는 몇 개 쓰였을까요?
예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
총 21개가 쓰였음을 알 수 있습니다.
자연수 N이 입력되면 1부터 N까지 각 숫자는 몇 개가 사용되었는지를 구하는 프로그램을 작
성하세요.
▣ 입력설명
첫 번째 줄에는 자연수 N(3<=N<100,000)이 주어진다.
▣ 출력설명
첫 번째 줄에 숫자의 총개수를 출력한다.*/int find(int num) {	int count = 0;	while (num != 0) {		count++;		num /= 10;	}	return count;}int main() {
	int n;	int count = 0;	cin >> n;	for (int i = 1; i <= n; i++) {		count += find(i);	}	cout << count << endl;	return 0;}                //함수랑 메인함수에 같은 변수명은 협업시 햇갈릴 수 있음, string으로 가면 인덱스 갯수로 쉽게 찾기 가능/*모범 답안#include<stdio.h>
int main(){
	//freopen("input.txt", "rt", stdin);
	int n, i, cnt=0, tmp;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		tmp=i;
		while(tmp>0){
			tmp=tmp/10;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}*/