#include <iostream>
using namespace std;

/*
27. N!의 표현법
임의의 N에 대하여 N!은 1부터 N까지의 곱을 의미한다. 이는 N이 커짐에 따라 급격하게 커진
다. 이러한 큰 수를 표현하는 방법으로 소수들의 곱으로 표현하는 방법이 있다. 먼저 소수는
2, 3, 5, 7, 11, 13... 순으로 증가함을 알아야 한다. 예를 들면 825는 (0 1 2 0 1)로 표현이
가능한데, 이는 2는 없고 3은 1번, 5는 2번, 7은 없고, 11은 1번의 곱이라는 의미이다. 101보
다 작은 임의의 N에 대하여 N 팩토리얼을 이와 같은 표기법으로 변환하는 프로그램을 작성해
보자. 출력은 아래 예제와 같이 하도록 한다.
▣ 입력설명
첫 줄에 자연수 N(3<=N<=1000)이 입력된다.
▣ 출력설명
소수의 곱으로 표현한다.*/

void recursion(int, int*);

int main() {
	int n;
	cin >> n;
	int num[1001] = { 0 };
	for (int i = 2; i <= n; i++) {
		recursion(i, num);
	}
	cout << n << "! = ";
	for (int i = 2; i < n + 1; i++) {
		if (num[i] != 0) cout << num[i] << " ";
	}
	return 0;
}

void recursion(int n, int* num) {
	if (n == 1) return;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			num[i]++;
			n /= i;                                     
			recursion(n, num);
			return;
		}
	}
}               // n!이면 n보다 작은 소수는 무조건 한 번씩 쓰임. 
                // 그리고 미리 소수를 한 번 찾아서 재귀함수에 소수 배열을 넣어주면 계산이 적다. 
                // while문으로 소인수분해 가능

/*
모범 답안

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, i, j, tmp;
	scanf("%d", &n);
	vector<int> ch(n+1);
	for(i=2; i<=n; i++){
		tmp=i;
		j=2;
		while(1){
			if(tmp%j==0){
				ch[j]++;
				tmp=tmp/j;
			}
			else j++;
			if(tmp==1) break;
		}
	}
	printf("%d! = ", n);
	for(j=2; j<=n; j++){
		if(ch[j]!=0) printf("%d ", ch[j]);
	}
	return 0;
}
*/