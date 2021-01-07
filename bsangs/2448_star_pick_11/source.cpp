#include <stdio.h>

// triangle_draw[x][y] 와 같이 사용
bool triangle_draw[6145][3072];

void triangle_mapping(int triangle_count, int x, int y) {
	/*
		실질적 재귀함수
		triangle_count: 세로로 삼각형을 쌓을 수 있는 양 (1이면 가장 깊은 depth)
		x: x offset
		y: y offset
	*/

	// offset 기준으로 가장 작은 삼각형 그리기
	if (triangle_count <= 1) {
		triangle_draw[x][y] = true;
		triangle_draw[x - 1][y + 1] = true;
		triangle_draw[x + 1][y + 1] = true;
		for (int i = -2; i <= 2; i++) triangle_draw[x + i][y + 2] = true;
		return;
	}

	// 해당 위치
	triangle_mapping(triangle_count / 2, x, y);

	// 왼쪽 아래
	triangle_mapping(triangle_count / 2, x - (triangle_count * 3 / 2), y + (triangle_count * 3 / 2));

	// 오른쪽 아래
	triangle_mapping(triangle_count / 2, x + (triangle_count * 3 / 2), y + (triangle_count * 3 / 2));
}

void print_triangle(int width, int height) {
	for(int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (triangle_draw[j][i]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}
int main() {
	int N, triangle_count, height, width;
	
	scanf("%d", &N);
	
	// 출력할 때 쓰는 높이
	height = N;

	// 출력할 대 쓰는 폭
	width = N * 2 - 1;

	triangle_count = N / 3;
	
	// 배열이 0부터 시작하니까 처음엔 x에 -1을 넣어줌
	triangle_mapping(triangle_count, N - 1, 0);
	
	// 출력
	print_triangle(width, height);
}
