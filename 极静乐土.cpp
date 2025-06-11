#include<iostream>
#include<graphics.h>
#include<Windows.h>
#include<string>

using namespace std;



int main(void) {


	initgraph(800, 450);
	wchar_t wname[256] = { 0 };
	wchar_t name[256] = {0};
	IMAGE *images = new IMAGE[148];
	cout << "加载中。。。。。" << endl;
	for(int i=0 ; i < 148 ; i++)
	{
		swprintf_s(name,L"images2\\_%04d_图层-%d.jpg",i,148-i);
		loadimage(images + i, name);

		
	}
	cout << "加载完成" << endl;

	for (int i = 0; i < 148; i++)
	{
		putimage(0, 0, &images[i]);
		Sleep(75);
	}
	delete[] images;
	system("pause");
	closegraph();
	return 0;

}