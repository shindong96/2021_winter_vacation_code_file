#include <iostream>
using namespace std;

/*
53. K진수 출력
10진수 N이 입력되면 K진수로 변환하여 출력하는 프로그램을 작성하세요. 스택 자료구조를 사
용하시기 바랍니다.
▣ 입력설명
첫 번째 줄에 10진수 N(10<=N<=1,000)과 K(2, 5, 8, 16)가 주어진다.
▣ 출력설명
K진수를 출력한다.
*/
class stack {
public:
	int num[100];
	int count;

	stack() {
		num[100] = { 0 };
		count = 0;
	}

	void push(int x) {
		num[count++] = x;
	}
	int pop() {
		return num[--count];
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	stack s;
	while (n >= k) {
		s.push(n % k);
		n /= k;
	}
	s.push(n);
	int size = s.count;
	for (int i = 0; i < size; i++) {
		int num = s.pop();
		if (num > 9) {
			char c ;
			c = 65 + (num % 10);
			cout << c;
		} 
		else cout << num;
	}
	return 0;
}       //string str = "0123456789ABCDEF"를 사용해서 cout을 인덱스로 빼자.

/*
모범 답안

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int stack[100], top=-1;

void push(int x){
	stack[++top]=x;
}
int pop(){
	return stack[top--];
}

int main(){
	freopen("input.txt", "rt", stdin);
	int n, k;
	char str[20]="0123456789ABCDEF";
	scanf("%d %d", &n, &k);
	while(n>0){
		push(n%k);
		n=n/k;
	}
	while(top!=-1){
		printf("%c", str[pop()]);
	}
	return 0;
}




#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, k;
	stack<int> s;
	char str[20]="0123456789ABCDEF";
	scanf("%d %d", &n, &k);
	while(n>0){
		s.push(n%k);
		n=n/k;
	}
	while(!s.empty()){
		printf("%c", str[s.top()]);
		s.pop();
	}
	return 0;
}*/
