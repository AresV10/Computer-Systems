/*
* Connect 4 game using the C language.
* To create a connect four game using the topics that were taught untill now, containing an AI to play against, must conclude with win, lose or draw, allows either user or AI to start first,
* and display the board after every move.
*/
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

char board[7][8] = {{' ','A','B','C','D','E','F','G'},
					{'6','.','.','.','.','.','.','.'},
					{'5','.','.','.','.','.','.','.'},
					{'4','.','.','.','.','.','.','.'},
					{'3','.','.','.','.','.','.','.'},
					{'2','.','.','.','.','.','.','.'},
					{'1','.','.','.','.','.','.','.'},
				   };

char playerToken;
char aiToken;

//Function to print final end game message
void printFinal(char a)
{
	if(a == playerToken)
	{
		printf("Player won the game!\n");
	}
	else if(a == aiToken)
	{
		printf("AI won the game!\n");
	}
}

//Function to convert char input into corresponding column
int playerCharToArrayIndex(char input)
{
	switch (input)
	{
    	case 'A':
    	case 'a': return 1; 

    	case 'B':
    	case 'b': return 2;
        
        case 'C':
        case 'c': return 3;
        
        case 'D':
        case 'd': return 4;
       
        case 'E':
        case 'e': return 5;
       
        case 'F':
        case 'f': return 6;
       
        case 'G':
        case 'g': return 7;
        
    	default: return 0;// code to be executed if n doesn't match any cases
	}
}

//Function to print the game board
void printBoard()
{
	printf("\n");
	for(int i = 0; i<7;i++)
	{
		for(int j = 0; j<8; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

//Function to convert column to corresponding char name
char intToCol(int i)
{
	int num = i;
	if(num == 1) return 'A';
	if(num == 2) return 'B';
	if(num == 3) return 'C';
	if(num == 4) return 'D';
	if(num == 5) return 'E';
	if(num == 6) return 'F';
	if(num == 7) return 'G';
}

//Function to add move to board // 0 for user, 1 for ai
void addMove(char move, int mover)
{	
	int a = playerCharToArrayIndex(move);
	for(int i = 7; i>0;i--)
	{
		if(board[i][a]=='.')
		{
			if(mover == 0)
			{
				board[i][a]=playerToken;
				printBoard();
				break;
			}
			else
			{
				board[i][a]=aiToken;
				printBoard();
				printf("Ai Moved and chose %c\n\n", move);
				break;
			}			
		}		
	}	
	return;
}

//Function to add a random AI move to the board //also checks if the random move is valid
void addRandAiMove()
{
	srand(time(0));
	int num = (rand() % (7))+1;
	if(board[1][num] == 'X' || board[1][num] == 'O'){
		addRandAiMove();
		return;
	}
	addMove(intToCol(num),1);
	
}

//Function to add an AI move at the given column
void addAiMove(int x)
{	
	if(x==1||x==2||x==3||x==4||x==5||x==6||x==7)
		addMove(intToCol(x),1);
	
	if(x==0)
		addRandAiMove();
}


int gameStatus()
{	
	char aiMove;
	char temptok = 'l';
	int num = 0;

	//Check horizontal
	for(int i =1;i<=7; i++)
	{
		for(int j = 1;j<=5; j++ )
		{
			temptok = board[i][j];
			if(temptok==playerToken || temptok == aiToken)
			{
				if((board[i][j] == temptok && board[i][j+1] == temptok && board[i][j+2] == temptok))
				{
					if(board[i][j+3] == temptok && j<=4)
					{
						printFinal(temptok);
						return 1000;
					}
					if(i>1 && board[i][j-1] == '.' )
					{
						//if(!(board[i+1][j-1]=='.'))
							num = j-1;
					}
					if(i<7 && board[i][j+3] == '.' )
					{
						//if(i+1 < 7 && (board[i+1][j+3]=='.'))
						num = j+3;
					}
				}

				//Special Cases where the pattern is of type (X . X X) or (X X . X)
				if((j>1) && (board[i][j-1] == temptok) && (board[i][j+1] == temptok && board[i][j+2] == temptok) && (board[i][j] == '.'))
					num = j;
				if((j>1) && (board[i][j-1] == temptok) && (board[i][j] == temptok && board[i][j+2] == temptok) && (board[i][j+1] == '.'))
					num = j+1;
				if(j == 1 && board[i][j] == temptok && board[i][j+2] == temptok && board[i][j+3] == temptok && board[i][j] == '.')
					num = 2;
				if(j == 1 && board[i][j] == temptok && board[i][j+1] == temptok && board[i][j+3] == temptok && board[i][j+2] == '.')
					num = 2;
			}
		}
	}

	//Check Vertical
	temptok = 'l';
	for(int i =1;i<=3; i++)
	{
		for(int j = 1;j<=7; j++ )
		{
			temptok = board[i+1][j];
			if(temptok==playerToken || temptok == aiToken)
			{
				if((board[i+1][j] == temptok && board[i+2][j] == temptok && board[i+3][j] == temptok))
				{
					if(board[i][j] == temptok)
					{
						printFinal(temptok);
						return 1000;
					}
					if(board[i][j] == '.')	
						num = j;
				} 	
			}
		}
	}

	//Check Diagonal
	//left Diagonal
	temptok = 'l';

	for(int i = 1;i<=3; i++){
		for(int j = 4;j<=7; j++ ){
			temptok = board[i+1][j-1];
			if(temptok==playerToken || temptok == aiToken){
				if(board[i+1][j-1] == temptok && board[i+2][j-2] == temptok && board[i+3][j-3] == temptok){
					if(board[i][j] == temptok)
					{
						printFinal(temptok);
						return 1000;
					}
					if(board[i][j] == '.')
						num = j;			
				}
			}
		}
	}

	//Right Diagonal
	temptok = 'l';
	for(int i =1;i<=4; i++)
	{
		for(int j = 1;j<=3; j++ )
		{
			temptok = board[i+1][j+1];
			if(temptok==playerToken || temptok == aiToken)
			{
				if(board[i+1][j+1] == temptok && board[i+2][j+2] == temptok && board[i+3][j+3] == temptok)
				{
					if(board[i][j] == temptok )
					{
						printFinal(temptok);
						return 1000;	
					}	
					if(board[i][j] == '.')
						num = j;		
				}
			}
		}
	}

	return num;
}

//Function to deal with player interations for the game
void continueGame()
{
	char playerMove;

	printf("Enter a character between A and G: ");
	while(1)
	{
		scanf(" %c", &playerMove);//take player input
		if(board[1][playerCharToArrayIndex(playerMove)]==playerToken ||board[1][playerCharToArrayIndex(playerMove)]==aiToken)
			printf("\n This column is full, try another column\n");
		else if(playerMove!='A'&& playerMove!='a'&&playerMove!='B'&&playerMove!='b'&&playerMove!='C'&&playerMove!='c'&&playerMove!='D'&&playerMove!='d'&&playerMove!='E'&&playerMove!='e'&&playerMove!='F'&&playerMove!='f'&&playerMove!='G'&&playerMove!='g')
			printf("\n Enter a valid column\n");
		else
			break;
	}
	addMove(playerMove,0);	
}

//Function to start the game
void startGame()
{
	char firstMove;
	printf("Welcome to the connect four game, choose if you want to start the game or you want the AI to start the game (0 for User, 1 for AI)\n");

	while(1)
	{
		scanf("%c", &firstMove);
		if(firstMove == '1')
		{
			printf("AI Starts\n");
			aiToken = 'X';
			playerToken = 'O';
			break;
		}

		else if(firstMove == '0')
		{
			printf("User starts\n");
			printBoard();
			aiToken = 'O';
			playerToken = 'X';
			continueGame();
			break;
		}
		
		else
			printf("Enter either 0 or 1\n");
	}
	return;
}

//Main function
int main()
{
	int moves = 0;
	startGame();
	while((gameStatus() != 1000))
	{
		addAiMove(gameStatus());
		moves++;
		if(moves>41){
			printf("Game Draw\n");
			return 0;
		}
		if(gameStatus()==1000)
			return 0;
		continueGame();
		moves++;
		if(moves>41){
			printf("Game Draw\n");
			return 0;
		}
	}
	return 0;
}



