#include<iostream>      //preprocessor directive, tells preprocessor to include the iostream(input/output stream) header file
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<ctime>
#include <iomanip>
#include <unistd.h>
#include<fstream>
using namespace std;   //Tells the computer the code for cin/cout functionalities, and in which namespace they're defined

//GLOBAL VARIABLE:
int lives = 3;        //Stores the number of lives pacman has at any point in the game. Initially, this number is set to 3
int countMM = 0;
int hours = 0;
int minutes = 0;
int seconds = 0;
int timeForWin = 0;

/*We decided on the following assignment of values to make 
our work easier, and it will be used throughout the program:

FOOD (.) = 0
WALLS (|) = 1
FLOOR (_) = 2
POWER ($) = 3
SPACE (" ") = 4
KILLING MONSTER(O) = 5
PACMAN(^) = 6
EATABLE MONSTER(o) = 7  


--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void drawMaze(int mainArray[13][13])
{   
    int loopCounterRows, loopCounterColumns;
    
    cout<<"LIVES: "<<lives<<endl;
	
	for (loopCounterRows = 0; loopCounterRows <=12; loopCounterRows++)
	{
		for (loopCounterColumns = 0; loopCounterColumns <=12; loopCounterColumns++)
		{
			if (mainArray[loopCounterRows][loopCounterColumns] == 0)
			cout<<".";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 1)
			cout<<"|";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 2)
			cout<<"_";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 3)
			cout<<"$";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 4 or mainArray[loopCounterRows][loopCounterColumns] == 11)
			cout<<" ";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 5)
			cout<<"O";	
			else if (mainArray[loopCounterRows][loopCounterColumns] == 6)
			cout<<"^";	
			else if (mainArray[loopCounterRows][loopCounterColumns] == 7)
			cout<<"o";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 8)
			cout<<"<";	
			else if (mainArray[loopCounterRows][loopCounterColumns] == 9)
			cout<<">";
			else if (mainArray[loopCounterRows][loopCounterColumns] == 10)
			cout<<"v";
		}	
	
	cout<<endl;

    }
}

//------------------------------------------------------------------------------------------------------------------------------------------------------

void monsterEatsPacman(int mainArray[][13], int &positionX, int &positionY)    //IN CASE PACMAN ENCOUNTERS KILLING MONSTER (O)
{
	positionX = 11,	positionY =1;          //Pacman dies, positioned back at start position
    lives--;                              //Decrement the value of the variable 'lives' since pacman has lost a life
    mainArray[positionX][positionY] = 6;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------

void powerPill(int mainArray[][13], int &positionX, int &positionY)    //IN CASE PACMAN EATS AN ENERGY ITEM ($)
{
 int innerLoopCounter, loopCounter;                       //Declaration of 2 integer type variables
 
 
 
 for (loopCounter = 1; loopCounter < 13; loopCounter++)   //Outer FOR loop for the rows
 {
 	for (innerLoopCounter = 1; innerLoopCounter < 13; innerLoopCounter++)  //Inner FOR loop for the columns
 {
 	if (mainArray[loopCounter][innerLoopCounter] == 5)  //Conditional statement, reponsible for comparison of each array element with the value 5
 	mainArray[loopCounter][innerLoopCounter] = 7;   //Change all killing monsters to eatable monsters (Change values from 5 to 7)
 }
}
}

//------------------------------------------------------------------------------------------------------------------------------------------------------

void pacmanEatsMonster(int mainArray[][13])  //IN CASE PACMAN ENCOUNTERS AN EATABLE MONSTER (o)
{
	mainArray[6][5] = 5;	
}

//------------------------------------------------------------------------------------------------------------------------------------------------------

void monstersMovement(int mainArray[][13], int &monstPosX, int &monstPosY, int &pacmanPosX, int &pacmanPosY)  //CONTROLS AND RANDOMIZES THE MOVEMENT OF THE MONSTERS

{
	int tempVal;
	
	//INITIAL MOVEMENT (So the monsters don't stay in the cage for too long) //Monster 1 position is (6,5) right now
	
	if (countMM == 0)   //Will change Monster 1 position from (6,5) to (5,5)
		{
			mainArray[monstPosX][monstPosY] = 4;
			monstPosX--;
			countMM++;
		}
		
		else if (countMM == 1)   //Will change Monster 1 position from (5,5) to (5,6)
		{
			mainArray[monstPosX][monstPosY] = 4;
			monstPosY++;
			countMM++;
		}
		
		else if (countMM == 2)   //Will change Monster 1 position from (5,6) to (4,6)
		{
			mainArray[monstPosX][monstPosY] = 4;
			monstPosX--;
			countMM++;
		}
		
		else if (countMM == 3)   //Will change Monster 1 position from (4,6) to (3,6)
		{
			mainArray[monstPosX][monstPosY] = 4;
			monstPosX--;
			countMM++;
		}
		
		if (!(mainArray[monstPosX+1][monstPosY] == 1 or mainArray[monstPosX+1][monstPosY] == 2))
		{
			int n;
			n = (rand() % 3 +1);
			
		}
		
	//NORMAL MOVEMENT- AFTER THE FIRST FEW MONSTER PLACEMENTS, THIS CODE WILL RUN	
	else
	{
	int arr[4];
	
	if (mainArray[monstPosX][monstPosY-1] == 1 or mainArray[monstPosX][monstPosY-1] == 2 or mainArray[monstPosX][monstPosY-1] == 11)   //MONSTER MOVES LEFT
		    arr[0] = 0;
	else
		arr[0] = 1;
		
	if (mainArray[monstPosX][monstPosY+1] == 1 or mainArray[monstPosX][monstPosY+1] == 2 or mainArray[monstPosX][monstPosY+1] == 11)   //MONSTER MOVES RIGHT
		    arr[0] = 0;
	else
		arr[1] = 1;
	
	if (mainArray[monstPosX+1][monstPosY] == 1 or mainArray[monstPosX+1][monstPosY] == 2 or mainArray[monstPosX+1][monstPosY] == 11)   //MONSTER MOVES DOWN
		    arr[0] = 0;
	else
		arr[2] = 1;
	
	if (mainArray[monstPosX-1][monstPosY] == 1 or mainArray[monstPosX-1][monstPosY] == 2 or mainArray[monstPosX-1][monstPosY] == 11)   //MONSTER MOVES UP
		    arr[0] = 0;
	else
		arr[3] = 1;		
    
    
    int n = (rand() % 4);
	
	while (arr[n] == 0)
	 {n = (rand() % 4); }
	
	if (n == 0)    //LEFT
		{  
		if (mainArray[monstPosX][monstPosY-1] == 0)
		{mainArray[monstPosX][monstPosY] = 0;
		mainArray[monstPosX][monstPosY-1] = 5;
		monstPosY--;	}
		else if (mainArray[monstPosX][monstPosY-1] == 4)
		{mainArray[monstPosX][monstPosY] = 4;
		mainArray[monstPosX][monstPosY-1] = 5;	
		monstPosY--;}
		else if (mainArray[monstPosX][monstPosY-1] == 6 or mainArray[monstPosX][monstPosY-1] == 8 or mainArray[monstPosX][monstPosY-1] == 9 or mainArray[monstPosX][monstPosY-1] == 10)
		{mainArray[monstPosX][monstPosY] = 4;
		monstPosY--;
		monsterEatsPacman(mainArray, pacmanPosX, pacmanPosY);}
		else if (mainArray[monstPosX][monstPosY-1] == 5 or mainArray[monstPosX][monstPosY-1] == 7)
		monstersMovement(mainArray, monstPosX, monstPosY, pacmanPosX, pacmanPosY);
	    }
	
        else if (n == 1) //RIGHT
		{
		if (mainArray[monstPosX][monstPosY+1] == 0)
		{mainArray[monstPosX][monstPosY] = 0;
		monstPosY++;}	
		else if (mainArray[monstPosX][monstPosY+1] == 4)
		{mainArray[monstPosX][monstPosY] = 4;	
		monstPosY++;}
		else if (mainArray[monstPosX][monstPosY+1] == 6 or mainArray[monstPosX][monstPosY+1] == 8 or mainArray[monstPosX][monstPosY+1] == 9 or mainArray[monstPosX][monstPosY+1] == 10)
		{mainArray[monstPosX][monstPosY] = 4;
		monstPosY++;
		monsterEatsPacman(mainArray, pacmanPosX, pacmanPosY);}
		else if (mainArray[monstPosX][monstPosY+1] == 5 or mainArray[monstPosX][monstPosY+1] == 7)
		monstersMovement(mainArray, monstPosX, monstPosY, pacmanPosX, pacmanPosY);
		}
		
		else if (n == 2)  //DOWN
		{
		if (mainArray[monstPosX+1][monstPosY] == 0)
		{mainArray[monstPosX][monstPosY] = 0;	
		monstPosX++;}
		else if (mainArray[monstPosX+1][monstPosY] == 4)
		{mainArray[monstPosX][monstPosY] = 4;
		monstPosX++;}
		else if (mainArray[monstPosX+1][monstPosY] == 6 or mainArray[monstPosX+1][monstPosY] == 8 or mainArray[monstPosX+1][monstPosY] == 9 or mainArray[monstPosX+1][monstPosY] == 10)
		{mainArray[monstPosX][monstPosY] = 4;
		monstPosX++;
		monsterEatsPacman(mainArray, pacmanPosX, pacmanPosY);}
		else if (mainArray[monstPosX+1][monstPosY] == 5 or mainArray[monstPosX+1][monstPosY] == 7)
    	monstersMovement(mainArray, monstPosX, monstPosY, pacmanPosX, pacmanPosY);
		}
		
		else  //UP
		{
		if (mainArray[monstPosX-1][monstPosY] == 0)
		{mainArray[monstPosX][monstPosY] = 0;
		monstPosX--;}
		else if (mainArray[monstPosX-1][monstPosY] == 4)
		{mainArray[monstPosX][monstPosY] = 4;
		monstPosX--;}
		else if (mainArray[monstPosX-1][monstPosY] == 6 or mainArray[monstPosX-1][monstPosY] == 8 or mainArray[monstPosX-1][monstPosY] == 9 or mainArray[monstPosX-1][monstPosY] == 10)
		{mainArray[monstPosX][monstPosY] = 4;
		monstPosX--;
		monsterEatsPacman(mainArray, pacmanPosX, pacmanPosY);}
		else if (mainArray[monstPosX-1][monstPosY] == 5 or mainArray[monstPosX-1][monstPosY] == 7)
		monstersMovement(mainArray, monstPosX, monstPosY, pacmanPosX, pacmanPosY);
		}
		
	}
	mainArray[monstPosX][monstPosY] = 5;
}
		
//------------------------------------------------------------------------------------------------------------------------------------------------------		
		
void userInput(int mainArray[][13], int &posX, int &posY)  //RESPONSIBLE FOR TAKING INPUT, AND CONTROLLING HOW PACMAN WILL MOVE
{
	bool cantMove = false;                              //Declaration of boolean type variable named 'cantMove'
	char userInput;                                    //Declaration of character type variable named 'userInput'
	int keyValue, counterPowerPill = 0, storeVal;     //Declaration of 3 integer type variables 
	bool flagUp, flagDown, flagLeft, flagRight, flagPowerPill;  //Declaration of a few boolean type variables
	flagUp = false, flagDown = false, flagLeft = false, flagRight = false, flagPowerPill = false;  //Initialization of the boolean variables decalred above
		
		userInput = getch();     /*Pre-defined function which basically pauses/holds the console screen until the user inputs something. It 
		                         takes the character the user has entered and returns an integer(the ascii calue of that character). Uses the
								 library conio.h */
								 
		keyValue = userInput;   //Store the value that the user input in the above statement in the variable 'keyValue'
		system("CLS");         //The screen is cleared each time before taking input, so that only one maze is dislpayed on the console screen

		if (keyValue == 75 or keyValue == 97)    //CASE LEFT/A
		{
		    if (mainArray[posX][posY-1] == 1 or mainArray[posX][posY-1] == 2)
		    cantMove = true;
			else if (mainArray[posX][posY-1] == 5)
			monsterEatsPacman(mainArray, posX, posY);
			else if (mainArray[posX][posY-1] == 3)
			{
			powerPill(mainArray, posX, posY);
			mainArray[posX][posY] = 4;
			posY--;
			mainArray[posX][posY] = 8;}          //So that the next time the maze is drawn, pacman is printed at this position
			else if (mainArray[posX][posY-1] == 7)
			{flagLeft =  true;
			posY--;
			pacmanEatsMonster(mainArray);}
			else
			{
				flagLeft = true;
			mainArray[posX][posY] = 4;
			posY--;
			}
		}
			
		else if (keyValue == 77 or keyValue == 100)   //CASE RIGHT/D
		{
			if (mainArray[posX][posY+1] == 1 or mainArray[posX][posY+1] == 2)
		    cantMove = true;
			else if (mainArray[posX][posY+1] == 5)
			monsterEatsPacman(mainArray, posX, posY);
			else if (mainArray[posX][posY+1] == 3)
			{
			powerPill(mainArray, posX, posY);
			mainArray[posX][posY] = 4;
			posY++;
			mainArray[posX][posY] = 9;}          //So that the next time the maze is drawn, pacman is printed at this position
			else if (mainArray[posX][posY+1] == 7)
			{flagRight =  true;
			storeVal = mainArray[posX][posY+1];  
			posY++;
			mainArray[posX][posY] = 6;
			mainArray[posX][posY-1] = storeVal;}
			else
			{
			flagRight =  true;
			mainArray[posX][posY] = 4;
			posY++;
			}
        }
					
		else if (keyValue == 72 or keyValue == 119)   //CASE UP/W
		{		
			if ((mainArray[posX-1][posY] == 1) or (mainArray[posX-1][posY] == 2))
		    cantMove = true;
			else if (mainArray[posX-1][posY] == 5)
	      	monsterEatsPacman(mainArray, posX, posY);
			else if (mainArray[posX-1][posY] == 3)
			{
			powerPill(mainArray, posX, posY);
			mainArray[posX][posY] = 4;
			posX--;
			mainArray[posX][posY] = 6;}          //So that the next time the maze is drawn, pacman is printed at this position
			else if (mainArray[posX-1][posY] == 7)
			{flagUp =  true;
			storeVal = mainArray[posX-1][posY];  
			posX--;
			mainArray[posX][posY] = 6;
			mainArray[posX+1][posY] = storeVal;}
			else
			{
				flagUp =  true;
			mainArray[posX][posY] = 4;
			posX--;
			}
        }
					
		else if (keyValue == 80 or keyValue == 115)   //CASE DOWN/S
			{		;
			if (mainArray[posX+1][posY] == 1 or mainArray[posX+1][posY] == 2)
		    cantMove = true;
			else if (mainArray[posX+1][posY] == 5)
			monsterEatsPacman(mainArray, posX, posY);
			else if (mainArray[posX+1][posY] == 3)
			{
		    powerPill(mainArray, posX, posY);
			mainArray[posX][posY] = 4;
			posX++;
			mainArray[posX][posY] = 10;}          //So that the next time the maze is drawn, pacman is printed at this position
			else if (mainArray[posX+1][posY] == 7)
			{flagDown =  true;
			storeVal = mainArray[posX+1][posY];  
			posX++;
			mainArray[posX][posY] = 6;
			mainArray[posX-1][posY] = storeVal;}
			else
			{
				flagDown =  true;
			mainArray[posX][posY] = 4;
			posX++;
			}
        }
		
	if (flagPowerPill == true)
	{
	if (counterPowerPill < 20)
	{counterPowerPill++;
	powerPill(mainArray, posX, posY);}
    else
    {counterPowerPill = 0;
    flagPowerPill = false;}}
	
		
	if (flagLeft == true)
	mainArray[posX][posY] = 8;
	else if (flagRight == true)
	mainArray[posX][posY] = 9;
	else if (flagUp == true)
	mainArray[posX][posY] = 6;
	else if (flagDown == true)
	mainArray[posX][posY] = 10;
			
}

//------------------------------------------------------------------------------------------------------------------------------------------------------

int main()   //Default function - entry point for the program. Has return type integer and no parameters
{
	
	ofstream file("PacmanHighscore.txt");
	file.close();
	
	int userChoice;
	cout<<"Would you like to play the game(1), or see the records(2)?"<<endl;
	cin>>userChoice;
	
string name, difficulty, readLine;	

if (userChoice == 1)
{
int m1=5;   //Represents Monster 1
bool gameWon = false;
int mainArray[13][13] = {          /*Declaration and initialization of a 2D array. This array will be used to draw the maze 
                                   each time the user inputs something. We assigned values to its indexes based on what it's 
								   going to print at that index in the maze*/
								   
	{2,2,2,2,2,2,2,2,2,2,2,2,2},   //ROW 0
	{1,3,0,1,0,1,0,1,0,1,0,0,1},   //ROW 1
	{1,0,0,1,0,1,0,1,0,1,0,0,1},   //ROW 2
	{1,2,0,0,0,0,0,0,0,0,0,2,1},   //ROW 3
	{1,0,0,0,2,2,11,2,2,0,0,0,1},   //ROW 4
	{1,0,1,0,1,4,4,4,1,0,1,0,1},   //ROW 5
	{1,0,1,0,1,m1,5,5,1,0,1,0,1},   //ROW 6
	{1,2,1,0,1,2,2,2,1,0,1,2,1},   //ROW 7
	{1,0,0,0,0,0,0,0,0,0,0,0,1},   //ROW 8
	{1,0,0,0,0,0,0,0,0,0,0,0,1},   //ROW 9
	{1,0,1,0,0,1,0,1,0,0,1,0,1},   //ROW 10
	{1,6,1,0,0,1,0,1,0,0,1,3,1},   //ROW 11
	{1,2,2,2,2,2,2,2,2,2,2,2,1},   //ROW 12
	};	
	
int pacmanPosX = 11, pacmanPosY = 1, counter=0;   //Declaration and initialization of a few integer type variables
char gameOver = false;	                         //Delaration and initialization of a variable of type char

srand(time(0));                        /*Using a function within a function here- 'srand' uses the pre defined funtion 'time' as a paramter.
                                       And the funtion 'time' uses the value 0 as a parameter. The real time value of the actual time is 
									   being used here, therefore as time changes constantly, so do the generated values*/

int monst1PosX = 6, monst1PosY = 5;   //Monster 1 initial position
	
drawMaze(mainArray);                 //Draws the maze the first time, outside the main loop. This is before the game has started
cout<<"Use the arrow keys or awsd keys to play. "<<endl;   //Message displayed once before the game starts

while (gameOver == false && gameWon == false)
{
	userInput(mainArray, pacmanPosX, pacmanPosY);  //Functiion call- This function handles everything related to user input
	monstersMovement(mainArray, monst1PosX, monst1PosY, pacmanPosX, pacmanPosY);   //Function Call- This function controls the movement of the mosnsters
	drawMaze(mainArray);                           //Function call- This function is responsible for redrawing the maze each time it is updated

    if (lives ==0 )    //Condition to exit the loop in case user loses the game
    gameOver = true;
    
    gameWon = true;
    
    for (int rowsCounter = 1; rowsCounter < 13; rowsCounter++)
    {
    	for (int columnsCounter = 1; columnsCounter < 13; columnsCounter++)
    	{
    		if (mainArray[rowsCounter][columnsCounter] == 0)
    		gameWon = false;
		}
	}
} 
  if (gameWon == true)
  {
  	
  ofstream file("PacmanHighscore.txt");
  if (file.is_open())
  {
    file<<name<<"      Level: "<<difficulty<<"        Time: "<<timeForWin<<endl;
    file.close();
  }
  else cout << "Unable to open file";}
  }
  
  
  else if (userChoice == 2)
  {
  	ifstream file ("pacmanHighscores.txt");
  if (file.is_open())
  {
    while ( getline (file,readLine) )
    {
      cout << readLine << '\n';
    }
    file.close();
  }

  else cout << "Unable to open file"; 
  }


else 
{	
bool flagValidChoice = false;
cout<<"Enter a valid value. Press 1 to play the game or 2 to see the records: ";

while (flagValidChoice == false)
{
cin>>userChoice;

if (userChoice == 1 or userChoice == 2)
{flagValidChoice = true;
break;}

else
cout<<"Enter a valid value. Press 1 to play the game or 2 to see the records: "<<endl;
}

return 0;  //Indicates that the program has executed successfully

}
}