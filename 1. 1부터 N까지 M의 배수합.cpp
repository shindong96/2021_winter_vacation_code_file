#include <iostream>
using namespace std;

/*
1. 1부터 N까지의 M의 배수합
자연수 N이 입력되면 1부터 N까지의 수 중 M의 배수합을 출력하는 프로그램을 작성하세요.
▣ 입력설명
첫 줄에 자연수 N과 M이 차례대로 입력됩니다.(3<=M<N<=1000)
▣ 출력설명
첫 줄에 M의 배수합을 출력한다.
*/

int main() {
	int n, m;
	int sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		if (i % m == 0) sum += i;
	}
	cout << sum << endl;
	return 0;
}

/*
모범답안

#include<stdio.h>
int main(){
	int n, m, sum=0, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		if(i%m==0) sum+=i;
	}
	printf("%d\n", sum);
	return 0;
}


#include<iostream>
int main(){
	int n, m, i, sum=0;
	std::cin>>n>>m;
	for(i=1; i<=n; i++){
		if(i%m==0){
			sum=sum+i;
		}
	}
	std::cout<<sum;
	return 0;
}
*/

