#include <iostream>
#include <string>
using namespace std;

/*
13. 가장 많이 사용된 자릿수
N자리의 자연수가 입력되면 입력된 자연수의 자릿수 중 가장 많이 사용된 숫자를 출력하는 프
로그램을 작성하세요.
예를 들어 1230565625라는 자연수가 입력되면 5가 3번 상용되어 가장 많이 사용된 숫자입니
다. 답이 여러 개일 경우 그 중 가장 큰 수를 출력하세요.
▣ 입력설명
첫 줄에 자연수가 입력됩니다. 자연수의 길이는 100을 넘지 않습니다.
▣ 출력설명
자릿수의 곱을 출력합니다.*/int main() {	string str;	int b[10] = { 0 };	int max = 0;	cin >> str;	for (int i = 0; i < str.length(); i++) b[(int)str[i] - '0']++;	for (int i = 1; i < 10; i++) 		if (b[max] <= b[i]) max = i;   	cout << max << endl;	return 0;}                    //배열을 전역변수에 선언하면 초기화 필요없음./*모범 답안#include<stdio.h>
int ch[10];
int main(){
	//freopen("input.txt", "rt", stdin);
	int i, digit, max=-2147000000, res;
	char a[101];
	scanf("%s", &a);
	for(i=0; a[i]!='\0'; i++){
		digit=a[i]-48;
		ch[digit]++;
	}
	for(i=0; i<=9; i++){
		if(ch[i]>=max){
			max=ch[i];
			res=i;
		}
	}
	printf("%d\n", res);
	return 0;
}
*/