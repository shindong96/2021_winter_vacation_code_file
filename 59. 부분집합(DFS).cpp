#include <iostream>
using namespace std;

/*
59. 부분집합(DFS)
자연수 N이 주어지면 1부터 N까지의 원소를 갖는 집합의 부분집합을 모두 출력하는 프로그램
을 작성하세요.
▣ 입력설명
첫 번째 줄에 자연수 N(1<=N<=10)이 주어집니다.
▣ 출력설명
첫 번째 줄부터 각각의 부분집합을 출력합니다. 부분집합을 출력하는 순서는 출력예제에서 출
력한 순서와 같게 합니다. 단 공집합은 출력하지 않습니다.*/void DFS(int, int);

int ch[100];

int main() {
	int n;
	cin >> n;
	DFS(1, n);
	return 0;
}

void DFS(int num, int size) {
	if (num == size + 1) {
		for (int i = 1; i <= size; i++)
			if (ch[i] == 1) cout << i << " ";
		cout << endl;
	}
	else {
		ch[num] = 1;
		DFS(num + 1, size);
		ch[num] = 0;
		DFS(num + 1, size);
	}
}                    //패배....

/*
모범답안

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, ch[100];
void DFS(int L){
	int i;
	if(L==n+1){
		for(i=1; i<=n; i++){
			if(ch[i]==1) printf("%d ", i);
		}
		puts("");
	}
	else{
		ch[L]=1;
		DFS(L+1);
		ch[L]=0;
		DFS(L+1);
	}
}
int main(){
	freopen("input.txt", "rt", stdin);
	scanf("%d", &n);
	DFS(1);
	return 0;
}*/