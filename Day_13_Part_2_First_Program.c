/*
 ============================================================================
 Name        : Advent_2020_Day_13a.c
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

int main(void) {

FILE* filePtr;
int   fileSize;
char* fileData;
int   lineNumber;
int   checkSize;
int   errorFlag   = 0;
int   answerValue = 0;
char  answer[10]  = { '\0' };
int   i;


#define doTest
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

        for (i = lineNumber = 0; '\0' != fileData[i];) {
          for (; '\n' != fileData[i]; ++i) {  }
          ++lineNumber;  ++i;
        }



//todo: Put in Data Process code
int            j;
int            busArraySize;
int            element;
long long int  cntr;
long long int  testValue;
long long int  testValueNext;
int*           busArray;
int*           startArray;
long long int* timeArray;


        for (i = 0; '\n' != fileData[i]; ++i) {
        }
        busArray   = malloc(sizeof(int) * (checkSize - i));
        startArray = malloc(sizeof(int) * (checkSize - i));
        timeArray  = malloc(sizeof(long long int) * (checkSize - i));
        for (++i, element = busArraySize = 0; '\0' != fileData[i];) {
          if ('x' == fileData[i]) {
            i += 2;
          }
          else {
            for (busArray[busArraySize] = 0; ('\n' != fileData[i]) && (',' != fileData[i]); ++i) {
              busArray[busArraySize] = (busArray[busArraySize] * 10) + fileData[i] - '0';
            }
            startArray[busArraySize] = element;
            ++busArraySize;  ++i;
          }
          ++element;
        }

        for (cntr = 1;; ++cntr) {
          testValue = busArray[0] * cntr;
          for (j = 1; (busArraySize + 0) > j; ++j) {
            for (testValueNext = 0; (testValue + 0) > testValueNext; testValueNext += busArray[j]) {  }
            if ((testValue + startArray[j] - startArray[j - 1]) != testValueNext) {
              break;
            }
            else {
              testValue = testValueNext;
              if (2 == j) {
                printf("\nGoing Strong at %i matches at %I64d"
                     , j
                     , testValue);
              }
              else if (3 == j) {
                printf("\nGoing Strong at %i matches at %I64d"
                     , j
                     , testValue);
              }
              else if (4 == j) {
                printf("\nGoing Strong at %i matches at %I64d"
                     , j
                     , testValue);
              }
              else if (5 == j) {
                printf("\nGoing Strong at %i matches at %I64d"
                     , j
                     , testValue);
              }
              else if (6 <= j) {
                printf("\nGoing Strong at %i matches at %I64d"
                     , j
                     , testValue);
              }
            }
          }
          if ((busArraySize + 0) == j) {  //  Have the answer!
            break;
          }
        }

long long int longAnswer = busArray[0] * cntr;

        answerValue = busArray[0] * cntr;

        free(timeArray);
        free(busArray);

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
    printf("\n%s"
         , &answer[i]);
  }

	return EXIT_SUCCESS;
}
