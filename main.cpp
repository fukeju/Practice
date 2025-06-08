#include <iostream>
#include <string>
#include<Windows.h>
using namespace std;




void fun01(char* arr ,int lenth) 
{
	char temp[2] = { 0 };
	for (int i = 0; i < lenth/2; i+=2)
	{
		temp[0] = *(arr + i);
		temp[1] = *(arr + i + 1);

		*(arr + i) = *(arr + (lenth-3-i));
		*(arr + i + 1) = *(arr + (lenth - 2 - i));

		*(arr + (lenth - 3 - i)) = temp[0];
		*(arr + (lenth - 2 - i)) = temp[1];
	}
}
void fun02(int* arr ,int lenth)
{
	for (int i = 0; i < lenth-1; i++)
	{
		for (int j = 0; j < lenth-i-1; j++)
		{
			if (*(arr+j) > *(arr +j+ 1))
			{
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}
void fun03()
{
}
void fun04(const char* arr1, const char* arr2)
{
	char des[64] = {0};
	int pos = 0;

	for (int i = 0; i < strlen(arr1); i++)
	{
		*(des+pos) = *(arr1 + i);
		pos++;
	}
	for (int i = 0; i < strlen(arr2); i++)
	{
		*(des + pos) = *(arr2 + i);
		pos++;
	}
	cout << des<<endl;
}
void fun05()
{
}
void fun06()
{
}

void printArr(const int*arr,int lenth )
{
	for (int i = 0; i < lenth; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}
int srot(int a, int b)
{
	return a - b;
}
int main(void)
{
	char arr1[] = "爱上打架闹事的傻逼";
	fun01(arr1, sizeof(arr1) / sizeof(arr1[0]));
	cout << arr1<<endl;

	int arr2[] = {5,3,5,7,8,1,2,5};
	fun02(arr2, sizeof(arr2) / sizeof(arr2[0]));
	printArr(arr2, sizeof(arr2) / sizeof(arr2[0]));

	char arr4[] = "keju";
	char arr5[] = "大帅比"; 
	fun04(arr4, arr5);







}