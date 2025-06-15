#include<iostream>
#include<Windows.h>
#include<fstream>
#include<graphics.h>
#include <conio.h>

using namespace std;

#define EXIT 'q'
#define UP 'w'
#define RIGHT 'd'
#define LEFT 'a'
#define DOWN 's'

int arr[9][12] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 0, 1, 4, 1, 0, 2, 1, 0, 2, 1, 0, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0 },
	{ 0, 1, 0, 2, 0, 1, 1, 4, 1, 1, 1, 0 },
	{ 0, 1, 1, 1, 0, 3, 1, 1, 1, 4, 1, 0 },
	{ 0, 1, 2, 1, 1, 4, 1, 1, 1, 1, 1, 0 },
	{ 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

struct Port
{
	int x;
	int y;
};

enum gameData
{
	WALL,    //墙
	FLOOR,   //地板
	DES,   //目标
	MAN,     //人
	BOX,     //箱子
	HIT      //命中
};

gameData Next(char driorct, Port man, int next = 1)
{
	if (driorct == UP)
	{
		switch (arr[man.x - next][man.y])
		{
		case 0:
			return WALL;
		case 1:
			return FLOOR;
		case 2:
			return DES;
		case 4:
			return BOX;
		}
	}
	if (driorct == DOWN)
	{
		switch (arr[man.x + next][man.y])
		{
		case 0:
			return WALL;
		case 1:
			return FLOOR;
		case 2:
			return DES;
		case 4:
			return BOX;
		}
	}
	if (driorct == LEFT)
	{
		switch (arr[man.x][man.y - next])
		{
		case 0:
			return WALL;
		case 1:
			return FLOOR;
		case 2:
			return DES;
		case 4:
			return BOX;
		}
	}
	if (driorct == RIGHT)
	{
		switch (arr[man.x][man.y + next])
		{
		case 0:
			return WALL;
		case 1:
			return FLOOR;
		case 2:
			return DES;
		case 4:
			return BOX;
		}
	}
}

bool isWin()
{
	//是否赢了；
	return false;
}


int main()
{
	initgraph(1000, 700);


	IMAGE images[5] = { 0 };

	//****************************************************************初始化界面
	loadimage(0, _T("blackground.bmp"));

	loadimage(&images[0], _T("wall_right.bmp"));
	loadimage(&images[1], _T("floor.bmp"));
	loadimage(&images[2], _T("des.bmp"));
	loadimage(&images[3], _T("man.bmp"));
	loadimage(&images[4], _T("box.bmp"));

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			putimage(134 + j * 61, 75 + i * 61, &images[arr[i][j]]);
		}
	}
	//****************************************************************按键绑定
	Port man = { 5,5 };
	bool emp = true;
	do
	{
		char kb = _getch();
		if (kb == EXIT)							//q键退出
		{
			break;
		}
		else if (kb == UP)						//w键上升			
		{
			if (Next(UP, man) == FLOOR)
			{
				putimage(134 + man.y * 61, 75 + (man.x - 1) * 61, &images[MAN]);
				arr[man.x - 1][man.y] = MAN;
				putimage(134 + man.y * 61, 75 + man.x * 61, &images[FLOOR]);
				arr[man.x][man.y] = FLOOR;
				man.x -= 1;
			}
			else if (Next(UP, man) == BOX)
			{
				if (Next(UP, man, 2) == FLOOR)
				{
					putimage(134 + man.y * 61, 75 + (man.x - 1) * 61, &images[MAN]);
					arr[man.x - 1][man.y] = MAN;
					putimage(134 + man.y * 61, 75 + man.x * 61, &images[FLOOR]);
					arr[man.x][man.y] = FLOOR;
					putimage(134 + man.y * 61, 75 + (man.x - 2) * 61, &images[BOX]);
					arr[man.x - 2][man.y] = BOX;
					man.x -= 1;
				}
				else if (Next(UP, man, 2) == DES)
				{
					putimage(134 + man.y * 61, 75 + (man.x - 1) * 61, &images[MAN]);
					arr[man.x - 1][man.y] = MAN;
					putimage(134 + man.y * 61, 75 + man.x * 61, &images[FLOOR]);
					arr[man.x][man.y] = FLOOR;
					putimage(134 + man.y * 61, 75 + (man.x - 2) * 61, &images[BOX]);
					arr[man.x - 2][man.y] = HIT;
					man.x -= 1;
				}
			}
		}
		else if (kb == DOWN)					 //s键下降
		{
			if (Next(DOWN, man) == FLOOR)
			{
				putimage(134 + man.y * 61, 75 + (man.x + 1) * 61, &images[MAN]);
				arr[man.x + 1][man.y] = MAN;
				putimage(134 + man.y * 61, 75 + man.x * 61, &images[FLOOR]);
				arr[man.x][man.y] = FLOOR;
				man.x += 1;
			}
			else if (Next(DOWN, man) == BOX)
			{
				if (Next(DOWN, man, 2) == FLOOR)
				{
					putimage(134 + man.y * 61, 75 + (man.x + 1) * 61, &images[MAN]);
					arr[man.x + 1][man.y] = MAN;
					putimage(134 + man.y * 61, 75 + man.x * 61, &images[FLOOR]);
					arr[man.x][man.y] = FLOOR;
					putimage(134 + man.y * 61, 75 + (man.x + 2) * 61, &images[BOX]);
					arr[man.x + 2][man.y] = BOX;
					man.x += 1;
				}
				else if (Next(DOWN, man, 2) == DES)
				{
					putimage(134 + man.y * 61, 75 + (man.x + 1) * 61, &images[MAN]);
					arr[man.x + 1][man.y] = MAN;
					putimage(134 + man.y * 61, 75 + man.x * 61, &images[FLOOR]);
					arr[man.x][man.y] = FLOOR;
					putimage(134 + man.y * 61, 75 + (man.x + 2) * 61, &images[BOX]);
					arr[man.x + 2][man.y] = HIT;
					man.x += 1;
				}
			}
		}
		else if (kb == LEFT)					//a键左移
		{
			if (Next(LEFT, man) == FLOOR)
			{
				putimage(134 + (man.y - 1) * 61, 75 + (man.x) * 61, &images[MAN]);
				arr[man.x][man.y - 1] = MAN;
				putimage(134 + man.y * 61, 75 + man.x * 61, &images[FLOOR]);
				arr[man.x][man.y] = FLOOR;
				man.y -= 1;
			}
			else if (Next(LEFT, man) == BOX)
			{
				if (Next(LEFT, man, 2) == FLOOR)
				{
					putimage(134 + (man.y - 1) * 61, 75 + (man.x) * 61, &images[MAN]);
					arr[man.x][man.y - 1] = MAN;
					putimage(134 + man.y * 61, 75 + man.x * 61, &images[FLOOR]);
					arr[man.x][man.y] = FLOOR;
					putimage(134 + (man.y - 2) * 61, 75 + (man.x) * 61, &images[BOX]);
					arr[man.x][man.y - 2] = BOX;
					man.y -= 1;
				}
				else if (Next(LEFT, man, 2) == DES)
				{
					putimage(134 + (man.y - 1) * 61, 75 + (man.x) * 61, &images[MAN]);
					arr[man.x][man.y - 1] = MAN;
					putimage(134 + man.y * 61, 75 + man.x * 61, &images[FLOOR]);
					arr[man.x][man.y] = FLOOR;
					putimage(134 + (man.y - 2) * 61, 75 + (man.x) * 61, &images[BOX]);
					arr[man.x][man.y - 2] = HIT;
					man.y -= 1;
				}
			}
		}
		else if (kb == RIGHT)				  //d键右移
		{
			if (Next(RIGHT, man) == FLOOR)
			{
				putimage(134 + (man.y + 1) * 61, 75 + (man.x) * 61, &images[MAN]);
				arr[man.x][man.y + 1] = MAN;
				putimage(134 + man.y * 61, 75 + man.x * 61, &images[FLOOR]);
				arr[man.x][man.y] = FLOOR;
				man.y += 1;
			}
			else if (Next(RIGHT, man) == BOX)
			{
				if (Next(RIGHT, man, 2) == FLOOR)
				{
					putimage(134 + (man.y + 1) * 61, 75 + (man.x) * 61, &images[MAN]);
					arr[man.x][man.y + 1] = MAN;
					putimage(134 + man.y * 61, 75 + man.x * 61, &images[FLOOR]);
					arr[man.x][man.y] = FLOOR;
					putimage(134 + (man.y + 2) * 61, 75 + (man.x) * 61, &images[BOX]);
					arr[man.x][man.y + 2] = BOX;
					man.y += 1;
				}
				else if (Next(RIGHT, man, 2) == DES)
				{
					putimage(134 + (man.y + 1) * 61, 75 + (man.x) * 61, &images[MAN]);
					arr[man.x][man.y + 1] = MAN;
					putimage(134 + man.y * 61, 75 + man.x * 61, &images[FLOOR]);
					arr[man.x][man.y] = FLOOR;
					putimage(134 + (man.y + 2) * 61, 75 + (man.x) * 61, &images[BOX]);
					arr[man.x][man.y + 2] = HIT;
					man.y += 1;
				}
			}
		}

		if (isWin())
		{
			cout << "你赢了！！";
			break;
		}
	} while (emp);

	system("pause");
	closegraph();
	return 0;
}
