	
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

const char startPlayerX = 'X';
const char startPlayerO = 'O';
const char empt = ' ';
const char tieSymbol = 'T';
const char catsGame = 'N';
int BOARD_WIDTH = 5;
int BOARD_SIZE = 9;
int moveCount = 0;
bool firstMove = false;

int dummy();
int mostFit(char gameBoard[]);
int middleChild(char gameBoard []);
int ginger (char gameBoard []);
void drawBoard(char gameBoard[], bool helpDrawCount);
int askForMove(char gameBoard[], char playerTurns);
bool makeMove(char gameBoard[], char playerTurns, int playerMove);
bool isWinner(char gameBoard[], char playerTurns, int sizeOfArray);
bool isTie();
bool checkForWin(char gameBoard[], char playerTurns, int spaceCount, int iStart, int iEnd);
ofstream myfile;
	 
int main()
{
      myfile.open ("tic.txt");
      char theGameIsGoing = 'y';         
      
	  while (theGameIsGoing == 'y'){   
        BOARD_WIDTH;
        BOARD_SIZE = BOARD_WIDTH * BOARD_WIDTH;         
        moveCount = 0;         
		char gameBoard[25];

        for (int i = 0; i < BOARD_SIZE; i++)
           gameBoard[i] = empt;

          bool win = false;     
      
          while (win == false){
            
              askForMove(gameBoard, startPlayerX);            
              drawBoard(gameBoard, false);             
              win = false;
              win = isWinner(gameBoard, startPlayerX, BOARD_SIZE);
                if (win == true){
                  myfile << "\n\nPlayer X(gene) has won!\n\n";
				  cout << "\n\nPlayer X(gene) has won!\n\n";

                  break;
                }              
             
                if (isTie()){
                  myfile << "\n\nCats game\n\n";
				  cout << "\n\nCats game\n\n";
                  break;
				}
            
              askForMove(gameBoard, startPlayerO);             
              drawBoard(gameBoard, false);                  
              win = false;
              win = isWinner(gameBoard, startPlayerO, BOARD_SIZE);
                if (win == true){
                  myfile << "\n\nPlayer O  won!\n\n";
				   cout << "\n\nPlayer O  won!\n\n";

                  break;
				}                    
             }                
          myfile << "\n\nRun once more? (y/n): ";
		  cout << "\n\nRun once more? (y/n): ";
          cin >> theGameIsGoing;         
          myfile << "\n\n";
		  cout << "\n\n";
      }

      return 0;
}

bool checkForWin(char gameBoard[], char playerTurns, int spaceCount, int iStart, int iEnd){
    
    int tileCount = 0;    
   
    for (int i = iStart; i < iEnd; i += spaceCount){
        
        if (gameBoard[i] == playerTurns){
            tileCount += 1;
        }        
       
        if (tileCount == BOARD_WIDTH){
            return true;
        }         
    }    
    return false; 
}

void drawBoard(char gameBoard[], bool helpDrawCount){
  
	int rowCount = 0;    
    myfile << "\n\n";
	cout << "\n\n";  
	for (int i = 0; i < BOARD_SIZE; i++){     
      
         myfile << gameBoard[i];   
		 cout << gameBoard[i];
         if (rowCount < BOARD_WIDTH ){
            if (i < 11)
               myfile << " | ";
			   cout << " | ";
               else
                 myfile << " | ";
			     cout << " | ";
            }      
          rowCount++;
       
        if (rowCount == BOARD_WIDTH){          
          myfile << endl; 
		  cout << endl;
          int actualWidth;
          
		  if (helpDrawCount)
                actualWidth = BOARD_WIDTH * 5;
            else
                actualWidth = BOARD_WIDTH * 3;            
            
            for (int line = -4; line < actualWidth; line++)
                myfile << "-";
			    cout << "-";  
            myfile << endl;
			cout << endl; 
            rowCount = 0;
        }
    }
    myfile << "\n\n";
	cout << "\n\n";
}

int askForMove(char gameBoard[], char playerTurns){
   
	int userInput;   
   
	if (playerTurns =='O'){
		userInput=dummy();}		
	
	if (playerTurns =='X'){		  
		userInput=mostFit(gameBoard);}

	if (moveCount==0){
	 if (playerTurns =='X'){
      userInput=12;	
	  firstMove=true;}
	  }
	mostFit( gameBoard);
			if (playerTurns=='X'){
				 myfile << "Player X(Gene) played ";
				 cout << "Player X(Gene) played ";}
			else {
				myfile<< "Player O played ";
				cout<< "Player O played ";
			}
    while (true){
        bool validMove = makeMove(gameBoard, playerTurns, userInput);
         if (validMove == false){
          if (playerTurns =='O'){
		    userInput=dummy();}
	       if (playerTurns =='X'){
             mostFit(gameBoard);
	        }
        }
        else
            break;
    }    
    return userInput;    
}




bool isWinner(char gameBoard[], char playerTurns, int sizeOfArray){
   
    for (int i = 0; i < BOARD_SIZE; i += BOARD_WIDTH){
       if (checkForWin(gameBoard, playerTurns, 1, i, i + BOARD_WIDTH) == true){
            return true;
        }
    }       
    int diagRight = 2 + (BOARD_WIDTH - 3);
    if (checkForWin(gameBoard, playerTurns, diagRight, (BOARD_WIDTH - 1), (diagRight * BOARD_WIDTH) + 1) == true){
        return true;
    }
          
    for (int i = 0; i < BOARD_WIDTH; i++)
    {
        if (checkForWin(gameBoard, playerTurns, 3 + (BOARD_WIDTH - 3), i, ((BOARD_WIDTH * 2) + i) + 1) == true){
            return true;
        }
    }
    
   
    if (checkForWin(gameBoard, playerTurns, 4 + (BOARD_WIDTH - 3), 0, BOARD_SIZE) == true){
       return true;
    } 
   
    return false;
}

bool makeMove(char gameBoard[], char playerTurns, int playerMove){    
   
	
    if (gameBoard[playerMove] == empt){
        gameBoard[playerMove] = playerTurns;       
        moveCount += 1;     
        
        return true;}
    else{        
        return false;}
}

bool isTie(){
    
	if (moveCount >= BOARD_SIZE)
        return true;
    
    return false; 
}



int dummy(){
	  srand((unsigned)time(0));
	  int dummyO = (rand()%24);
return dummyO;}

//whatever is left over, poor ginger kid
int ginger (char gameBoard []){
	int c=0;
	int gingerKid=0;
	bool end=false;
	while (c !=25 &&!end){
		if (gameBoard[c]==' '){
			gingerKid=c;
			end=true;
		}
		c++;
	}	
	
	return gingerKid;
}
int middleChild (char gameBoard[]){
	
	int c=0;
	int middleKidChroms=0;
	bool end= false;
	while (c !=24 &&!end){
		if (gameBoard[c]=='X' && gameBoard[c-1] !='O'&& gameBoard[c+5] !='X' && gameBoard[c-5] !='X'){
				middleKidChroms=c;
				end=true;
		}
		c++;
	}

	if (!end){
		c=0;
		while (c !=24 &&!end){
			if (gameBoard[c]=='X' && gameBoard[c-6] !='O'&& gameBoard[c-6] !='X'){
				middleKidChroms=c-6;
				end=true;
		}
		c++;
		}
	}
	if (!end && c<0  || gameBoard[c]=='O'||gameBoard[c]=='X'){
		myfile<<"Bad chromosome going Ginger!\n";
		cout<<"Bad chromosome going Ginger!\n";
		middleKidChroms=ginger(gameBoard);
		}
	
	return middleKidChroms;
}


 int mostFit(char gameBoard[]){
	int c=0;
	int fitMove=0;
	int fitChild =0;
	bool end= false;
	while (c !=24 &&!end){
		if (gameBoard[c]== 'X'&& gameBoard[c+1] !='O'&& gameBoard[c+1] !='X')
			{
				fitMove=c+1;
				end= true;
				}
			if (gameBoard[c]== 'X'&& gameBoard[c+5] !='O'&& gameBoard[c+5] !='X'&& end){
				fitChild=c+5;}				
		   	c++;
         }
		
			if (fitChild>fitMove){
				fitMove=fitChild;
			}
			
			if (fitMove==0){
				fitMove=middleChild(gameBoard);}
			
	return fitMove;
}
