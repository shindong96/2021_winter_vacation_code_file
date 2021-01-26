#include <iostream>
using namespace std;

/*
24. Jolly Jumpers
N개의 정수로 이루어진 수열에 대해 서로 인접해 있는 두 수의 차가 1에서 N-1까지의 값을
모두 가지면 그 수열을 유쾌한 점퍼(jolly jumper)라고 부른다. 예를 들어 다음과 같은 수열에
서 1 4 2 3 앞 뒤에 있는 숫자 차의 절대 값이 각각 3 ,2, 1이므로 이 수열은 유쾌한 점퍼가
된다. 어떤 수열이 유쾌한 점퍼인지 판단할 수 있는 프로그램을 작성하라.
▣ 입력설명
첫 번째 줄에 자연수 N(3<=N<=100)이 주어진다.
그 다음 줄에 N개의 정수가 주어진다. 정수의 크기는 int 형 범위안에 있습니다.
▣ 출력설명
유쾌한 점퍼이면 “YES"를 출력하고, 그렇지 않으면 ”NO"를 출력한다.
*/

int main() {
	int n;
	cin >> n;
	int a[2];
	int* b = new int[n+1];
	for (int i = 0; i < n+1; i++) b[i]=0;
	cin >> a[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i%2];
		int gap = a[i % 2] - a[(i + 1) % 2];
		if (gap < 0) gap *= -1;
		if (gap > n - 1 || gap < 1) {
			cout << "NO";
			return 0;
		}
		if (b[gap] == 1) {
			cout << "NO";
			return 0;
		}
		else b[gap] = 1;
	}
	cout << "YES";
	delete[] b;
	return 0;
}

/*
모범 답안

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n, i, now, pre, pos;
	scanf("%d", &n);
	vector<int> ch(n);
	scanf("%d", &pre);
	for(i=1; i<n; i++){
		scanf("%d", &now);
		pos=abs(pre-now);
		if(pos>0 && pos<n && ch[pos]==0) ch[pos]=1;
		else{
			printf("NO\n");
			return 0;
		}
		pre=now;
	}
	printf("YES\n");
	return 0;
}*/