/*
 ============================================================================
 Name        : XO_proj.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
// =============== global var ==========================
char var1 , var2 , var ,arr[3][3];
int num , f = 1;
// =============== functions =======================
void places();
void tackplace();
void print();
void SaveElement();
int winner();

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Player1 will take X or O :  ");
	scanf("%c", &var);
	if(var == 'X' || var == 'x')
	{
		var1 = 'x';
		var2 = 'o';
	}
	else if(var == 'O' || var == 'o')
	{
		var1 = 'o';
		var2 = 'x';
	}
	places();
    tackplace();
	return 0;
}

void places()
{
	printf("\t\t|  1  |  2  |  3  |\n");
	printf("\t\t|  4  |  5  |  6  |\n");
	printf("\t\t|  7  |  8  |  9  |\n");
	printf("\n");
	printf("\n");
}
void tackplace()
{
	for (int i = 0 ; i < 4 ; i++)
	{
		if(f)
		{
			printf("where will player1 play?\n");
				scanf("%d" , &num);
				if(num >= 1 && num <= 3)
				{
					arr[0][num-1] = var1;
				}
				else if(num >= 4 && num <= 6)
				{
					arr[1][num-4] = var1;
					//printf("%c" , arr[0][num-1]);
				}
				else if(num >= 7 && num <= 9)
				{
					arr[2][num-7] = var1;
					//printf("%c" , arr[0][num-1]);
				}
				SaveElement();
				 f = winner();
				if(f == 1)
				{
					printf("where will player2 play?\n");
								scanf("%d" , &num);
								if(num >= 1 && num <= 3)
								{
									arr[0][num-1] = var2;
									//printf("%c" , arr[0][num-1]);
								}
								else if(num >= 4 && num <= 6)
								{
									arr[1][num-4] = var2;
									//printf("%c" , arr[0][num-1]);
								}
								else if(num >= 7 && num <= 9)
								{
									arr[2][num-7] = var2;
									//printf("%c" , arr[0][num-1]);
								}
								SaveElement();
								//print();
								 f = winner();
				}
		}
	}
	if(f)
	{
		printf("where will player1 play?\n");
				scanf("%d" , &num);
				if(num >= 1 && num <= 3)
				{
					arr[0][num-1] = var1;
				}
				else if(num >= 4 && num <= 6)
				{
					arr[1][num-4] = var1;
				}
				else if(num >= 7 && num <= 9)
				{
					arr[2][num-7] = var1;
				}
				SaveElement();
				//print();
				f = winner();
	}
	if(f)
	{
		printf("NO one win");
	}

}

void SaveElement()
{
	for(int i = 0 ; i < 3 ; i++)
	{
		for(int j = 0 ; j < 3 ; j++)
		{
			if(!(arr[i][j] == 'x' || arr[i][j]  == 'o' || arr[i][j] == 'X' || arr[i][j]  == 'O'))
			{
				arr[i][j] = ' ';
			}
		}
	}
	print();
}
void print()
{
	printf("\t\t|  %c  |  %c | %c   |\n" ,arr[0][0] ,arr[0][1] ,arr[0][2] );
	printf("\n");
	printf("\t\t|  %c  |  %c | %c   |\n" ,arr[1][0] ,arr[1][1] ,arr[1][2] );
	printf("\n");
	printf("\t\t|  %c  |  %c | %c   |\n" ,arr[2][0] ,arr[2][1] ,arr[2][2] );
	printf("\n");
	printf("\n");
}

int winner()
{
    if (
        (arr[0][0] == var1 && arr[0][1] == var1 && arr[0][2] == var1) ||
        (arr[1][0] == var1 && arr[1][1] == var1 && arr[1][2] == var1) ||
        (arr[2][0] == var1 && arr[2][1] == var1 && arr[2][2] == var1) ||

        (arr[0][0] == var1 && arr[1][0] == var1 && arr[2][0] == var1) ||
        (arr[0][1] == var1 && arr[1][1] == var1 && arr[2][1] == var1) ||
        (arr[2][0] == var1 && arr[2][1] == var1 && arr[2][2] == var1) ||

        (arr[0][0] == var1 && arr[1][1] == var1 && arr[2][2] == var1) ||
        (arr[0][2] == var1 && arr[1][1] == var1 && arr[2][0] == var1)
        )
    {
    	printf("player1 win");
    	f = 0;
    }
    else if (
        (arr[0][0] == var2 && arr[0][1] == var2 && arr[0][2] == var2) ||
        (arr[1][0] == var2 && arr[1][1] == var2 && arr[1][2] == var2) ||
        (arr[2][0] == var2 && arr[2][1] == var2 && arr[2][2] == var2) ||

        (arr[0][0] == var2 && arr[1][0] == var2 && arr[2][0] == var2) ||
        (arr[0][1] == var2 && arr[1][1] == var2 && arr[2][1] == var2) ||
        (arr[2][0] == var2 && arr[2][1] == var2 && arr[2][2] == var2) ||

        (arr[0][0] == var2 && arr[1][1] == var2 && arr[2][2] == var2) ||
        (arr[0][2] == var2 && arr[1][1] == var2 && arr[2][0] == var2)
        )
    {
    	printf("player2 win");
    	f = 0;
    }
   /* else
    {
    	printf("NO one win");
    }*/

    return f;

}
