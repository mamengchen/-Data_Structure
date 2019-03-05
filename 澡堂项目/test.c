



#include "game.h" 


void menu()
{
	printf("##################################################\n");
	printf("######             1.我要洗澡              #######\n");
	printf("######             0.退出                  #######\n");
	printf("######           PLEASE  SELECT  :          #######\n");

}
void game()
{
	char board[ROW][COL] = { 0 };
	int i = 0;
	chushiqipan(board, ROW, COL);//初始化澡堂
	displayboard(board, ROW, COL);//显示澡堂规模
	while (i == 0) {
		moveboard(board, ROW, COL);//学生选择位置
		displayboard(board, ROW, COL);//显示澡堂规模
		Sleep(1000);//预约时间
		chushiqipan(board, ROW, COL);//初始化澡堂
		displayboard(board, ROW, COL);//显示澡堂规模
		i = IFull(board, ROW, COL);//判断澡堂满没有
	}

}
int main()
{
	int select = 0;


		do {
			menu();
			printf("请输入>:");
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
				printf("输入错误，请重新输入>:");
				break;
			}

		} while (select);

	system("pause");
	return 0;
}