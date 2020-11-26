#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int print_game (int _num, int _addnum1, int _addnum2) {
	printf("----------------------------------\n");
	for (int i = 0; i < _addnum1; i++) {
		printf("%d ", _num + i);
		if (_num + i >= 31) {
			printf("\n컴퓨터의 승리입니다.\n");
			printf("----------------------------------\n");
			return -1;
		}
	}
	printf("\n");
	for (int i = 0; i < _addnum2; i++) {
		printf("%d ", _num + _addnum1 + i);
		if (_num + _addnum1 + i >= 31) {
			printf("\n당신의 승리입니다.\n");
			printf("----------------------------------\n");
			return -1;
		}
	}
	printf("\n");
	printf("----------------------------------\n");

	return _num + _addnum1 + _addnum2;
}	


int main(void)
{
	srand((unsigned int)time);

	int num, player_num, com_num;
	num = 1;
	player_num = -1;

	printf("컴퓨터와 베스킨라빈스31 게임을 진행합니다.\n");
	while (num <= 31) {
		do {
			printf("숫자 몇 개를 말할지 선택하세요: ");
			scanf_s("%d", &player_num);
			if (player_num > 3 || player_num <= 0)
				printf("1 ~ 3 사이의 숫자를 입력해주세요.\n\n");
		} while (player_num > 3 || player_num <= 0);
		com_num = rand() % 3 + 1;
		
		num = print_game(num, player_num, com_num);
		if (num == -1)
			break;
	}
}