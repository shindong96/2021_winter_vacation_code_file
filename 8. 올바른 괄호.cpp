#include <iostream>
#include <string>
using namespace std;

/*
8. 올바른 괄호
괄호가 입력되면 올바른 괄호이면 “YES", 올바르지 않으면 ”NO"를 출력합니다.
(())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아니다.
▣ 입력설명
첫 번째 줄에 괄호 문자열이 입력됩니다. 문자열의 최대 길이는 30이다.
▣ 출력설명
첫 번째 줄에 YES, NO를 출력한다.
*/

int main() {
	int count = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == '(') count++;
		else if (str.at(i) == ')')count--;
		if (count < 0) {
			cout << "NO" << endl;
			return 0;
		}
	}if (count != 0) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}            //stack으로 풀이 가능

/*
모범 답안

#include<stdio.h>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	char a[100];
	int i, cnt=0;
	scanf("%s", &a);
	for(i=0; a[i]!='\0'; i++){
		if(a[i]=='(') cnt++;
		else if(a[i]==')') cnt--;
		if(cnt<0) break;
	}
	if(cnt==0) printf("YES\n");
	else printf("NO\n");
	return 0;
}
*/