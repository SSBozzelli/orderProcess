// FILE : orderProcess.h
// PROG : Andrew Bozzelli
// PURP : Class for a parallel array searching and sorting program. The arrays are searched using sequential search, binary search and bubble sort.

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class InventoryData
{
	private:
		int ptNum[200];
		double prices[200];
		int ptCount;
		

	public:
		InventoryData();
		void loadArray();
		void bubbleSort();
		int seqSearch(int);
		int binSearch(int);
		double getPrice(int);


};

InventoryData::InventoryData()
{
	ptCount = 0;
}

void InventoryData::loadArray()
{
	ifstream array;
	int ptIn = 0;
	double priceIn = 0.0;
	int ct = 0;

	array.open("masterInventory.dat");
	if (array.is_open())
	{
		array >> ptIn >> priceIn;

		while(!array.eof())
		{
			
			ptNum[ptCount]=ptIn;
			prices[ptCount]=priceIn;
			array >> ptIn >> priceIn;
			++ptCount;
		}
		array.close();
	}
	else
	{
		cout  <<  "File failed to open!";
	}
}

void InventoryData::bubbleSort()
{
	int last = ptCount - 1;
	int tempA = 0;
	double tempB =0.0;
	while(last>0)
	{
		int ind = 0;
		int swap = 0;
		while(ind<last)
		{
			if(ptNum[ind]>ptNum[ind+1])
			{
				tempA=ptNum[ind];
				tempB=prices[ind];
				prices[ind]=prices[ind+1];
				ptNum[ind]=ptNum[ind+1];
				prices[ind+1]=tempB;
				ptNum[ind+1]=tempA;
				swap = 1;
			}
			else
			{
				++ind;
			}
		}
		if(swap == 0)
		{
			last = 0;
		}
		else
		{
			last = last -1;
		}
	}

}

int InventoryData::seqSearch(int target)
{
	int ind=0;
	int found = -1;
	
	while(ind < ptCount)
	{
		
		if (target == ptNum[ind])
		{
			found = ind;
			ind = ptCount;
			
		}
		else
		{
			++ind;
			
		}
	}
	return found;
}

int InventoryData::binSearch(int target)
{
	int first = 0;
	int last = ptCount-1;
	int found = 0;
	int mid = 0.0;
	
	while(first<=last && found == 0)
	{
	
		mid = (first+last)/2;
		
		if (ptNum[mid] == target)
		{
			found = 1;
		}
		else if (ptNum[mid] < target)
		{
			first = mid +1;
		}
		else
		{
			last = mid - 1;
		}
	}
	if (found == 0)
	{
		mid = -1;
	}
	return mid;
}
double InventoryData::getPrice(int sub)
{
	return prices[sub];
}