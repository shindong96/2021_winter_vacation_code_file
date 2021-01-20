#include <iostream>
using namespace std;

/*
2. 자연수의 합
자연수 A, B가 주어지면 A부터 B까지의 합을 수식과 함께 출력하세요.
▣ 입력설명
첫 줄에 자연수 A, B가 공백을 사이에 두고 차례대로 입력된다. (1<=A<B<=100)
▣ 출력설명
첫 줄에 더하는 수식과 함께 합을 출력합니다.
*/

int main() {
	int a, b;
	int sum = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		sum += i;
		if (i == b) cout << i << " = " << sum << endl;
		else cout << i << " +";
	}
	return 0;
}                            // 고칠 점 : for문 안은 비교 연산 등 최소화

/*
모범 답안

#include<stdio.h>
int main(){
	int a, b, sum=0, i;
	scanf("%d %d", &a, &b);
	for(i=a; i<b; i++){
		sum+=i;
		printf("%d + ", i);
	}
	printf("%d = %d\n", i, sum+i);
	return 0;
}
*/