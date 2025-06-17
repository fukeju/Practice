#include<string>
#include<iostream>
#include<graphics.h>
#include<conio.h>

using namespace std;

#define BLOCK_COUNT 5
#define BLOCK_WIDTH 5
#define BLOCK_HEIGHT 5

#define WIDTH 20

#define STAR_X 130
#define STAR_Y 30

#define KEY_UP 72
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_DOWN 0
#define KEY_SPACE 32


int score;
int ranks;

int nextIndex = -1;
int nowIndex = -1;

int block[BLOCK_COUNT * 4][BLOCK_HEIGHT][BLOCK_WIDTH] = {
	{
		0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,1,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,1,0,0,
		0,1,1,1,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,1,0,0,0,
		0,1,1,0,0,
		0,1,0,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,1,1,1,0,
		0,0,1,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,0,1,0,
		0,0,1,1,0,
		0,0,0,1,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,1,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,0,1,0,
		0,0,1,1,0,
		0,0,1,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,1,1,0,0,
		0,0,1,1,0,
		0,0,0,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,0,1,0,
		0,0,1,1,0,
		0,0,1,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,0,0,0,
		0,1,1,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,1,0,0,0,
		0,1,0,0,0,
		0,1,1,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,1,1,1,0,
		0,1,0,0,0,
		0,0,0,0,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,1,1,0,
		0,0,0,1,0,
		0,0,0,1,0,
		0,0,0,0,0,
	},
	{
		0,0,0,0,0,
		0,0,0,0,0,
		0,0,0,1,0,
		0,1,1,1,0,
		0,0,0,0,0,
	},
};

int vists[30][15] = { 0 };

void welcome()
{
	initgraph(550, 660);
	HWND window = GetHWnd();
	SetWindowText(window, "俄罗斯方块");

	setfont(40, 0, _T("微软雅黑"));
	setcolor(WHITE);
	outtextxy(205, 200, "俄罗斯方块");

	setfont(22, 0, _T("楷体"));
	setcolor(WHITE);
	outtextxy(175, 300, "生活  从俄罗斯方块开始");

	Sleep(1500);
}

void initGameScene()
{
	char str[18] = { 0 };
	cleardevice();
	rectangle(27, 27, 336, 635);
	rectangle(29, 29, 334, 633);


	rectangle(370, 50, 515, 195);

	setfont(24, 0, "楷体");
	settextcolor(WHITE);
	outtextxy(405, 215, "下一个");

	settextcolor(RED);
	outtextxy(405, 280, "得分：");
	sprintf_s(str, "%d", score);
	outtextxy(425, 310, str);

	settextcolor(RED);
	outtextxy(405, 375, "等级：");
	sprintf_s(str, "%d", ranks);
	outtextxy(425, 405, str);

	settextcolor(WHITE);
	outtextxy(390, 475, "操作说明");
	outtextxy(390, 500, "↑旋转");
	outtextxy(390, 525, "↓下降");
	outtextxy(390, 550, "←左移");
	outtextxy(390, 575, "→右移");
	outtextxy(390, 600, "空格 暂停");
}

void clearBlock()
{
	settextcolor(BLACK);
	setfont(23, 0, "楷体");
	for (int i = 0; i < BLOCK_HEIGHT; i++)
	{
		for (int j = 0; j < BLOCK_WIDTH; j++)
		{
			outtextxy(391 + j * WIDTH, 71 + i * WIDTH, "■");
		}
	}
}

void drawBlock(int X,int Y)
{
	settextcolor(WHITE);
	
	for (int i = 0; i < BLOCK_HEIGHT; i++)
	{
		for (int j = 0; j < BLOCK_WIDTH; j++)
		{
			if (block[nextIndex*4][i][j])
			{
				outtextxy(X + j * WIDTH, Y + i * WIDTH, "■");
			}
		}
	}
}

void nextBlock()
{
	clearBlock();

	srand(time(NULL));
	nextIndex = rand() % 5;
	//nextIndex = 0;

	drawBlock(391,71);
}

void isGameOver()
{

}

void moveBlock()
{
	isGameOver();
	while (1)
	{
		if (kbhit())
		{
			int key = getch();
			if (key == KEY_SPACE)
			{
				getch();
			}
		}
		
	}

}

void newBlock()
{
	nowIndex = nextIndex;
	drawBlock(STAR_X, STAR_Y);
	Sleep(100);

	nextBlock();
	moveBlock();


}

int main()
{
	welcome();

	initGameScene();
	nextBlock();
	Sleep(500);

	while(1)
	{
		newBlock();




	}

	system("pause");
	closegraph();
}