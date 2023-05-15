// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <iostream>

void ShellSort(int n, int mass[])
{
    int i, j, step;
    int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}

int main()
{
    int N;
    printf("Input N: ");
    scanf_s("%d", &N);

    int* mass;
    mass = (int*)malloc(N * sizeof(int));

    printf("Input the array elements:\n");
    for (int i = 0; i < N; i++)
        scanf_s("%d", &mass[i]);

    printf("Unsorted array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", mass[i]);
    printf("\n");
    ShellSort(N, mass);


    printf("Sorted array:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", mass[i]);
    printf("\n");

    free(mass);
    _getch();
    return 0;
}

