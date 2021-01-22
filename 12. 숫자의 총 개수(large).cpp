#include <iostream>
#include <cmath>
using namespace std;

/*
12. 숫자의 총 개수(large)
자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자는 몇 개 쓰였을까요?
예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로
총 21개가 쓰였음을 알 수 있습니다.
자연수 N이 입력되면 1부터 N까지 각 숫자는 몇 개가 사용되었는지를 구하는 프로그램을 작
성하세요.
▣ 입력설명
첫 번째 줄에는 자연수 N(3<=N<=100,000,000)이 주어진다.
▣ 출력설명
첫 번째 줄에 숫자의 총개수를 출력한다.
*/int main() {	int n;	int count = 0;	cin >> n;	if (n < 10) {		cout << n;		return 0;	}	else {		int a = n;		while (a >= 10) {			a /= 10;			count++;           		}		int remain = n - (int)pow(10, count);   		int sum = (remain + 1) * (count + 1);		for (int i = 0; i < count; i++) {			sum += 9 * (int)pow(10, i) * (i + 1);		}		cout << sum << endl;		return 0;	}}                    //if문 없애는 생각해보기/*모범 답안#include<stdio.h>
int main(){
	freopen("input.txt", "rt", stdin);
	int n, sum=0, cnt=1, digit=9, res=0;
	scanf("%d", &n);
	while(sum+digit<n){
		sum=sum+digit;
		res=res+(cnt*digit);
		cnt++;
		digit=digit*10;
	}
	res=res+((n-sum)*cnt);
	printf("%d\n", res);
	return 0;
}*/