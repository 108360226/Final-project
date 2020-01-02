#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game();
void show();

int main(void)
{
	char input;                                  //��ENTER�i�J�C��

	show();

	scanf_s("%c", &input);

	if (input = '13')                            //13=ENTER
	{
		game();                                  //�Y��ENTER,�i�J�C���D�{��
	}

	system("pause");
}

void show(void)
{
	printf("���Ӥj����\n\n");
	printf("�C������:\n");
	printf("�C�������H�m��\n");
	printf("PLAYER1����䬰:A S D,PLAYER2����䬰:J K L\n");
	printf("����o1���i�J�U�D\n");
	printf("�����h���o1��,�~��@��\n");
	printf("�v���F��5�������\n");
	printf("\n��ENTER��}�l�C��\n");
}

void game(void)
{
	typedef struct question
	{
		char Q[50];
		int A;
		int S[3];
	}_math;                                          //�ŧi�D�w

	int i, j;                                        //�����D�w
	_math temp;                                      //�D�w�Ȧs
	int score1 = 0;  
	int score2 = 0;                                  //����
	char key;                                        //Ū�����
	int ans1 = 100;
	int	ans2 = 100;                                  //����ഫ��������
	int l_ans1 = 100;
	int l_ans2 = 100;

	_math math[10] = { { "3x7+5",26,{26,21,36} } ,
					   { "8x9-36",36,{34,36,38}} ,
					   { "8+8x8+8",80,{256,136,80}} ,
					   { "(4!)��6+2",6 ,{6,3,4}} ,
	                   { "2x5-5x2",0,{0,20,10} } ,
					   { "1!+9x2!",19,{20,18,19} } ,
					   { "0!",1,{2,1,0} } ,
					   { "5+5-5x5",-15,{-5,-15,-10} } ,
					   { "6x3-7+5",16,{16,26,36} } ,
					   { "���@�պA��X�Ϭ�(1:CC,2:CB,3:CE)",3,{1,2,3} } };

	srand(time(NULL));

	for (i = 0; i < 10; i++)
	{
		j = rand() % 10;
		temp = math[i];
		math[i] = math[j];
		math[j] = temp;
	}                                                        //�����D�w����

	system("cls");                                           //�M���W�h

	while ((score1 < 5) && (score2 < 5))
	{
		for (i = 0; i < 10; i++)
		{
			while ((math[i].A != ans1) && (math[i].A != ans2))
			{
				printf("PLAYER1:%d\t\t\t\t\t\t\t\tPLAYER2:%d", score1, score2);
				printf("\n\n\n\t\t\t\t\t%s\n\n\n\n\n\n", math[i].Q);
				printf("\t%d\t%d\t%d\t\t\t\t\t%d\t%d\t%d\n"
					, math[i].S[0], math[i].S[1], math[i].S[2], math[i].S[0], math[i].S[1], math[i].S[2]);
				printf("\tA\tS\tD\t\t\t\t\tJ\tK\tL\n");
				
				key = getch();

				if (key == 'a' || key == 'A')
				{
					ans1 = math[i].S[0];
				}
				else if (key == 'j' || key == 'J')
				{
					ans2 = math[i].S[0];
				}
				else if (key == 's' || key == 'S')
				{
					ans1 = math[i].S[1];
				}
				else if (key == 'k' || key == 'K')
				{
					ans2 = math[i].S[1];
				}
				else if (key == 'd' || key == 'D')
				{
					ans1 = math[i].S[2];
				}
				else if (key == 'l' || key == 'L')
				{
					ans2 = math[i].S[2];
				}

				if (ans1 != l_ans1)
				{
					if (ans1 != math[i].A)
					{
						score2++;
						l_ans1 = ans1;
					}
				}
				if (ans2 != l_ans2)
				{
					if (ans2 != math[i].A)
					{
						score1++;
						l_ans2 = ans2;
					}
				}
				system("cls");
			}
			
			if (ans1 != l_ans1)
			{
				if (ans1 == math[i].A)
				{
					score1++;
					l_ans1 = 100;
					ans1 = 100;
				}
			}
			if (ans2 != l_ans2)
			{
				if (ans2 == math[i].A)
				{
					score2++;
					l_ans2 = 100;
					ans2 = 100;
				}
			}
			if (score1 == 5 || score2 == 5)
			{
				i = 100;                         //�j�����}for loop
			}

			system("cls");
		}
	}
	
	if (score1 == 5)
	{
		system("cls");
		printf("PLAYER1 WIN\n\n\n\n");
	}
	else if (score2 == 5)
	{
		system("cls");
		printf("PLAYER2 WIN\n\n\n\n");
	}
}

