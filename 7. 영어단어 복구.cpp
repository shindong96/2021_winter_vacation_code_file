﻿#include <iostream>
#include <string>
using namespace std;

/*
7. 영어단어 복구
현수의 컴퓨터가 바이러스에 걸려 영어단어가 뛰어쓰기와 대소문자가 혼합되어 표현된다.
예를 들면 아름다운 이란 뜻을 가지고 있는 beautiful 단어가 “bE au T I fu L” 과 같이
컴퓨터에 표시되고 있습니다. 위와 같이 에러로 표시되는 영어단어를 원래의 표현대로 공백을
제거하고 소문자화 시켜 출력하는 프로그램을 작성하세요.
▣ 입력설명
첫 줄에 바이러스에 걸린 영어단어가 주어진다. 바이러스에 걸린 영어단어의 길이(공백포함)는
100을 넘지 않는다. 문자사이의 공백은 연속적으로 존재할 수 있습니다. 입력은 알파벳과 공
백만 주어집니다.
▣ 출력설명
첫 줄에 소문자로 된 정상적인 영어단어를 출력한다.
*/

int main() {
	string std;
	string result;
	getline(cin, std);
	for (int i = 0; i < std.length(); i++) {
		if (std.at(i) >= 'a' && std.at(i) <= 'z') result.push_back(std.at(i));
		else if (std.at(i) >= 'A' && std.at(i) <= 'Z') result.push_back(std.at(i) + 32);
		else continue;
	}
	cout << result << endl;
	return 0;
}           //getline 공부하기

/*
모범 답안

#include<stdio.h>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	char a[101], b[101];
	int i, p=0;
	gets(a);
	for(i=0; a[i]!='\0'; i++){
		if(a[i]!=' '){
			if(a[i]>=65 && a[i]<=90){
				b[p++]=a[i]+32;
			}
			else b[p++]=a[i];
		}
	}
	b[p]='\0';
	printf("%s\n", b);
	return 0;
}
*/