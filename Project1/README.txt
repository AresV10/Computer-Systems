Connect four
=============================================================================================================================================================================

This is a program to play connect four between the user and a programmed AI.
The idea is to have a 2 dimentional array to save the board state and the subsequesnt AI moves are calculated based on the board state.

The logic starts with asking if the user wants to start or if they want the AI to start.
Based on that either the AI moves randomly or the program deals with the user's input column
Then the program checks if the board has any winning positions, if there aren't any then the AI makes a move.

the AIs move is based on checks on the board.
    The priority of moves is: defend opponent 3 in a row first, then attack  if self 3 in a row, then randomly place a token 

Then the program checks if there are any winning positions, and if there aren't then it repeats the cycle.

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

printFinal(char a)
    This function is used to print the final statements when soneone wins, input is the winner's token

playerCharToArrayIndex(char input)
    As the name indicates, this converts char input into the corresponding column using a switch case

printBoard()
    This function uses iteration throughout the array and prints each character, thus printing the entire board.

intToCol(int i)
    the opposite of playerCharToArrayIndex(), converts column i to corresponding char name
    used this because some functions are designed to use char as a parameter.

addMove(char move, int mover)
    A function that is used to add a move made either by the player or the AI to the board. 
    1st parameter is the column that to which a move has to be added to, while the second parameter is the mover, that is either if it is the user or AI adding the move

addRandAiMove()
    Used to generate a random move, used in cases where there is no apparant move to be made. Calls addMove()

addAiMove(int x)
    Used to check if theres a given colunm to act on, or else it calls addRandAiMove() to add a random move

gameStatus()
    This function checks for win patterns and if there is the win pattern - 1 token. 
    If a win pattern is present then it declares that the game has been won, 
    if there is a win pattern -1 token then it reutrns the column number where to play to either defend from the move or attack from the move

continueGame()
    Takes user input and checks if it is a valid move and then once it is it adds it to the board using add move

startGame()
    checks if the user wants to start or they want the Ai to start, then if based on their choice it assigns aiToken and playerToken their respective values.
    also if if the user decides to start, it calls continueGame()

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

link to video: https://youtu.be/pw84A7MJgTk

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




