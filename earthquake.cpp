#include<iostream>
using namespace std;
#include<string>
#include<fstream>

//earthquake
#define LONG 5
#define SHORT 2
#define TIME 0.02
#define THTRSHOLD 1.5


void printArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		cout << *(arr + i) << " ";

	cout << endl;
}

double powerLong(int* arr)
{
	double powerLong = 0;
	for (int i = 0; i < LONG - 1; i++)
	{
		powerLong += (*(arr + i)) * (*(arr + i));
	}
	return powerLong / LONG;
}

double powerShort(int* arr)
{
	double powerShort = 0;
	for (int i = LONG - 1; i >= LONG - SHORT; i--)
	{
		powerShort += (*(arr + i)) * (*(arr + i));
	}
	return powerShort / SHORT;
}

int main()
{
	int num;
	int j = 0;
	ifstream ifs;
	int* earthquakeArr = NULL;
	double longPower, shortPower, threshold, time=0;
	ifs.open("earthquake.txt");
	if (ifs.is_open())
	{
		ifs >> num;
		cout << "�ļ��Ѵ򿪣�����" << num << "������" << endl;
		earthquakeArr = new int[num];
		for (int i = 0; i < num; i++)
		{
			ifs >> *(earthquakeArr + i);
		}
		printArr(earthquakeArr, num);


		int Window[LONG] = { 0 };
	/*	for (int i = 0; i < LONG; i++)
		{
			*(Window + i) = *(earthquakeArr + i);	//��ʼ������
		}
		*/
		for (int i=LONG-1;i<num;i++)
		{
			
			for (int i = 0; i < LONG; i++)
			{
				*(Window + i) = *(earthquakeArr+i+j);	//��ʼ������
			}
			j++;
			longPower = powerLong(Window);
			shortPower = powerShort(Window);
			threshold = longPower > shortPower ? longPower / shortPower : shortPower / longPower;
			if (threshold > THTRSHOLD)
			{
				time += TIME;
			}
		}
		cout << "Ԥ�Ƶ���ʱ��Ϊ��" << time << "s";
	}
	else
	{
		cout << "�ļ���ʧ��" << endl;
	}
}