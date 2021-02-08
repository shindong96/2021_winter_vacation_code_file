#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/*
52. Ugly Numbers
어떤 수를 소인수분해 했을 때 그 소인수가 2 또는 3 또는 5로만 이루어진 수를 Ugly
Number라고 부릅니다. Ugly Number를 차례대로 적어보면
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......입니다. 숫자 1은 Ugly Number의 첫 번째 수로 합
니다. 자연수 N이 주어지면 Ugly Number를 차례로 적을 때 N번째 Ugly Number를 구하는
프로그램을 작성하세요.
▣ 입력설명
첫 줄에 자연수 N(3<=N<=1500)이 주어집니다.
▣ 출력설명
첫 줄에 N번째 Ugly Number를 출력하세요.*/int main() {
	int n;	cin >> n;	int sum = 1, sum2 = 0, sum3 = 0, sum5 = 0;	int count = 1;	while (sum <= n) {		sum2 = 1;		sum3 = count;		for (int i = 1; i <= count; i++) sum5 += i;		sum += (sum2 + sum3 + sum5);		count++;	}	int* result = new int[sum];	int num = 0;	for (int i = 0; i <= count; i++)		for (int j = 0; j <= count - i; j++) 			for (int k = 0; k <= count - i-j; k++){				result[num] = pow(2, i) * pow(3, j) * pow(5, count - i - j);				num++;			}	sort(result, result + sum);	cout << result[n];	delete[] result;	return 0;}/*주원이형 코드int main() {
   //freopen("input.txt", "rt", stdin);
   int n, cnt=1, cur=1, min, p2=0, p3=0, p5=0;
   vector<int> v2, v3, v5;
   cin >> n;
   while (cnt < n) {
	  v2.push_back(cur * 2);
	  v3.push_back(cur * 3);
	  v5.push_back(cur * 5);
	  min = v2[p2];
	  if (min > v3[p3]) min = v3[p3];
	  if (min > v5[p5]) min = v5[p5];
	  cur = min;
	  if (v2[p2] == min) p2++;
	  if (v3[p3] == min) p3++;
	  if (v5[p5] == min) p5++;
	  cnt++;
   }
   cout << cur;
   return 0;
}*/


/*
모범 답안

#include <bits/stdc++.h>
using namespace std;
int a[1501];
int main(){
	//freopen("input.txt", "rt", stdin);
	int n, i, p2, p3, p5, min=0;
	scanf("%d", &n);
	a[1]=1;
	p2=p3=p5=1;
	for(i=2; i<=n; i++){
		if(a[p2]*2<a[p3]*3) min=a[p2]*2;
		else min=a[p3]*3;
		if(a[p5]*5<min) min=a[p5]*5;
		if(min==a[p2]*2) p2++;
		if(min==a[p3]*3) p3++;
		if(min==a[p5]*5) p5++;
		a[i]=min;
	}
	printf("%d\n", a[n]);
	return 0;
}*/