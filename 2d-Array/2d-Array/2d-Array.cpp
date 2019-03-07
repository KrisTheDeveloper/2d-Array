// 2d-Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>


using namespace std;

int hourglassSum(vector<vector<int>> arr) 
{	
	int currentSum = 0;
	int maxSum = -1000;

	int homeRow = 0;
	int homeCol = 0;
	
	for (int rowIter = homeRow; rowIter != arr.size(); )
	{
		for (int colIter = homeCol; colIter != (arr[0].size() + 1); colIter++)
		{
			if (homeCol > 3)
			{
				homeRow++;
				rowIter = homeRow;
				homeCol = 0;
				break;
			}			
			else if (rowIter == (homeRow + 1))
			{
				if (colIter == (homeCol + 1))
				{
					currentSum += arr[rowIter][colIter];
					rowIter++;
					break;
				}
				continue;				
			}
			else if (colIter < (homeCol + 3) && rowIter != (homeRow +1))
			{
				currentSum += arr[rowIter][colIter];
				continue;
			}
			
			if (!(rowIter < (homeRow + 2)))
			{
				homeCol++;
				rowIter = homeRow;
				if (currentSum > maxSum)
					maxSum = currentSum;
				
				currentSum = 0;				
				break;
			}
			
			rowIter++;
			break;			
		}		
	}
	return maxSum;
}

int main()
{
	/*
	vector<vector<int>> arr
	{
		{1,1,1,0,0,0}, 
		{0,1,0,0,0,0},
		{1,1,1,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0}
	};
	*/
	vector<vector<int>> arr
	{
		{-1,1,-1,0,0,0},
		{0,-1,0,0,0,0},
		{-1,-1,-1,0,0,0},
		{0,-9,2,-4,-4,0},
		{-7,0,0,-2,0,0},
		{0,0,-1,-2,-4,0}
	};

	
		
		
		
		
		
	
	int result = hourglassSum(arr);

}