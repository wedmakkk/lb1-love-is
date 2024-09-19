﻿#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n, m;
	int max = 100, min = -100;
	while (1)
	{
		printf("Введите колличество строк (строки < столбцы):\n");
		scanf_s("%d", &n);
		printf("Введите колличество столбцов:\n");
		scanf_s("%d", &m);
		if (n < m)
		{
			break;
		}
	}
	int** mas = (int**)malloc(sizeof(int*) * n);

	for (int i = 0;i < n;i++)
	{
		mas[i] = (int*)malloc(sizeof(int) * m);
	}

	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			mas[i][j] = min + rand() % (max - min + 1);
			printf("%d ", mas[i][j]);
		}
		printf("\n");
	}

	int sum = 0, num, nums;
	while (1)
	{
		printf("Где посчитать сумму?\n1-столбцы\n2-строки\n");
		scanf_s("%d", &num);
		if (num == 1)
		{
			printf("Введите номер столбца в котором хотите посчитать сумму: ");
			scanf_s("%d", &nums);
			if (nums > m or nums < 0)
			{
				printf("Ошибка");
			}
			else
			{
				break;
			}
		}
		if (num == 2)
		{
			printf("Введите номер строки в которой хотите посчитать сумму: ");
			scanf_s("%d", &nums);
			if (nums > n or nums < 0)
			{
				printf("Ошибка");
			}
			else
			{
				break;
			}
		}
	}
	if (num == 1)
	{
		int j = 0;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				if (j == nums - 1)
				{
					sum += mas[i][j];
				}
			}
		}
	}
	if (num == 2)
	{
		int j = 0;
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				if (i == nums - 1)
				{
					sum += mas[i][j];
				}
			}
		}
	}
	int sumd = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			if (m % 2 == 0)
			{
				if (j >= m / 2)
				{
					sumd += mas[i][j];
				}
			}
			if (m % 2 != 0)
			{
				if (j > m / 2)
				{
					sumd += mas[i][j];
				}
			}
		}
	}
	printf("Сумма: %d\n", sum);
	printf("Cумма чисел право половины: %d", sumd);
	return 0;

}
