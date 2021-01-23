﻿#include <iostream>
#include <string>
using namespace std;

/*
16. Anagram(아나그램 : 구글 인터뷰 문제)
Anagram이란 두 문자열이 알파벳의 나열 순서를 다르지만 그 구성이 일치하면 두 단어는 아
나그램이라고 합니다.
예를 들면 AbaAeCe 와 baeeACA 는 알파벳을 나열 순서는 다르지만 그 구성을 살펴보면
A(2), a(1), b(1), C(1), e(2)로 알파벳과 그 개수가 모두 일치합니다. 즉 어느 한 단어를 재
배열하면 상대편 단어가 될 수 있는 것을 아나그램이라 합니다.
길이가 같은 두 개의 단어가 주어지면 두 단어가 아나그램인지 판별하는 프로그램을 작성하세
요. 아나그램 판별시 대소문자가 구분됩니다.
▣ 입력설명
첫 줄에 첫 번째 단어가 입력되고, 두 번째 줄에 두 번째 단어가 입력됩니다.
단어의 길이는 100을 넘지 않습니다.
▣ 출력설명
두 단어가 아나그램이면 “YES"를 출력하고, 아니면 ”NO"를 출력합니다.*/int main() {
	string a, b;	cin >> a >> b;	if (a.length() != b.length()) {		cout << "NO";		return 0;	}	int size = a.length();	for (int i = 0; i < size; i++) {		for (int j = 0; j < size; j++) {			if (b[j] == a[i]) {				b[j] = '0';				break;			}		}	}	for (int i = 0; i < size; i++) {		if (b[i] != '0') {			cout << "NO";			return 0;		}	}cout << "YES";	return 0;}                            //  a에 있는데 b에 없는 상황도 생각하면 빨리 끝날 수 있다./*모범 답안#include<stdio.h>
#include<algorithm>
int a[60], b[60];
int main(){
	freopen("input.txt", "rt", stdin);
	int n, i;
	char str[100];
	scanf("%s", &str);
	for(i=0; str[i]!='\0'; i++){
		if(str[i]>=65 && str[i]<=90)
			a[str[i]-64]++;
		else a[str[i]-70]++;
	}

	scanf("%s", &str);
	for(i=0; str[i]!='\0'; i++){
		if(str[i]>=65 && str[i]<=90)
			b[str[i]-64]++;
		else b[str[i]-70]++;
	}

	for(i=1; i<=52; i++){
		if(a[i]!=b[i]){
			printf("NO\n");
			exit(0);
		}
	}
	printf("YES\n");
	return 0;
}*/