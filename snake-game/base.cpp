#include <iostream>
#include<conio.h>
#include<windows.h>
#include<ctime>
using namespace std;


class base{
	protected:     // Protected scope so the attributes can be accessed by derived classes
		int score;     //Stores the score (+1 each time the snake eats 1 item)
        int count; 
	    int mainArray[11][21];
		
	public:
	    base(int score, int count)    // Parametrized constructor 
	    {
	    	this->score = score;     // Using this pointer to set values of score and count
	    	this->count = count;
		}
		
		int getScore()    
		{
			return score;
		}
		
		void incrementScore()
		{
			score++;
		}
		
		int getCount()
		{
			return count;
		}
		
		void incrementCount()
		{
			count++;
		}
	    
	    
	    virtual void arrayInitializer(int mainArray[][21], int &snakePosX, int &snakePosY) = 0;    // Pure virtual function since array(design of the maze)
																								  // will be redefined in each version
	    
	    
	    void draw(int x, int y, int mainArray[][21])    // This function draws the maze by using nested IF statements and comparisons

/*We decided on the following assignment of values to make 
our work easier, and it will be used throughout the program:

FOOD (.) = 0
WALLS (|) = 1
FLOOR (_) = 2
SPACE (' ') = 3
SNAKE (>) = 4 
MONSTER (O) = 7   */

{
	
	
	int loopCounterRows = x;
	int loopCounterColumns = y;
	
	cout<<"SCORE: "<<score<<endl;
	  
	for (loopCounterRows = 0; loopCounterRows <x; loopCounterRows++)
	{
		for (loopCounterColumns = 0; loopCounterColumns <y; loopCounterColumns++)
		{
			if (mainArray[loopCounterRows][loopCounterColumns] == 0)
			cout<<".";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 1)
			cout<<"|";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 2)
			cout<<"_";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 3)
			cout<<" ";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 4)
			cout<<">";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 5)
			cout<<"-";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 6)
			cout<<"^";	
			else if (mainArray[loopCounterRows][loopCounterColumns] == 7)
			cout<<"O";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 8)
			cout<<"<";	
			else if (mainArray[loopCounterRows][loopCounterColumns] == 10)
			cout<<"v";
		}	
	
	cout<<endl;
}
	
}
	
		
		virtual void movement(int mainArray[][21], int &posX, int &posY, bool &exitGame)     // Controls the user input and movement of the snake
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
		    else
			{
				flagDown =  true;
			mainArray[posX][posY] = 3;
			posX++;
			}
		}
		
		if (flagLeft == true)    // Some comparisons to check which direction our snake will move in based on the user input
	mainArray[posX][posY] = 8;
	else if (flagRight == true)
	mainArray[posX][posY] = 4;
	else if (flagUp == true)
	mainArray[posX][posY] = 6;
	else if (flagDown == true)
	mainArray[posX][posY] = 10;
        
}

        
        void generator(int &x, int &y)    // Generates random a and y values being used as coordinates for the next food item in the maze
{
	x = rand() % 9 + 1;   // Generates a random value between 1 and 9
    y = rand() % 19 + 1;  // Generates a random value between 1 and 19
}

bool foodChecker(int mainArray[][21])    // Predicate function which checks whether food already exists in the maze
{
	bool foodExists = false;
	
	for (int rowsCounter = 1; rowsCounter < 11; rowsCounter++)
    {
    	for (int columnsCounter = 1; columnsCounter < 21; columnsCounter++)
    	{
    		if (mainArray[rowsCounter][columnsCounter] == 0)
    		foodExists = true;
		}
	}
	
	return foodExists;
}

void foodGenerator(int mainArray[][21])   /* Given that the snake has eaten the food, a new food item must be placed in the maze. This function calls the 
										     appropriate functions to generate a random location for the new item, and place it in the maze   */
{
	int x, y;
	generator(x, y);
	
	if (mainArray[x][y] == 3)
	mainArray[x][y] = 0;
	else
	{
		while (!(mainArray[x][y] == 3))   // While the generated location is non-empty, generate it again (i.e. call generator function again)
		generator(x, y);
		mainArray[x][y] = 0;
	 } 
	
}

 
		
};







