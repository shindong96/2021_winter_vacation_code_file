#include <iostream>
using namespace std;

/*
3. 진약수의 합
자연수 N이 주어지면 자연수 N의 진약수의 합을 수식과 함께 출력하는 프로그램을 작성하세
요.
▣ 입력설명
첫 줄에 자연수 N이 주어집니다. (3<N<=100)
▣ 출력설명
첫 줄에 더하는 수식과 함께 합을 출력합니다.
*/

int main() {
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		if (n % i == 0) {
			sum += i;
			if (i == 1)cout << i << " ";
			else cout << "+ " << i << " ";
		}
	}
	cout << "= " << sum << endl;
	return 0;
}                           //배울 점 : 1 다음에 오는 약수로 나눈 것이 마지막으로 for문 중단하는 방법

/*
모범 답안

#include<stdio.h>
int main(){
	int n, sum=1, i;
	scanf("%d", &n);
	printf("1 ");
	for(i=2; i<n; i++){
		if(n%i==0){
			sum+=i;
			printf("+ %d ", i);
		}
	}
	printf("= %d\n", sum);
	return 0;
}




#include<iostream>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	int n, sum=1, i;
	cin>>n;
	cout<<"1";
	for(i=2; i<n; i++){
		if(n%i==0){
			sum+=i;
			cout<<" + "<<i;
		}
	}
	cout<<" = "<< sum;
	return 0;
}
*/