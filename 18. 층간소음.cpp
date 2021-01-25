#include <iostream>
using namespace std;

/*
18. 층간소음
T편한 세상 아파트는 층간소음 발생 시 윗집의 발뺌을 방지하기 위해 애초 아파트를 지을 때
바닥에 진동센서를 설치했습니다. 이 센서는 각 세대의 층간 진동소음 측정치를 초단위로 아
파트 관리실에 실시간으로 전송합니다. 그리고 한 세대의 측정치가 M값을 넘으면 세대호수와
작은 경보음이 관리실 모니터에서 울립니다. 한 세대의 N초 동안의 실시간 측정치가 주어지면
최대 연속으로 경보음이 울린 시간을 구하세요. 경보음이 없으면 -1를 출력합니다.
▣ 입력설명
첫 줄에 자연수 N(10<=N<=100)과 M이 주어집니다.
두 번째 줄에 N개의 측정값(1000이하 자연수)이 초 순서대로 입력된다.
▣ 출력설명
최대 연속 경보음이 울린 시간(초)를 출력하세요.
*/

int main() {
	int n, m;
	int count = 0;
	int max = -1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int sound;
		cin >> sound;
		if (sound <= m) {
			if (max < count)max = count;
			count = 0;
		}
		else count++;
	}
	if (max < count)max = count;
	cout << max;
	return 0;
}                //27번 줄을 30번 안의 else문에 속하게 하면 32번이 필요없다!

/*
모범 답안

#include<stdio.h>
int main(){
	//freopen("input.txt", "rt", stdin);
	int n, val, i, num, cnt=0, max=-2147000000;
	scanf("%d %d", &n, &val);
	for(i=1; i<=n; i++){
		scanf("%d", &num);
		if(num>val) cnt++;
		else cnt=0;
		if(cnt>max) max=cnt;
	}
	printf("%d\n", max);
	return 0;
}
*/