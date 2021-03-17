﻿#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/*
86. 피자 배달 거리(삼성 SW역량평가 기출문제 : DFS활용)
N×N 크기의 도시지도가 있습니다. 도시지도는 1×1크기의 격자칸으로 이루어져 있습니다. 각
격자칸에는 0은 빈칸, 1은 집, 2는 피자집으로 표현됩니다. 각 격자칸은 좌표(행번호, 열 번호)
로 표현됩니다. 행번호는 1번부터 N번까지이고, 열 번호도 1부터 N까지입니다.
도시에는 각 집마다 “피자배달거리”가 았는데 각 집의 피자배달거리는 해당 집과 도시의 존재
하는 피자집들과의 거리 중 최소값을 해당 집의 “피자배달거리”라고 한다.
집과 피자집의 피자배달거리는 |x1-x2|+|y1-y2| 이다.
예를 들어, 도시의 지도가 아래와 같다면
0 1 0 0
0 0 2 1
0 0 1 0
1 2 0 2
(1, 2)에 있는 집과 (2, 3)에 있는 피자집과의 피자 배달 거리는 |1-2| + |2-3| = 2가 된다.
최근 도시가 불경기에 접어들어 우후죽순 생겼던 피자집들이 파산하고 있습니다. 도시 시장은
도시에 있는 피자집 중 M개만 살리고 나머지는 보조금을 주고 폐업시키려고 합니다.
시장은 살리고자 하는 피자집 M개를 선택하는 기준으로 도시의 피자배달거리가 최소가 되는
M개의 피자집을 선택하려고 합니다.
도시의 피자 배달 거리는 각 집들의 피자 배달 거리를 합한 것을 말합니다.
▣ 입력설명
첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 12)이 주어진다.
둘째 줄부터 도시 정보가 입력된다.
▣ 출력설명
첫째 줄에 M개의 피자집이 선택되었을 때 도시의 최소 피자배달거리를 출력한다.*/class house {public:	int x;	int y;	int value;	house() {		x = y = value = 0;	}	house(int x, int y) {		this->x = x;		this->y = y;		value = 100000000;	}};class pizza {
public:	int x;	int y;	pizza() {		x = 0;		y = 0;	}	pizza(int x, int y) {		this->x = x;		this->y = y;	}};vector<house> h;vector<pizza> p;int n, m, cnt, cnt_h, cnt_p, min=100000000;int* ch;void DFS(int L) {	if (L == cnt_p && cnt == m){		int sum = 0;		for (int i = 0; i < cnt_h; i++) {			for (int j = 0; j < cnt_p; j++) {				if (ch[j] == 1) {					h[i].value = (h[i].value < abs(p[j].x - h[i].x) + abs(p[j].y - h[i].y))						? h[i].value : abs(p[j].x - h[i].x) + abs(p[j].y - h[i].y);				}			}			sum += h[i].value;			h[i].value = 100000000;		}		min = min < sum ? min : sum;	}	else {		if (ch[L] == 0) {			ch[L] = 1;			cnt++;			DFS(L + 1);			ch[L] = 0;			cnt--;			DFS(L + 1);		}	}}int main() {	cin >> n >> m;	for (int i = 0; i < n; i++) {		for (int j = 0; j < n; j++) {			int num;			cin >> num;			if (num == 1) {				house ho(i + 1, j + 1);				h.push_back(ho);				cnt_h++;			}			else if (num == 2) {				pizza pi(i + 1, j + 1);				p.push_back(pi);				cnt_p++;			}		}	}	ch = new int[cnt_p];	for (int i = 0; i < cnt_p; i++) ch[i] = 0;	DFS(0);	cout << min;	return 0;}         //최적화를 찾아보자.