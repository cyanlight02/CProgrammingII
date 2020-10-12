 네모네모로직
## 문제
[(위키백과 링크)](https://ko.wikipedia.org/wiki/%EB%85%B8%EB%85%B8%EA%B7%B8%EB%9E%A8_)

네모네모로직은 스도쿠와 비슷한, 일본의 퍼즐게임입니다. 적혀있는 숫자를 보면서 숨겨진 숫자를 예상하여 그림을 완성해나가며 그림을 그리는 게임입니다.

네모네모로직의 전체 보드는 다음과 같이 구성되어 있습니다.

## hor_quest[10][5]
hor_quest[i][5]에는 가로 [i]번째 줄의 힌트가 적혀있습니다.

## ver_quest[10][5]
ver_quest[i][5]에는 세로 [i]번째 줄의 힌트가 적혀있습니다.
## board[10[10]
아직 맞히지 못한 칸과 정답을 맞힌 칸이 {?,  ,1} 중 하나로 출력됩니다.

맞히지 못한 칸을 0, 정답을 맞힌 칸을 1 or 2로 설정하는 것을 권장합니다.

## void print_board(void)
i행 j열에 대해서 i, j값에 따라서 다음과 같이 출력한다.


1. i = 0 ~ 4\
	1-1. j = 0 ~ 4: 공백출력\
	1-2. j = 5 ~ 14: ver_quest[j-5][i]가 0이 아니면 출력

2. "(공백문자*6)#######################\n"으로 보드와 힌트를 구분

3. i = 5 ~ 14\
	3-1. j = 0 ~ 4: hor_quest[i-5][j]가 0이 아니면 출력 + "#"로 보드와 힌트를 구분\
	3-2. j = 5 ~ 14: board[i-5][j-5]를 출력



## 입력받은 좌표 & 지시에 따른 연산
입력받은 좌표가 존재할 경우, 다음과 같이 진행합니다.

지시 = 빈칸(채우기)일 때
  1. 만약 해당 칸의 정답(answer[][])이 빈칸(채우기)일 경우\
  	1-1. 해당 칸의 정답을 이전에 맞히지 않은 경우\
		-> 해당 좌표를 빈칸으로 표시\
		-> 이미 해결한 좌표임을 설정하여 중복제출을 막음\
		-> 해결한 좌표의 수 +1\
    1-2. 해당 칸의 정답을 이전에 맞힌 경우\
		-> 이미 입력한 좌표임을 알림
      
  2. 만약 해당 칸의 정답(answer[][])이 빈칸(채우기)이 아닌 경우\
		-> 해당 칸의 정답이 빈칸(채우기)이 아님을 알림\
		-> 기회 차감



## 문제 (game.c)

```C
#include <stdio.h>
#include "answer.h"

int board[10][10]   = {};		// 로직퍼즐의 보드. (가로길이+1)/2 + 가로길이, (세로길이+1)/2 + 세로길이("?", "0", " ")

int bsolved[10][10] = {};		// 보드의 해결여부 표시.	(0, 1)
int solved = 0;				// 해결한 좌표의 갯수
int chance = 5;				// 기회의 갯수. 틀릴 때마다 1씩 차감

void print_board() {	// 보드 전체를 출력하는 함수
	for (int i = 0; i < 5; i++) {
	// 여기에 행i = 0 ~ 4일 때의 경우 입력
	}
	printf("      #######################\n");
	for (int i = 5 ; i < 15; i++) {
	// 여기에 행i = 5 ~ 14일 때의 경우 입력
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
```


## 힌트&정답 (answer.h)
answer.lib에 선언되어 있는 배열들의 이름이 들어있습니다.
```C
#pragma once

//문제의 답
//======================================================
extern int answer[10][10];

// 출력되는 흰트
// 흰트의 가로(세로)[줄번호][숫자집합], 각 줄마다 있을 수 있는 숫자의 최대 갯수는 [길이+1/2]
//======================================================
// 가로 흰트
extern int hor_quest[10][5];
// 세로 흰트
extern int ver_quest[10][5];
```

## 힌트&정답 (answer.lib)
힌트와 정답의 값이 들어있는 파일입니다.
debug, x64 플랫폼입니다.

