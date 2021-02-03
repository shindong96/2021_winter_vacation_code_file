#include <iostream>
#include <algorithm>
using namespace std;

/*
44. 마구간 정하기(이분검색 응용)
N개의 마구간이 1차원 수직선상에 있습니다. 각 마구간은 x1, x2, x3, ......, xN의 좌표를 가
지며, 마구간간에 좌표가 중복되는 일은 없습니다.
현수는 C마리의 말을 가지고 있는데, 이 말들은 서로 가까이 있는 것을 좋아하지 않습니다.
각 마구간에는 한 마리의 말만 넣을 수 있고, 가장 가까운 두 말의 거리가 최대가 되게 말을
마구간에 배치하고 싶습니다.
C마리의 말을 N개의 마구간에 배치했을 때 가장 가까운 두 말의 거리가 최대가 되는 그 최대
값을 출력하는 프로그램을 작성하세요.
▣ 입력설명
첫 줄에 자연수 N(3<=N<=200,000)과 C(2<=C<=N)이 공백을 사이에 두고 주어집니다.
둘째 줄부터 N개의 줄에 걸쳐 마구간의 좌표 xi(0<=xi<=1,000,000,000)가 한 줄에 하나씩
주어집니다.
▣ 출력설명
첫 줄에 가장 가까운 두 말의 최대 거리를 출력하세요.*/int main() {
	int n, c;	cin >> n >> c;	int* a = new int[n];	int* b = new int[n - 1];	for (int i = 0; i < n; i++) cin >> a[i];	sort(a, a + n);	int sum = 0;	int min = 1000000000;	for (int i = 0; i < n - 1; i++) {		b[i] = a[i + 1] - a[i];		sum += b[i];		min = min > b[i] ? b[i] : min;	}	int max = sum;	int mid;	int count = 0;	int result = 0;	while (1) {		if (min > max) break;		mid = (max + min) / 2;		int sum1 = 0;		int result1 = sum;		for (int i = 0; i < n - 1; i++) {			sum1 += b[i];			if (sum1 >= mid) {				count++;				result1 = result1 < sum1 ? result1 : sum1;				sum1 = 0;			}		}		if (sum1 >= mid) {			count++;			result1 = result1 < sum1 ? result1 : sum1;		}		if (count >= c - 1) {
			result = result1 > result ? result1 : result;
			min = mid + 1;
		}
		else  max = mid - 1;
		count = 0;	}	cout << result;
	return 0;}                  //변수명 가독성..거리 배열을 만들 필요없다./*모범답안 반영 전class index_info {public:	int index;	int value;};int main() {
	int n, c;	cin >> n >> c;	int* a = new int[n];	int* b = new int[n - 1];	index_info* div = new index_info[c];	for (int i = 0; i < n; i++) cin >> a[i];	sort(a, a + n);	int sum = 0;	for (int i = 0; i < n - 1; i++) {		b[i] = a[i + 1] - a[i];		sum += b[i];	}	for (int i = 0; i < c; i++) div[i].value = 0;	for (int i = 0; i < n; i++) {		div[0].index = i;		div[0].value += b[i];		for (int j = i + 1; j < n; j++) {		}	}	int std = sum / (c - 1);	delete[] a, b;}*//*모범 답안#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int Count(int len, int x[]){
	int i, cnt=1, pos=x[1];
	for(i=2; i<=n; i++){
		if(x[i]-pos>=len){
			cnt++;
			pos=x[i];
		}
	}
	return cnt;
}
int main(){
	//freopen("input.txt", "rt", stdin);
	int m, i, lt=1, rt, mid, res;
	scanf("%d %d", &n, &m);
	int *x = new int[n+1];
	for(i=1; i<=n; i++){
		scanf("%d", &x[i]);
	}
	sort(x+1, x+n+1);
	rt=x[n];
	while(lt<=rt){
		mid=(lt+rt)/2;
		if(Count(mid, x)>=m){
			res=mid;
			lt=mid+1;
		}
		else rt=mid-1;
	}
	printf("%d\n", res);
	delete[] x;
	return 0;
}*/