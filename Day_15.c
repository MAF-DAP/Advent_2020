/*
 ============================================================================
 Name        : Advent_2020_Day_15a.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
int   i;
uint64_t answerValue = 0;


//todo: Put in Data Process code
#define nodoTest
enum {
     BUFFERSTART = 1 << 16
#ifdef  doTest
  ,  ENDTURN     = 2020
#else
  ,  ENDTURN     = 30000000
#endif
};
int     startingNumbers[] =
#define doTest8
#if     defined(doTest1)
{ 0, 3, 6, -1 };
#elif   defined(doTest2)
{ 1, 3, 2, -1 };
#elif   defined(doTest3)
{ 2, 1, 3, -1 };
#elif   defined(doTest4)
{ 1, 2, 3, -1 };
#elif   defined(doTest5)
{ 2, 3, 1, -1 };
#elif   defined(doTest6)
{ 3, 2, 1, -1 };
#elif   defined(doTest7)
{ 3, 1, 2, -1 };
#elif   defined(doTest8)
{ 15, 5, 1, 4, 7, 0, -1 };  //  *My* Numbers
#endif
int     startingNumbersSize;
  for (startingNumbersSize = 0; -1 != startingNumbers[startingNumbersSize]; ++startingNumbersSize) {  }
int*    calledArray     = malloc(sizeof(int) * BUFFERSTART);
int     calledArraySize = BUFFERSTART;
int     lastNumber;
int     nextNumber;
int     savedLastNumber;
int     turn;


  for (i = 0;  BUFFERSTART > i; ++i) {  calledArray[i] = -1;  }

  for (turn = 0; startingNumbersSize > turn; ++turn) {  calledArray[startingNumbers[turn]] = turn;  }
  lastNumber = 0;  //  This is valid because in no sequence, the number has been written before

  for (; ENDTURN > turn;) {
    if (calledArraySize < lastNumber) {
      calledArray = realloc(calledArray
                          , sizeof(int) * (lastNumber * 2));
      for (i = calledArraySize; (lastNumber * 2) > i; ++i) {  calledArray[i] = -1;  }
      calledArraySize = lastNumber * 2;
    }
    if (-1 == calledArray[lastNumber]) {
      nextNumber              = 0;
    }
    else {
      nextNumber              = turn - calledArray[lastNumber];
    }
    calledArray[lastNumber]   = turn++;
    savedLastNumber           = lastNumber;
    lastNumber                = nextNumber;
  }

  answerValue = savedLastNumber;


  free(calledArray);

  printf("\n%I64d"
       , answerValue);

	return EXIT_SUCCESS;

}
