#include <iostream>
using namespace std;

/*
76. 이항계수(메모이제이션)
이항계수는 N개의 원소를 가지는 집합에서 R개의 원소를 뽑아 부분집합을 만드는 경우의 수
를 의미한다. 공식은 
 로 표현된다.
N과 R이 주어지면 이항계수를 구하는 프로그램을 작성하세요.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=20)과 R(0<=R<=20)이 주어진다. 단 (N>=R)
▣ 출력설명
첫 번째 줄에 이항계수 값을 출력한다.*/int main() {
	int n, r;	cin >> n >> r;	int result = 1;	for (int i = r + 1; i <= n; i++) result *= i;	for (int i = n - r; i > 0; i--) result /= i;	cout << result;	return 0;}