#include <iostream>
using namespace std;

/*
4. 나이 차이
N(2<=N<=100)명의 나이가 입력됩니다. 이 N명의 사람 중 가장 나이차이가 많이 나는 경우는
몇 살일까요? 최대 나이 차이를 출력하는 프로그램을 작성하세요.
▣ 입력설명
첫 줄에 자연수 N(2<=N<=100)이 입력되고, 그 다음 줄에 N개의 나이가 입력된다.
▣ 출력설명
첫 줄에 최대 나이차이를 출력합니다.
*/

int main() {
	int n;
	int min, max;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (i == 0) min = max = num;
		else {
			if (num > max) max = num;
			if (num < min) min = num;
		}
	}
	cout << max - min << endl;
	return 0;
}                            //고칠 점 : 맨 처음 받는 걸 for문 밖에 따로 받고 한 번 빼고 for문

/*
모범 답안

#include<iostream>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	int n, i, a, max=-2147000000, min=2147000000;
	cin>>n;
	for(i=1; i<=n; i++){
		cin>>a;
		if(a>max) max=a;
		if(a<min) min=a;
	}
	cout<<max-min;
	return 0;
}*/