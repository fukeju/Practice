#include<iostream>
#include<Windows.h>
#include<fstream>
#include<graphics.h>

using namespace std;

int main()
{

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

	IMAGE images[5] = { 0 };

	initgraph(1000, 700);

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
			switch (arr[i][j])
			{
			case 0:
				putimage(134 + j * 61, 75 + i * 61, &images[0]);
				break;
			case 1:
				putimage(134 + j * 61, 75 + i * 61, &images[1]);
				break;
			case 2:
				putimage(134 + j * 61, 75 + i * 61, &images[2]);
				break;
			case 3:
				putimage(134 + j * 61, 75 + i * 61, &images[3]);
				break;
			case 4:
				putimage(134 + j * 61, 75 + i * 61, &images[4]);
				break;
			}
			
		}
	}

	system("pause");
	closegraph();
}