



#include "game.h" 


void menu()
{
	printf("##################################################\n");
	printf("######             1.��Ҫϴ��              #######\n");
	printf("######             0.�˳�                  #######\n");
	printf("######           PLEASE  SELECT  :          #######\n");

}
void game()
{
	char board[ROW][COL] = { 0 };
	int i = 0;
	chushiqipan(board, ROW, COL);//��ʼ������
	displayboard(board, ROW, COL);//��ʾ���ù�ģ
	while (i == 0) {
		moveboard(board, ROW, COL);//ѧ��ѡ��λ��
		displayboard(board, ROW, COL);//��ʾ���ù�ģ
		Sleep(1000);//ԤԼʱ��
		chushiqipan(board, ROW, COL);//��ʼ������
		displayboard(board, ROW, COL);//��ʾ���ù�ģ
		i = IFull(board, ROW, COL);//�ж�������û��
	}

}
int main()
{
	int select = 0;


		do {
			menu();
			printf("������>:");
			scanf("%d", &select);
			switch (select)
			{
			case 1:
				game();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("�����������������>:");
				break;
			}

		} while (select);

	system("pause");
	return 0;
}