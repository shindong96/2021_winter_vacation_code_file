#include <iostream>
#include <cmath>
using namespace std;

/*
9. 모두의 약수
자연수 N이 입력되면 1부터 N까지의 각 숫자들의 약수의 개수를 출력하는 프로그램을 작성하
세요. 만약 N이 8이 입력된다면 1(1개), 2(2개), 3(2개), 4(3개), 5(2개), 6(4개), 7(2개), 8(4
개) 와 같이 각 숫자의 약수의 개수가 구해집니다.
출력은 다음과 같이 1부터 차례대로 약수의 개수만 출력하면 됩니다.
1 2 2 3 2 4 2 4 와 같이 출력한다.
▣ 입력설명
첫 번째 줄에 자연수 N(5<=N<=50,000)가 주어진다.
▣ 출력설명
첫 번째 줄에 1부터 N까지 약수의 개수를 순서대로 출력한다.*/int find(int num) {	int count = 0;	int i;	for (i = 1; i <= sqrt(num); i++) {		if (num % i == 0) count++;	}	count *= 2;	i--;	if (i * i == num) count--;	return count;}int main() {
	int n;	cin >> n;	for (int i = 1; i <= n; i++) {		cout<<find(i)<<" ";	}	return 0;}          //숫자가 너무 커지면 time-limited 걸린다./*모범 답안#include<stdio.h>
using namespace std;
int cnt[50001];
int main(){
	//freopen("input.txt", "rt", stdin);
	int n, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		for(j=i; j<=n; j=j+i){
			cnt[j]++;
		}
	}
	for(i=1; i<=n; i++){
		printf("%d ", cnt[i]);
	}
	return 0;
}*/