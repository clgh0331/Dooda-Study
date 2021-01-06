#include <stdio.h>

bool triangle_draw[6145][3072];

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

void triangle_mapping(int triangle_count, int x, int y) {
	/*
		실질적 재귀함수
		triangle_count: 세로로 삼각형을 쌓을 수 있는 양 (1이면 가장 깊은 depth)
		x: x offset
		y: y offset
	*/

	if (triangle_count == 1) {
		triangle_draw[x + 2][y] = true;
		triangle_draw[x + 1][y + 1] = true;
		triangle_draw[x + 3][y + 1] = true;
		for (int i = 0; i < 5; i++) triangle_draw[x + i][y + 2] = true;
		return;
	}
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
	int N, triangle_height, height, width;
	
	scanf("%d", &N);
	
	// 출력할 때 쓰는 높이
	height = N;

	// 출력할 대 쓰는 폭
	width = N * 2 - 1;

	// triangle_mapping 에서 용도 설명
	triangle_count = N / 3;
	
	triangle_mapping(triangle_count, 0, 0)
	
	print_triangle(width, height);
}
