#include <stdio.h>
#include "answer.h"

int board[10][10]   = {};		// 로직퍼즐의 보드. (가로길이+1)/2 + 가로길이, (세로길이+1)/2 + 세로길이("?", "0", " ")

int bsolved[10][10] = {};		// 보드의 해결여부 표시.	(0, 1)
int solved = 0;				// 해결한 좌표의 갯수
int chance = 5;				// 기회의 갯수. 틀릴 때마다 1씩 차감

void print_board() {	// 보드 전체를 출력하는 함수
	for (int i = 0; i < 5; i++) {
	// 여기에 i = 0 ~ 4일 때의 경우 입력
	}
	printf("      #######################\n");
	for (int i = 5 ; i < 15; i++) {
	// 여기에 i = 5 ~ 14일 때의 경우 입력
	}
	printf("      #######################\n");
}

//규칙
// 빈칸표시, 채우기 표시를 입력받아서 정답과 동일한 경우 해당칸을 변경
// 정답과 다른 경우 기회 차감
// 기회 0인 경우 게임오버

int main (void) {

	while ((solved < 100) && (chance > 0)) {				// 해결한 블록의 갯수가 (가로x세로) 이하일때 반복
		print_board();
		int check;							// 좌표에 입력할 명령 (채우기, 빈칸표시 하기)
		int ver, hor;							// 입력받을 (가로, 세로) 좌표

		printf("좌표와 지시를 입력해주세요 (가로, 세로, 지시)\n");
		printf("빈칸표시: 0, 채우기: 1\n");
		scanf_s("%d %d %d", &ver, &hor, &check);

		/*
		if (올바른 좌표일 경우) {
			check 값에 따른 연산
		} else {
			printf("올바른 좌표를 입력해주세요.\n");
		}
		*/
		printf("남은 기회: %d\n\n\n\n\n\n\n\n\n", chance);
	}
	print_board();
	if (solved == 100) {
		printf("퍼즐을 모두 풀었습니다!\n");
	}
	if (chance <= 0) {
		printf("Game Over\n");
	}
}
