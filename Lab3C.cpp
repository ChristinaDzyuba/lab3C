// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "stdio.h"
#include "math.h"

void selectionSort(int outArray[5][5]);//Функция сортировки вставской
void printArray(int outArray[5][5]);	//Функция печати массива, шоб не писать один и тот же код много раз
void sumColumns(int outArray[5][5]);		//Функция, которая считает сумму элементов по условию и находит их среднее геометрическое


int main(void)
{
									//место под переменную п
	int  outArray[5][5] = {			//Внешний массив(обрабатываемый массив)
	44, -2, -5,  38, -91,
	 2,  0,  6,   3,  22,
	13,  1, -4,   90,  11,
	-3, -6, -98, -23, -24,
	10, 34,  32,  31,  69
	};
	/*
	int  outArray[5][5], n = 5;
	for (int i = 0; i < n; i++)				//это код для ввода массива вручную с клавы
	{
		for (int j = 0; j < n; j++)
		{
			printf("a[%d][%d] =", i + 1, j + 1);
			scanf_s("%d", &outArray[i][j]);
		}
	}
	*/
	printf("old array\n");			
	printArray(outArray);
	printf("new array\n");					//вызовы функций
	selectionSort(outArray);
	printArray(outArray);
	sumColumns(outArray);
}

void selectionSort(int outArray[5][5])		//тело функции сортировки
{	
	
	for (int i = 0; i < 5; i++)
	{	
		
		for (int j = 0; j < 5; j++)
		{
			int min = j;
			for (int k = j + 1; k < 5; k++)
			{
				if (outArray[i][k] < outArray[i][min]) min = k;
			}
			if (min != j)
			{
				int c = outArray[i][min];
				outArray[i][min] = outArray[i][j];
				outArray[i][j] = c;
			}
		}
	}
}
void printArray(int outArray[5][5])
{
	for (int i = 0; i < 5; i++)					//Функция вывода массива в консоль
	{
		for (int j = 0; j < 5; j++)
			printf("%5d", outArray[i][j]);
		printf("\n");
	}
}
void sumColumns(int outArray[5][5])		// функция суммирования элементов над вспомогательной
{										//диагональю и среднего геометричееского сумм
	int  geoSum = 1, k = 3;
	for (int j = 0; j < 4; j++)	
	{	
		int count = 0;
		for (int i = k; i >= 0 ; i--)
		{	
			count += outArray[i][j];
		}
		printf("%5d", count);
		printf("\n");
		geoSum *= count;
		k--;
	}
	//printf("%i\n", geoSum);
	
	printf("%lf", pow(geoSum, 1.0 / 4.0));
	printf("\n");
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
