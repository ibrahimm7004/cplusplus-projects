#include <iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
#include "snakeV2.cpp"
using namespace std;

class snakeV3 : public base{
	
	
	public:
		snakeV3(int a, int b) : base(a, b) {};
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
				mainArray[i][y-1] = 1; 
				mainArray[i][6] = 7;
				mainArray[i][14] = 7;
				}
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



void monster(bool &eG)   // Function in case snake encounters a monster. Responsible for the assignment exitGame = true
{
	eG = true;
}

void movement(int mainArray[][21], int &posX, int &posY, bool &exitGame)   /* Virtual function re-defined since the functioning of movement is 
																		      different than in the base and previous derived classes */
{
	int userInput;
	bool cantMove, flagUp, flagDown, flagLeft, flagRight;  //Declaration of a few boolean type variables
	flagUp = false, flagDown = false, flagLeft = false, flagRight = false, cantMove = false;  //Initialization of the boolean variables decalred above
	
	userInput = getch();     /*Pre-defined function which basically pauses/holds the console screen until the user inputs something. It 
		                         takes the character the user has entered and returns an integer(the ascii calue of that character). Uses the
								 library conio.h */
								 
	system("CLS");         //The screen is cleared each time before taking input, so that only one maze is dislpayed on the console screen

        if (userInput == 27)
        exitGame = true;
        
		else if (userInput == 75 or userInput == 97)    //CASE LEFT/A
		{
		    if (mainArray[posX][posY-1] == 1 or mainArray[posX][posY-1] == 2)
		    cantMove = true;
		    else if (mainArray[posX][posY-1] == 7)    // If snake encounters monster, kill snake
		    {
		    monster(exitGame);
		    mainArray[posX][posY] = 3;
		}
		    else
			{
				flagLeft = true;
			mainArray[posX][posY] = 3;
			posY--;
			} }
			
		else if (userInput == 77 or userInput == 100)   //CASE RIGHT/D
		{
			if (mainArray[posX][posY+1] == 1 or mainArray[posX][posY+1] == 2)
		    cantMove = true;
		    else if (mainArray[posX][posY+1] == 7)
		    {
		    monster(exitGame);
		    mainArray[posX][posY] = 3;
		}
		    else
			{
				flagRight =  true;
			mainArray[posX][posY] = 3;
			posY++;
			}
        }
					
		else if (userInput == 72 or userInput == 119)   //CASE UP/W
		{		
			if ((mainArray[posX-1][posY] == 1) or (mainArray[posX-1][posY] == 2))
		    cantMove = true;
		    else if (mainArray[posX-1][posY] == 7)
		    {
		    monster(exitGame);
		    mainArray[posX][posY] = 3;
		}
		    else
			{
				flagUp =  true;
			mainArray[posX][posY] = 3;
			posX--;
			}
        }
					
		else if (userInput == 80 or userInput == 115)   //CASE DOWN/S
		{	
		if (mainArray[posX+1][posY] == 1 or mainArray[posX+1][posY] == 2)
		    cantMove = true;
		    else if (mainArray[posX+1][posY] == 7)
		    {
		    monster(exitGame);
		    mainArray[posX][posY] = 3;
		}
		    else
			{
				flagDown =  true;
			mainArray[posX][posY] = 3;
			posX++;
			}
		}
		
		if (flagLeft == true)
	mainArray[posX][posY] = 8;
	else if (flagRight == true)
	mainArray[posX][posY] = 4;
	else if (flagUp == true)
	mainArray[posX][posY] = 6;
	else if (flagDown == true)
	mainArray[posX][posY] = 10;	
        
}

		
		
};


int main()
{   
    int Score = 0;
	const int x = 11, y = 21;   
	int mainArray[x][y] = {0};   // Declaration of a 2-D array and initialisation of all its elements to 0
	
	srand(time(0));                        /*Using a function within a function here- 'srand' uses the pre defined funtion 'time' as a paramter.
                                       And the funtion 'time' uses the value 0 as a parameter. The real time value of the actual time is 
									   being used here, therefore as time changes constantly, so do the generated values*/
	
	int snakePosX, snakePosY, userInput;
	bool exitGame = false;    // When TRUE, game will be exited
	
	base *bptr;    
	snakeV1 obj1(0,0);    
	snakeV2 obj2(0,0);
	snakeV3 obj3(0,0);
	
	cout << "Choose the version you want to play: \n(1) Version 1\n(2) Version 2\n(3) Version 3\n";
	cin >> userInput;
	system("CLS");
	
	switch (userInput)
	{
		case 1:
	
	bptr = &obj1;
	obj1.arrayInitializer(mainArray, snakePosX, snakePosY);		// Function call to initialize array
		
	obj1.draw(x, y, mainArray);
	cout<<"\n\n\t\t\t\tUse the arrow keys or awsd keys to play.\n\t\t\t\tPress ESC to quit. "<<endl;   //Message displayed once before the game starts
	
	while (obj1.getScore() < 3 && exitGame == false)
	{
	bptr->movement(mainArray, snakePosX, snakePosY, exitGame);  //Functiion call- This function handles everything related to user input
	if (obj1.foodChecker(mainArray) == false)
	{
	obj1.foodGenerator(mainArray);
	if (obj1.getCount() > 0)
	obj1.incrementScore();
}
    obj1.draw(x, y, mainArray);
    obj1.incrementCount();
}
    break;
    
	  case 2:
	
	bptr = &obj2;
	obj2.arrayInitializer(mainArray, snakePosX, snakePosY);		// Function call to initialize array
		
	obj2.draw(x, y, mainArray);
	cout<<"\n\n\t\t\t\tUse the arrow keys or awsd keys to play.\n\t\t\t\tPress ESC to quit. "<<endl;   //Message displayed once before the game starts
	
	while (obj2.getScore() < 3 && exitGame == false)
	{
	bptr->movement(mainArray, snakePosX, snakePosY, exitGame);  //Functiion call- This function handles everything related to user input
	if (obj2.foodChecker(mainArray) == false)
	{
	obj2.foodGenerator(mainArray);
	if (obj2.getCount() > 0)
	obj2.incrementScore();
}
    obj2.draw(x, y, mainArray);
    obj2.incrementCount();
}
    break;
		   
case 3:
	
	bptr = &obj3;
	obj3.arrayInitializer(mainArray, snakePosX, snakePosY);		// Function call to initialize array
		
	obj3.draw(x, y, mainArray);
	cout<<"\n\n\t\t\t\tUse the arrow keys or awsd keys to play.\n\t\t\t\tPress ESC to quit. "<<endl;   //Message displayed once before the game starts
	
	while (obj2.getScore() < 3 && exitGame == false)
	{
	bptr->movement(mainArray, snakePosX, snakePosY, exitGame);  //Function call- This function handles everything related to user input
	if (obj3.foodChecker(mainArray) == false)
	{
	obj3.foodGenerator(mainArray);
	if (obj3.getCount() > 0)
	obj3.incrementScore();
}
    obj3.draw(x, y, mainArray);
    obj3.incrementCount();
}
    break;
    
       default:
       	if (userInput != 1 || userInput != 2)
       	{
       		cout << "Enter a valid option(1,2 or 3): \n";
       		cin >> userInput;
		   } 		   
}

if (exitGame ==  false)
{
	system("CLS");
	cout << "YOU WON! \n\n";
}
	
	return 0;
}