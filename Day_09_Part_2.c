/*
 ============================================================================
 Name        : Advent_2020_Day_9a.c
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


int getLineValue(char* fileData
               , int   lineNumber) {
int i;
int n;
int currentLine;


  for (i = currentLine = 0; (lineNumber + 0) != currentLine;) {
    for (; '\n' != fileData[i]; ++i) {  }
    ++i;  ++currentLine;
  }

  for (n = 0; '\n' != fileData[i]; ++i) {
    n = (n * 10) + fileData[i] - '0';
  }

  return n;

}


int sumCheck(char* fileData
           , int   lineNumber
           , int   preamble) {
int firstLine;
int secondLine;
int curNumber   = getLineValue(fileData
                             , lineNumber);
int firstNumber;
int secondNumber;


  for (firstLine = lineNumber - preamble; (lineNumber - 1) != firstLine; ++firstLine) {
    firstNumber = getLineValue(fileData
                             , firstLine);
    for (secondLine = firstLine + 1; (lineNumber + 0) != secondLine; ++secondLine) {
      secondNumber = getLineValue(fileData
                                , secondLine);
      if ((firstNumber + secondNumber) == curNumber) {
        return 0;
      }
    }
  }

  return curNumber;

}


int main(void) {

FILE* filePtr;
int   fileSize;
char* fileData;
int   checkSize;
int   errorFlag = 0;
int   answerValue;
char  answer[10] = { '\0' };
int   i;


#define nodoTest
#ifdef  doTest
  if (NULL == (filePtr = fopen("testInput.txt"
                             , "r"))) {
#else
  if (NULL == (filePtr = fopen("actualInput.txt"
                             , "r"))) {
#endif
    puts("No File Open Joy");  errorFlag = 1;
  }
  else {
    fseek(filePtr
        , 0
        , SEEK_END);
    fileSize = ftell(filePtr);
    fseek(filePtr
        , 0
        , SEEK_SET);

    if (NULL == (fileData = malloc(fileSize + 3))) {
      puts("No Malloc Joy");  errorFlag = 1;
    }
    else {
      if (!(checkSize = fread(fileData
                            , sizeof(char)
                            , fileSize
                            , filePtr))) {
        puts("No Read Joy");  errorFlag = 1;
      }
      else {
        if ('\n' != fileData[checkSize - 1]) {
          fileData[checkSize++] = '\n';
        }
        fileData[checkSize] = '\0';



//todo: Put in Data Process code
#ifdef  doTest
int preamble = 5;
#else
int preamble = 25;
#endif
int checkLine;
int j;
int k;
int sum;
int min = 0x7FFFFFFF;
int max = 0;


        for (checkLine = preamble; !(answerValue = sumCheck(fileData
                                                          , checkLine
                                                          , preamble)); ++checkLine) {  }

        for (i = sum = 0;; ++i) {
          for (k = i, sum = 0; (sum + 0) < answerValue; ++k) {
            sum += getLineValue(fileData
                              , k);
          }
          if ((sum + 0) == answerValue) {
            break;
          }
        }

        printf("Contiguous Range %i to %i\n"
             , i
             , k);

        for (j = i; (k + 0) > j; ++j) {
          sum = getLineValue(fileData
                           , j);
          if ((sum + 0) < min) {
            min = sum;
          }
          if ((sum + 0) > max) {
            max = sum;
          }
        }

        printf("Min = %i  Max = %i\n"
             , min
             , max);

        answerValue = min + max;

      }
      free(fileData);
    }
    fclose(filePtr);
  }

  if (!errorFlag) {
    if (!answerValue) {
      answer[i = 8] = '0';
    }
    else {
      for (i = 8; answerValue; --i, answerValue /= 10) {
        answer[i] = (answerValue % 10) + '0';
      }
      ++i;
    }
    puts(&answer[i]);
  }

	return EXIT_SUCCESS;
}
