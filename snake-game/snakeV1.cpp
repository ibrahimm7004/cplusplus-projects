#include <iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include "base.cpp"
using namespace std;

class snakeV1 : public base{    // Derived class snakeV1 using public inheritance to inherit properties/methods of the class base 
	
	
	public:
		snakeV1(int a, int b) : base(a, b) {};   // Using base constructor in derived class
		// using base :: base;
		
		void arrayInitializer(int mainArray[][21], int &snakePosX, int &snakePosY)   // Pure virtual function defined
{
	int x = 11;
	int y =21;
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if ((i == 0) or (i == x-1))
			{
				mainArray[i][j] = 2;
			}
			else 
			{
				mainArray[i][0] = 1;
				mainArray[i][j] = 3;
				mainArray[i][y-1] = 1;
			} }	}
	
	mainArray[5][10] = 6;	
	snakePosX = 5;
	snakePosY = 10;	
}
		
		
};




