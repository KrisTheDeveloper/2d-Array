// 2d-Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int hourglassSum(vector<vector<int>> arr) 
{
	vector<int> sum(4);
	
	int endSumIter = 0;
	for (vector<vector<int>>::iterator rowIter = arr.begin(); rowIter != arr.end(); rowIter++)
	{
		int currentLocation = 0;
		for(vector<int>::iterator colIter = rowIter->begin(); colIter != rowIter->end(); colIter++)
		{	
			//3on - 4off - 1on - 4off - 3on
			int currentNum = *colIter;	

			//while 

			//going to simplify this logic
			switch (currentLocation)
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

			currentLocation += 1;
			
		}
	}

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
