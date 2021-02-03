#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/*
48. 각 행의 평균과 가장 가까운 값
<그림 1>과 같이 9 × 9 격자판에 쓰여진 81개의 자연수가 주어질 때, 각 행의 평균을 구하고,
그 평균과 가장 가까운 값을 출력하는 프로그램을 작성하세요. 평균은 소수점 첫 째 자리에서 반
올림합니다. 평균과 가까운 값이 두 개이면 그 중 큰 값을 출력하세요.
▣ 입력설명
첫 째 줄부터 아홉 번째 줄까지 한 줄에 아홉 개씩 자연수가 주어진다. 주어지는 자연수는 100보
다 작다.
▣ 출력설명
첫째 줄에 첫 번째 줄부터 각 줄에 각행의 평균과 그 행에서 평균과 가장 가까운 수를 출력한다.
*/

int main() {
	int* a = new int [9];
	for (int j = 0; j < 9; j++) {
		int average;
		int result=1000;
		double sum = 0;
		for (int i = 0; i < 9; i++) {
			cin >> a[i];
			sum += a[i];
		}
		sort(a, a + 9);     
		average = (int)(sum / 9*10) % 10 >= 5 ? (int)(sum / 9) + 1 : (int)(sum / 9);
		for (int i = 0; i < 9; i++) {
			result = abs(average-result) >= abs(average - a[i]) ? a[i] : result;
		}
		cout << average << " " << result << endl;
	}
	delete[] a;
	return 0;
}          //   average=((sum*10)/9+5)/10로 하면 double 필요없다.

/*
모범 답안

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[10][10];
int main(){
//	freopen("input.txt", "rt", stdin);
	int i, j, sum, ave, min, res, tmp;
	for(i=1; i<=9; i++){
		sum=0;
		for(j=1; j<=9; j++){
			scanf("%d", &a[i][j]);
			sum=sum+a[i][j];
		}
		ave=(sum/9.0)+0.5;
		printf("%d ", ave);
		min=2147000000;
		for(j=1; j<=9; j++){
			tmp=abs(a[i][j]-ave);
			if(tmp<min){
				min=tmp;
				res=a[i][j];
			}
			else if(tmp==min){
				if(a[i][j]>res) res=a[i][j];
			}
		}
		printf("%d\n", res);
	}
	return 0;
}*/