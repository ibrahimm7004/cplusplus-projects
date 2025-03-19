#include <iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include "snakeV1.cpp"
using namespace std;

class snakeV2 : public base{
	
	
	public:
		snakeV2(int a, int b) : base(a, b) {};
		// using base :: base;
		
		void arrayInitializer(int mainArray[][21], int &snakePosX, int &snakePosY)
{
	int x = 11;
	int y =21;
   
	for (int i = 0; i < x; i++)
	 {
		for (int j = 0; j < y; j++)
		{
			if (i == 0) 
			{
				mainArray[i][j] = 2;
			}
			
			else if ((i == 1) or (i == 2) or (i == 8) or (i == 9))
			{
				if ((j == 5) or (j == 7) or (j == 9) or (j == 11) or (j == 13) or (j == 15))
				mainArray[i][j] = 1; 
				else
			{
				mainArray[i][0] = 1;
				mainArray[i][j] = 3;
				mainArray[i][y-1] = 1;
			}
			}
			
			else if (i == x-1)    // ROW 10
			{
				mainArray[i][0] = 1;
				mainArray[i][j] = 2;
				mainArray[i][y-1] = 1;
			}
			
			else if (i == 4 or i == 6)
			{
				if ((j == 1) or (j == 2) or (j == 3) or (j == 4) or (j == 16) or (j == 17) or (j == 18) or (j == 19))
				 { mainArray[i][j] = 2; }
				else
				{
				mainArray[i][0] = 1;
				mainArray[i][j] = 3;
				mainArray[i][y-1] = 1; }
				mainArray[6][10] = 2;
				mainArray[6][9] = 1;
				mainArray[6][11] = 1;
			}
			
			else if (i == 5)
			{
				if ((j == 9) or (j == 11))
				 { mainArray[i][j] = 1; }
				else
				{
				mainArray[i][0] = 1;
				mainArray[i][j] = 3;
				mainArray[i][y-1] = 1; }
			}
			
			else if (i == 3)
			{
			    mainArray[i][10] = 2; 
				mainArray[i][0] = 1;
				mainArray[i][j] = 3;
				mainArray[i][y-1] = 1;
			}
			
			else
			
			{
				mainArray[i][0] = 1;
				mainArray[i][j] = 3;
				mainArray[i][y-1] = 1;
			} } }
	
	mainArray[6][10] = 6;	
	snakePosX = 6;
	snakePosY = 10;	
}


		
		
};


