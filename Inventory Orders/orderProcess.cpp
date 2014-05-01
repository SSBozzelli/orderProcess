//FILE : orderProcess.cpp
//PROG : Andrew Bozzelli
//PURP : Loads the arrays from the file "masterInventory.dat" and asks the user to input a parts number to search for the price. The results are sent to an output file.

#include <iostream>
using namespace std;
#include "orderProcess.h"

int main()
{
	InventoryData myArray;

	myArray.loadArray();
	myArray.bubbleSort();
	int part = 0;
	int choice = 0;
	int numParts = 0;
	double totalCost = 0;
	ofstream myFile;
	myFile.open("ordersProcessed.dat");
	cout << "Welcome to Parks Auto Parts!"<<endl;
	cout << "Please press 1 to search for a part or press 0 to quit."<<endl;
	cin >> choice;
	while(choice == 1)
	{
		cout<< "Please enter a part number."<<endl;
		cin >> part;
		cout << fixed << setprecision(2);
		if(myArray.binSearch(part) == -1)
		{
			cout<< "Binary search did not find part number "<<part<<endl;
		}
		else
		{
			cout<< "How many parts would you like to buy?"<<endl;
			cin>>numParts;
			totalCost=numParts*myArray.getPrice(myArray.binSearch(part));
			cout <<"Part#"<<setw(10)<<"Price"<<setw(15)<<"Qty Ordered"<<setw(10)<<"Total"<<endl;
			cout <<part<<setw(10)<<myArray.getPrice(myArray.binSearch(part))<<setw(10)<<numParts<<setw(15)<<totalCost<<endl;
			myFile << part <<" "<< numParts <<" "<< totalCost <<"\n" ;
		}
		cout << "\n";
		cout << "Please press 1 to search for a part or press 0 to quit."<<endl;
		cin >> choice;
	}
	myFile.close();
	system("pause");
	return 0;
}