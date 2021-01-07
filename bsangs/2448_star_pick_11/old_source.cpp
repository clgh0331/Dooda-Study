#include <stdio.h>
#include <math.h>

int list[8000][8000];

void draw(int x_offset, int y_offset) {
	list[y_offset][x_offset] = 1;
	for (int i = 1; i < 3; i++) {
		for (int j = 0; j < 5; j++) {
			if ((i + j) % 2 == 0 || i == 2)
				list[y_offset + i][x_offset + j - 2] = 1;
		}
	}
}

void func(int k, int x_offset, int y_offset) {
	if (k < 0) return;
	if (k == 0) draw(x_offset, y_offset);
	int offset = (k > 0) ? pow(2, k - 1) * 3 : 0;

	func(k - 1, x_offset, y_offset);
	func(k - 1, x_offset + offset, y_offset + offset);
	func(k - 1, x_offset - offset, y_offset + offset);
	
}

int main() {
	int n, k;
	scanf("%d", &n);

	k = log2(n / 3);
	func(k, n - 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2 - 1; j++) {
			printf((list[i][j] == 1) ? "*" : " ");
		}
		printf("\n");
	}
}