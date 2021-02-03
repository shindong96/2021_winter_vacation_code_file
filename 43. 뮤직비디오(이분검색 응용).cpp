#include <iostream>
#include <algorithm>
using namespace std;

/*
43. 뮤직비디오(이분검색 응용)
지니레코드에서는 불세출의 가수 조영필의 라이브 동영상을 DVD로 만들어 판매하려 한다.
DVD에는 총 N개의 곡이 들어가는데, DVD에 녹화할 때에는 라이브에서의 순서가 그대로 유지
되어야 한다. 순서가 바뀌는 것을 우리의 가수 조영필씨가 매우 싫어한다. 즉, 1번 노래와 5번
노래를 같은 DVD에 녹화하기 위해서는 1번과 5번 사이의 모든 노래도 같은 DVD에 녹화해야
한다.
지니레코드 입장에서는 이 DVD가 팔릴 것인지 확신할 수 없기 때문에 이 사업에 낭비되는
DVD를 가급적 줄이려고 한다. 고민 끝에 지니레코드는 M개의 DVD에 모든 동영상을 녹화하기
로 하였다. 이 때 DVD의 크기(녹화 가능한 길이)를 최소로 하려고 한다. 그리고 M개의 DVD는
모두 같은 크기여야 제조원가가 적게 들기 때문에 꼭 같은 크기로 해야 한다.
▣ 입력설명
첫째 줄에 자연수 N(1≤N≤1,000), M(1≤M≤N)이 주어진다. 다음 줄에는 조영필이 라이브에서
부른 순서대로 부른 곡의 길이가 분 단위로(자연수) 주어진다. 부른 곡의 길이는 10,000분을
넘지 않는다고 가정하자.
▣ 출력설명
첫 번째 줄부터 DVD의 최소 용량 크기를 출력하세요.*/int main() {
	int n, m;
	cin >> n >> m;
	int* a = new int[n];
	int sum = 0;
	int result = 0;
	int min = 10000;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		min = min < a[i] ? min : a[i];
	}
	int max = sum;
	int mid = (max + min) / 2;
	int count = 0;
	while (1) {
		if (min > max) break;
		int sum1 = 0;
		for (int i = 0; i < n; i++) {
			if (sum1 + a[i] <= mid) sum1 += a[i];
			else {
				count++;
				sum1 = a[i];
			}
		}
		if (count < m) {
			result = mid;
			max = mid - 1;
		}
		else min = mid + 1;
		count = 0;
		mid = (max + min) / 2;
	}
	cout << result;
	return 0;
}/*모범 답안 반영 전class index_info {public:	int index;	int value;};int whoIsMax(index_info*, int);int main() {
	int n, m;	cin >> n >> m;	int* a = new int[n];	index_info* b = new index_info[m];	for (int i = 0; i < m; i++) b[i].value = 0;	int sum = 0;	for (int i = 0; i < n; i++) {		cin >> a[i];		sum += a[i];	}	int std = sum / m;	int count = 0;	for (int i = 0; i < n; i++) {		if (b[count].value + a[i] > std && count != m - 1) {			count++;			b[count].index = i;		}		b[count].value += a[i];	}	int max = whoIsMax(b, m);	int max2 = max;	while (1) {		if (b[max2].value >= b[max].value) break;		else max = max2;		b[max].value -= a[b[max].index] ;		b[max - 1].value += a[b[max].index];		b[max].index += 1;		b[max + 1].index -= 1;		max2 = whoIsMax(b, m);	}	cout << b[max].value;	delete[] a, b;	return 0;}int whoIsMax(index_info* name, int size) {	int max = 0;	for (int i = 1; i < size; i++)		max = (name[max].value < name[i].value) ? i : max;	return max;}*//*모범 답안#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1001], n;
int Count(int s){
	int i, cnt=1, sum=0;
	for(i=1; i<=n; i++){
		if(sum+a[i]>s){
			cnt++;
			sum=a[i];
		}
		else sum=sum+a[i];
	}
	return cnt;
}
int main(){
	freopen("input.txt", "rt", stdin);
	int m, i, lt=1, rt=0, mid, res, maxx=-2147000000;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		rt=rt+a[i];
		if(a[i]>maxx) maxx=a[i];
	}
	while(lt<=rt){
		mid=(lt+rt)/2;
		if(mid>=maxx && Count(mid)<=m){
			res=mid;
			rt=mid-1;
		}
		else lt=mid+1;
	}
	printf("%d\n", res);
	return 0;
}*/