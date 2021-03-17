#include <iostream>
using namespace std;

/*
최대 부분 증가수열
N개의 자연수로 이루어진 수열이 주어졌을 때, 그 중에서 가장 길게 증가하는(작은 수에서 큰
수로) 원소들의 집합을 찾는 프로그램을 작성하라. 예를 들어, 원소가 2, 7, 5, 8, 6, 4, 7,
12, 3 이면 가장 길게 증가하도록 원소들을 차례대로 뽑아내면 2, 5, 6, 7, 12를 뽑아내어 길
이가 5인 최대 부분 증가수열을 만들 수 있다.
▣ 입력설명
첫째 줄은 입력되는 데이터의 수 N(2≤N≤1,000, 자연수)를 의미하고,
둘째 줄은 N개의 입력데이터들이 주어진다.
▣ 출력설명
첫 번째 줄에 부분증가수열의 최대 길이를 출력한다.
*/

int n, max, cnt;
int* a;
int num[1000];
int main() {
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	num[cnt++] = a[0];
	for (int i = 1; i < n; i++) {
		int j;
		for (j = 0; j < cnt; j++) {
			if (num[j] >= a[i]) {
				num[j] = a[i];
				break;
			}
		}
		if (j == cnt) num[cnt++] = a[i];

	}
	cout << cnt;
	return 0;
}   
/*
앞에서 보는데 들어오는 수보다
큰 수 나오면 그 자리를 대체 ,
끝까지 가면 추가 
*/