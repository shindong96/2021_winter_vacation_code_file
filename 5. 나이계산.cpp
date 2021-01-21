#include <iostream>
#include <string>
using namespace std;

/*
5. 나이계산
주민등록증의 번호가 주어지면 주민등록증 주인의 나이와 성별을 판단하여 출력하는 프로그램
을 작성하세요. 주민등록증의 번호는 -를 기준으로 앞자리와 뒷자리로 구분된다.
뒷자리의 첫 번째 수가 1이면 1900년대생 남자이고, 2이면 1900년대생 여자, 3이면 2000년대
생 남자, 4이면 2000년대생 여자이다.
올해는 2019년입니다. 해당 주민등록증 주인의 나이와 성별을 출력하세요.
▣ 입력설명
첫 줄에 주민등록증 번호가 입력됩니다.
▣ 출력설명
첫 줄에 나이와 성별을 공백을 구분으로 출력하세요. 성별은 남자는 M(man), 여자는
W(Woman)로 출력한다.*/int main() {
	string std;	int age;	cin >> std;            	int a[7];	int b[7];	for (int i = 0; i < 7; i++) {		a[i] = (int)std.at(i) - 48;		b[i] = (int)std.at(i + 7) - 48;	}	if (b[0] == 1) {		age = 2019 - (1900 + 10 * a[0] + a[1]) + 1;		cout << age << " M" << endl;	}	else if (b[0] == 3) {		age = 2019 - (2000 + 10 * a[0] + a[1]) + 1;		cout << age << " M" << endl;	}	else if (b[0] == 2) {		age = 2019 - (1900 + 10 * a[0] + a[1]) + 1;		cout << age << " W" << endl;	}	else {		age = 2019 - (2000 + 10 * a[0] + a[1]) + 1;		cout << age << " W" << endl;	}	return 0;}             //case가 많아지면 중괄호 묶기, std[1] 이런 것도 가능/*모범 답안#include<stdio.h>
int main(){
	char a[20];
	int year, age;
	scanf("%s", &a);
	if(a[7]=='1' || a[7]=='2') year=1900+((a[0]-48)*10+(a[1]-48));
	else year=2000+((a[0]-48)*10+(a[1]-48));
	age=2019-year+1;
	printf("%d ", age);
	if(a[7]=='1' || a[7]=='3') printf("M\n");
	else printf("W\n");
	return 0;
}*/