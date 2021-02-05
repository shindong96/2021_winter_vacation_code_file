﻿#include <iostream>
using namespace std;

/*
50. 영지(territory) 선택 : (small)
세종대왕은 현수에게 현수가 다스릴 수 있는 영지를 하사하기로 했다. 전체 땅은 사각형으로 표
시된다. 그 사각형의 땅 중에서 세종대왕이 현수가 다스릴 수 있는 땅의 크기(세로의 길이와 가
로의 길이)를 정해주면 전체 땅 중에서 그 크기의 땅의 위치를 현수가 정하면 되는 것이다.
전체 땅은 사각형의 모양의 격자로 되어 있으며, 그 사각형 땅 안에는 많은 오렌지 나무가 심
겨져 있다. 현수는 오렌지를 무척 좋아하여 오렌지 나무가 가장 많이 포함되는 지역을 선택하
고 싶어 한다. 현수가 얻을 수 있는 영지의 오렌지 나무 최대 개수를 출력하는 프로그램을 작
성하세요. 다음과 같은 땅의 정보가 주어지고, 현수가 하사받을 크기가, 가로 2, 세로 3의 크
기이면 가장 많은 오렌지 나무가 있는 영지는 총 오렌지 나무의 개수가 16인 3행 4열부터 시
작하는 구역이다.
3 5 1 3 1 3 2
1 2 1 3 1 1 2
1 3 1 5 1 3 4
5 1 1 3 1 3 2
3 1 1 3 1 1 2
1 3 1 3 1 2 2
▣ 입력설명
첫 줄에 H(세로길이)와 W(가로길이)가 입력된다. (5<=H, W<=50) 그 다음 H줄에 걸쳐 각 사
각형 지역에 오렌지의 나무 개수(1~9개) 정보가 주어진다.
그 다음 영지의 크기인 세로길이(1~H)와 가로길이(1~W)가 차례로 입력된다.
▣ 출력설명
첫 줄에 현수가 얻을 수 있는 오렌지 나무의 최대 개수를 출력한다.*/


int main() {
	int h, w;
	cin >> h >> w;
	int** a = new int* [h];
	for (int i = 0; i < h; i++) {
		a[i] = new int[w];
		for (int j = 0; j < w; j++) cin >> a[i][j];
	}


	int height, width;
	cin >> height >> width;
	int* dx = new int[height * width];
	int* dy = new int[height * width];
	int count = 0;
	for (int i = 0; i < height; i++) 
		for (int j = 0; j < width; j++) {
			dx[count] = j;
			dy[count++] = i;
		}


	int max = 0;
	int sum = 0;
	for (int i = 0; i < h - height + 1; i++) {
		for (int j = 0; j < w - width + 1; j++) {
			for (int k = 0; k < count; k++) 
				sum += a[i + dy[k]][j + dx[k]];
			max = max < sum ? sum : max;
			sum = 0;
		}
	}
	cout << max;
	delete[] a;
	return 0;
}


/*
모범 답안

#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a[51][51];
int main(){
	freopen("input.txt", "rt", stdin);
	int h, w, n, m, i, j, k, s, sum=0, max=-2147000000;
	scanf("%d %d", &h, &w);
	for(i=1; i<=h; i++){
		for(j=1; j<=w; j++){
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d %d", &n, &m);
	for(i=1; i<=h-n+1; i++){
		for(j=1; j<=w-m+1; j++){
			sum=0;
			for(k=i; k<i+n; k++){
				for(s=j; s<j+m; s++){
					sum=sum+a[k][s];
				}
			}
			if(sum>max){
				max=sum;
			}
		}
	}
	printf("%d\n", max);
	return 0;
}*/