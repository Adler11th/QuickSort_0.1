// QuikSort0.1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

constexpr int SIZE = 10000;//Const size of the array

int QuickSort(int *Array, int start, int end)//Recursive function that sorts array
{
	int Pivot = start;//Variable that will hold pivot position before recursive calls and tracks indexes					
	int Temp = 0;	//Variable used for swaping array members
	if (start < end)//Exit condition
	{
		for (int Index = start; Index < end; Index++)
		{
			if (Array[Index] <= Array[end])
			{
				Temp = Array[Pivot];
				Array[Pivot] = Array[Index];
				Array[Index] = Temp;
				Pivot++;
			}
		}
		Temp = Array[end];
		Array[end] = Array[Pivot];
		Array[Pivot] = Temp;
	QuickSort(Array, start, --Pivot);//Calling racursion for left of the pivot
	QuickSort(Array, ++Pivot, end);//Calling recursion for right of the pivot
	}
 return 0;
}

int GenerateArray(int *Array)//Put random values in Array 
{
	srand(time(NULL));
	for (int Index = 0; Index < SIZE; Index++)
	{
		Array[Index] = rand() % SIZE;
	}
	return 0;
}

void PrintArray(int *Array)
{
	for (int Index = 0; Index < SIZE; Index++)
	{
		std::cout << Array[Index] << " ";
		if (Index % 20 == 0)
		{
			std::cout <<"\n";
		}
	}
	std::cout << std::endl;
}


int main()
{
	int Array[SIZE];
	GenerateArray(Array);
	QuickSort(Array, 0, SIZE-1);
	PrintArray(Array);
	std::cin.get();
    return 0;
}

