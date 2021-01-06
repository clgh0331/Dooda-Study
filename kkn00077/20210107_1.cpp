#include <iostream>
#include <typeinfo> 
using namespace std;

class Triangle {
private:
	char default_triangle[3][6] = { "  *  ", " * * ", "*****" };
	char** board;
	int len;

public:
	Triangle(int len) {
		this->len = len;
		this->board = new char* [len];

		for (int i = 0; i < len; i++) {
			this->board[i] = new char[len * 2];
			for (int j = 0; j < len * 2; j++) {
				this->board[i][j] = '\0';
			}
		}

	}

	~Triangle() {
		for (int i = 0; i < len; i++) {
			delete[] board[i];
		}
		delete[] board;
	}

	void print_triangle() {
		int col = len * 2;// _msize(board[0]);
		int row = len;// _msize(board);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}

	// 기본 삼각형 그리는 함수
	void draw_triangle(int y, int x) {

		// c에서는 문자열 끝에 null 값이 들어가므로 문자열 길이 - 1 해줌
		int triangle_w = sizeof(default_triangle[0]) / sizeof(char) - 1;
		int triangle_h = sizeof(default_triangle) / sizeof(default_triangle[0]);

		for (int i = 0; i < triangle_h; i++) {
			for (int j = 0; j < triangle_w; j++) {
				board[y + i][x + j - 2] = default_triangle[i][j];
			}
		}
	}

	// 프렉탈 그리기
	void make_triangle(int y, int x, int line = -1) {

		if (line == -1) line = this->len;

		if (line == 3) {
			// 삼각형 그리기
			draw_triangle(y, x);
			return;
		}

		// 사실상 삼각형 그려주는 역할
		make_triangle(y, x, line / 2);

		// 상단에 있는 삼각형 하단 - 좌측에 위치한 삼각형
		make_triangle(y + line / 2, x - line / 2, line / 2);

		// 상단에 있는 삼각형 하단 - 우측에 위치한 삼각형
		make_triangle(y + line / 2, x + line / 2, line / 2);
	}

};


int main() {
	int line = 0;

	//cout << "삼각형의 높이를 입력하시오 : ";
	cin >> line;

	Triangle triangle = Triangle(line);

	// 가장 큰 삼각형을 그리기 위해 가장 상단에 위치한 꼭짓점 좌표를 넘겨줌
	// board의 크기가 row = len, col = len * 2 이기 때문에 중앙에 별을 찍기 위해서 len / 2
	triangle.make_triangle(0, line - 1);
	triangle.print_triangle();

	return 0;
}
