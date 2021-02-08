#include <iostream>
#include <string>
using namespace std;

/*
54. 올바른 괄호(stack)
괄호가 입력되면 올바른 괄호이면 “YES", 올바르지 않으면 ”NO"를 출력합니다.
(())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아니다.
▣ 입력설명
첫 번째 줄에 괄호 문자열이 입력됩니다. 문자열의 최대 길이는 30이다.
▣ 출력설명
첫 번째 줄에 YES, NO를 출력한다.*/

class stack {
public:
	char c[30];
	int count;

	stack() {
		count = 0;
	}

	void push(char x){
		c[count++] = x;
	}
	char pop() {
		return c[--count];
	}
};

int main() {
	string str;
	stack s;
	cin >> str;
	int alright=0;
	for (int i = 0; i < str.length(); i++) s.push(str[i]);
	for (int i = 0; i < str.length(); i++) {
		if (s.pop() == ')') alright += 1;
		else alright -= 1;
		if (alright < 0) {
			cout << "NO";
			return 0;
		}
	}
	if (alright != 0) cout << "NO";
	else cout << "YES";
	return 0;
}          //스택을 사용해서 입력받을 때마다 pop시키는게 정석!

/*
모범 답안

#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	stack<char> s;
	string str;
	cin>>str;
	for(auto x : str){
		if(x=='(') s.push(x);
		else{
			if(s.empty() || s.top()!='('){
				cout<<"NO";
				return 0;
			}
			s.pop();
		}
	}
	if(s.empty()) cout<<"YES";
	else cout<<"NO";
	return 0;
}*/