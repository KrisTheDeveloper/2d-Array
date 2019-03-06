// 2d-Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>


using namespace std;

int hourglassSum(vector<vector<int>> arr) 
{
	
	
	int currentSum = 0;
	int maxSum = 0;

	int homeRow = 0;
	int homeCol = 0;
	
	//Won't work this way. Will need to change both forloops to standard int::iterators with arr.size(row) or arr.size[0](column) being the max.
	//will then need to keep track of 0 location of both row and column and capture 1 hour glass at a time only overwriting sum if th current hourglass is greater than the previous one
	//there will be 16 hourglass checks but numbers will be iterated more than once. Around twice for most of the numbers but this will be the best way without an algorithm. 
	//this process is better. I need to mess with it though to rid defects.
	for (int rowIter = homeRow; rowIter != arr.size(); )
	{
		
		for (int colIter = homeCol; colIter != arr[0].size(); colIter++)
		{
			if (!(homeCol < (arr[0].size() - 2)))
			{
				homeRow++;
				rowIter = homeRow;
				homeCol = 0;
				break;
			}
			else if (!(rowIter < (homeRow + 3)))
			{
				homeCol++;
				rowIter = homeRow;
				break;
			}
			else if (rowIter == (homeRow + 1))
			{
				if (colIter == (homeCol + 1))
				{
					cout << arr[rowIter][colIter] << endl;
					currentSum += arr[rowIter][colIter];
					homeRow++;
					rowIter = homeRow;
					break;
				}
				continue;				
			}
			else if (colIter < (homeCol + 3) && rowIter != (homeRow +1))
			{
				cout << arr[rowIter][colIter] << endl;
				currentSum += arr[rowIter][colIter];
				continue;
			}

			//if (rowIter != (homeRow + 1))
			//{				
				rowIter++;
			//}

			
		}
		
	}
	cout << "first sum = " << currentSum;
	/*
	for (vector<vector<int>>::iterator rowIter = arr.begin(); rowIter != arr.end(); rowIter++)
	{		
		/*if (rowIndex % 2 > 0)
		{
			cout << "Odd row";
			flagSkipRow = true;
		}
		else
			flagSkipRow = false;
		
		int columnIndex = 0;
		for(vector<int>::iterator colIter = rowIter->begin(); colIter != rowIter->end(); colIter++)
		{	
			//3on - 4off - 1on - 4off - 3on
			int currentNum = *colIter;	

			

			//going to simplify this logic
			switch (columnIndex)
			{
				case 0:
					sum[0] += currentNum;
					break;
				case 1:
					sum[0] += currentNum;
					sum[1] += currentNum;
					break;
				case 2:
					sum[0] += currentNum;
					sum[1] += currentNum;
					sum[2] += currentNum;
					break;
				case 3:
					sum[1] += currentNum;
					sum[2] += currentNum;
					sum[3] += currentNum;
					break;
				case 4:
					sum[2] += currentNum;
					sum[3] += currentNum;
					break;
				case 5:
					sum[3] += currentNum;
			}

			columnIndex++;
			
		}
		rowIndex++;
	}
	*/
	return 0;
}

int main()
{
	vector<vector<int>> arr
	{
		{1,1,1,0,0,0}, 
		{0,1,0,0,0,0},
		{1,1,1,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0},
		{0,0,0,0,0,0}
	};
	
	int result = hourglassSum(arr);
	//cout << result << "\n";

    //std::cout << "Hello World!\n"; 
}