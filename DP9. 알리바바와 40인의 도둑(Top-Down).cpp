#include <iostream>
using namespace std;

int n;
int** a;
bool** flag;

int run(int x, int y) {
	int leftside;
	int topside;
	if (x == 0) {
		if (y == 0) {
			leftside = 0;
			topside = 0;
		}
		else {
			leftside = !flag[x][y - 1] ? a[x][y - 1]:run(x, y - 1);
			topside = 10000000;
		}
	}
	else if (y == 0) {
		leftside = 10000000;
		topside = !flag[x - 1][y] ? a[x - 1][y] : run(x - 1, y);
	}
	else {
		leftside = !flag[x][y - 1] ? a[x][y - 1] : run(x, y - 1);
		topside = !flag[x - 1][y] ? a[x - 1][y] : run(x - 1, y);
	}
	a[x][y] += (leftside < topside) ? leftside : topside;
	flag[x][y] = false;
	return a[x][y];
}

int main() {
	cin >> n;
	a = new int* [n];
	flag = new bool* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		flag[i] = new bool[n];
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}
	cout << run(n - 1, n - 1);
}