#include <iostream>
#include <algorithm>
using namespace std;

/*
40. 교집합(투포인터 알고리즘)
두 집합 A, B가 주어지면 두 집합의 교집합을 출력하는 프로그램을 작성하세요.
▣ 입력설명
첫 번째 줄에 집합 A의 크기 N(1<=N<=30,000)이 주어집니다.
두 번째 줄에 N개의 원소가 주어집니다. 원소가 중복되어 주어지지 않습니다.
세 번째 줄에 집합 B의 크기 M(1<=M<=30,000)이 주어집니다.
네 번째 줄에 M개의 원소가 주어집니다. 원소가 중복되어 주어지지 않습니다.
각 집합의 원소는 int형 변수의 크기를 넘지 않습니다.
▣ 출력설명
두 집합의 교집합을 오름차순 정렬하여 출력합니다.*/int main() {
	int n, m;	cin >> n;	int* a = new int[n];	for (int i = 0; i < n; i++) cin >> a[i];	sort(a, a + n);	cin >> m;	int* b = new int[m];	for (int i = 0; i < m; i++) cin >> b[i];	sort(b, b + m);		int small = (n < m) ? n : m;	int* result = new int[small];	int count = 0;	int a_cnt = 0;	int b_cnt = 0;		while (a_cnt < n && b_cnt < m) {		if (a[a_cnt] < b[b_cnt]) a_cnt++;		else if(a[a_cnt] > b[b_cnt]) b_cnt++;		else {			result[count] = a[a_cnt];			a_cnt++;			b_cnt++;			count++;		}	}		for (int i = 0; i < count; i++) cout << result[i] << " ";
	delete[] a, b, result;	return 0;}                  //모범답안 알고리즘 라이브러리 그냥 씀../*모범 답안#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, m, i, p1=0, p2=0, p3=0;
	scanf("%d", &n);
	vector<int> a(n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());

	scanf("%d", &m);
	vector<int> b(m), c(m);
	for(i=0; i<m; i++){
		scanf("%d", &b[i]);
	}
	sort(b.begin(), b.end());

	while(p1<n && p2<m){
		if(a[p1]==b[p2]){
			c[p3++]=a[p1++];
			p2++;
		}
		else if(a[p1]<b[p2]){
			p1++;
		}
		else p2++;
	}
	for(i=0; i<p3; i++){
		printf("%d ", c[i]);
	}
	return 0;
}
*/