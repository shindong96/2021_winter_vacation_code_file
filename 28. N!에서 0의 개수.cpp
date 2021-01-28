#include <iostream>
using namespace std;

/*
28. N!에서 0의 개수
자연수 N이 입력되면 N! 값에서 일의 자리부터 연속적으로 ‘0’이 몇 개 있는지 구하는 프로그
램을 작성하세요.
만약 5! =  × ×  ×  × = 120으로 일의자리부터 연속적된 ‘0’의 개수는 1입니다.
만약 12! = 479001600으로 일의자리부터 연속적된 ‘0’의 개수는 2입니다.
▣ 입력설명
첫 줄에 자연수 N(10<=N<=1,000)이 입력된다.
▣ 출력설명
일의 자리부터 연속된 0의 개수를 출력합니다.*/void recursion(int, int*);

int main() {
	int n;
	int count = 0;
	cin >> n;
	int num[1001] = { 0 };
	for (int i = 2; i <= n; i++) {
		recursion(i, num);
	}
	while (num[2] != 0 && num[5] != 0) {
		count++;
		num[2]--;
		num[5]--;
	}
	cout << count;
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
}             //while문 대신 count = (num[2] > num[5]) ? num[5] : num[2];이면 끝난다. 심지어 count 안쓰고 cout<<((num[2] > num[5]) ? num[5] : num[2]); 쓰면 끝!

/*
모범 답안

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, i, j, tmp, cnt1=0, cnt2=0;
	scanf("%d", &n);
	for(i=2; i<=n; i++){
		tmp=i;
		j=2;
		while(1){
			if(tmp%j==0){
				if(j==2) cnt1++;
				else if(j==5) cnt2++;
				tmp=tmp/j;
			}
			else j++;
			if(tmp==1) break;
		}
	}
	if(cnt1<cnt2) printf("%d\n", cnt1);
	else printf("%d\n", cnt2);
	return 0;
}*/