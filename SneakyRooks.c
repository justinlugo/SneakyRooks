// Justin Lugo
// COP 3502 - Fall 2020

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SneakyRooks.h"

// The purpose of this function is to determine whether (given an array of strings), whether the
// rooks located on the chess board can attack one another or are safe.
int allTheRooksAreSafe(char **rookStrings, int numRooks, int boardSize)
{
  int i, *numCol, *numRow;
  Coordinate *rookCoor;

  // Allocate memory for the dynamic variables we intend on using.
  rookCoor = malloc(sizeof(Coordinate));
  numCol = malloc(sizeof(int) * (boardSize + 1));
  numRow = malloc(sizeof(int) * (boardSize + 1));

  // Initialize all spaces on the board to 0 before we populate it with rooks.
  for (i = 0; i <= boardSize; i++)
  {
    numCol[i] = 0;
    numRow[i] = 0;
  }

  // If the string is empty, immediately free all space and return 1, since there are no rooks
  // to attack one another.
  if (rookStrings[0] == "")
  {
    free(rookCoor);
    free(numCol);
    free(numRow);
    return 1;
  }

  // For the number of rooks we intend on populating the board with, we give each one their
  // coordinates on the board.
  for(i = 0; i < numRooks; i++)
  {

    // Go through the string to determine the coordinates of the rooks.
    parseCoordinateString(rookStrings[i], rookCoor);

    // If there are any other rooks within the same row and/or column, free the memory and return 0
    // because they are not safe.
    if(numCol[rookCoor->col] != 0 || numRow[rookCoor->row] != 0)
    {
      free(rookCoor);
      free(numCol);
      free(numRow);
      return 0;
    }

    // Set the row and column to occupied by a rook.
    numCol[rookCoor->col] = 1;
    numRow[rookCoor->row] = 1;
  }

  // Free all used space before leaving the function.
  free(rookCoor);
  free(numCol);
  free(numRow);
  return 1;
}

// The purpose of this function is to parse through rookString to determine where the rooks are
// on the chess board and populate the Coordinate pointer with it's location.
void parseCoordinateString(char *rookString, Coordinate *rookCoordinate)
{
  int i, rookCol = 0, rookRow = 0, strLength;
  strLength = strlen(rookString);

  // We parse through the string to determine where our rooks are based off of the string passed
  // into the function. By applying ascii arithmetic, we are able to find the row and column that
  // rooks occupy.
  for (i = 0; i < strLength; i++)
  {
    // The digits from our string determine the row.
    if (isdigit(rookString[i]))
    {
      // Digits are 0-9 (10 possible); 48 is equal to '0'.
      rookRow = (rookRow * 10) + (rookString[i] - 48);
      rookCoordinate->row = rookRow;
    }

    // While the letters determine the column.
    else if (isalpha(rookString[i]))
    {
      // There are 26 letters in the alphabet; 96 is equal to ascii 'a' - 1.
      rookCol = (rookCol * 26) + (rookString[i] - 96);
      rookCoordinate->col = rookCol;
    }
  }
}

// Function to show how difficult I felt the assignment was.
double difficultyRating(void)
{
  return 4.0;
}

// Function to show how many hours I spent with the assignment.
double hoursSpent(void)
{
  return 7.0;
}
