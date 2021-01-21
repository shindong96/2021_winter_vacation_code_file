﻿#include <iostream>
#include <string>
using namespace std;

/*
6. 숫자만 추출
문자와 숫자가 섞여있는 문자열이 주어지면 그 중 숫자만 추출하여 그 순서대로 자연수를 만
듭니다. 만들어진 자연수와 그 자연수의 약수 개수를 출력합니다.
만약 “t0e0a1c2her”에서 숫자만 추출하면 0, 0, 1, 2이고 이것을 자연수를 만들면 12가 됩니
다. 즉 첫 자리 0은 자연수화 할 때 무시합니다. 출력은 12를 출력하고, 다음 줄에 12의 약
수의 개수를 출력하면 됩니다.
추출하여 만들어지는 자연수는 100,000,000을 넘지 않습니다.
▣ 입력설명
첫 줄에 숫자가 썩인 문자열이 주어집니다. 문자열의 길이는 50을 넘지 않습니다.
▣ 출력설명
첫 줄에 자연수를 출력하고, 두 번째 줄에 약수의 개수를 출력합니다.
*/

int main() {
	string std;
	cin >> std;
	int result=0;
	int count = 0;
	for (int i = 0; i < std.length(); i++) {
		if (std.at(i) >= '0' && std.at(i) <= '9') {
			result = 10 * result + (int)std.at(i) - 48;
		}
	}
	for (int i = 1; i <= result; i++) {
		if (result % i == 0) count++;
	}
	cout << result << endl << count << endl;
	return 0;
}

/*
모범 답안

#include<stdio.h>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	char a[100];
	int res=0, cnt=0, i;
	scanf("%s", &a);
	for(i=0; a[i]!='\0'; i++){
		if(a[i]>=48 && a[i]<=57){
			res=res*10+(a[i]-48);
		}
	}
	printf("%d\n", res);
	for(i=1; i<=res; i++){
		if(res%i==0) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
*/
