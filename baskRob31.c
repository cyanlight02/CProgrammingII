#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int print_game (int _num, int _addnum1, int _addnum2) {
	printf("----------------------------------\n");
	for (int i = 0; i < _addnum1; i++) {
		printf("%d ", _num + i);
		if (_num + i >= 31) {
			printf("\n��ǻ���� �¸��Դϴ�.\n");
			printf("----------------------------------\n");
			return -1;
		}
	}
	printf("\n");
	for (int i = 0; i < _addnum2; i++) {
		printf("%d ", _num + _addnum1 + i);
		if (_num + _addnum1 + i >= 31) {
			printf("\n����� �¸��Դϴ�.\n");
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

	printf("��ǻ�Ϳ� ����Ų���31 ������ �����մϴ�.\n");
	while (num <= 31) {
		do {
			printf("���� �� ���� ������ �����ϼ���: ");
			scanf_s("%d", &player_num);
			if (player_num > 3 || player_num <= 0)
				printf("1 ~ 3 ������ ���ڸ� �Է����ּ���.\n\n");
		} while (player_num > 3 || player_num <= 0);
		com_num = rand() % 3 + 1;
		
		num = print_game(num, player_num, com_num);
		if (num == -1)
			break;
	}
}