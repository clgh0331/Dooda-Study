#include <stdio.h>

bool triangle_draw[3072][6145];

int get_height(int k) {
	int height = 2;
	
	for(int i = 0; i < k; i++) height *= 2;
	
	return height * 3;
}

int get_k(int N) {
	int k = 0;
	int temp = N / 3;
	
	while (temp > 1) {
		temp /= 2;
		k ++;
	}
	
	return k;
}

void triangle_print(int n, int x, int y) {
	
}

void print_triangle(int width, int height) {
	for(int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (!triangle_draw[j][i]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}
int main() {
	int N, k, height, width;
	
	scanf("%d", &N);
	
	height = N;
	width = N * 2 - 1;
	
	print_triangle(width, height);
}
