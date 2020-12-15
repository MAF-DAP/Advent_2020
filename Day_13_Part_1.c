/*
 ============================================================================
 Name        : Advent_2020_Day_13.c
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

        for (i = lineNumber = 0; '\0' != fileData[i];) {
          for (; '\n' != fileData[i]; ++i) {  }
          ++lineNumber;  ++i;
        }



//todo: Put in Data Process code
int  earliestDepart;
int  busArraySize;
int  currentClosest;
int  currentBest    = 0x7FFFFFFF;
int* busArray;
int* timeArray;


        for (i = earliestDepart = 0; '\n' != fileData[i]; ++i) {
          earliestDepart = (earliestDepart * 10) + fileData[i] - '0';
        }
        busArray  = malloc(sizeof(int) * (checkSize - i));
        timeArray = malloc(sizeof(int) * (checkSize - i));
        for (++i, busArraySize = 0; '\0' != fileData[i];) {
          if ('x' == fileData[i]) {
            i += 2;
          }
          else {
            for (busArray[busArraySize] = 0; ('\n' != fileData[i]) && (',' != fileData[i]); ++i) {
              busArray[busArraySize] = (busArray[busArraySize] * 10) + fileData[i] - '0';
            }
            ++busArraySize;  ++i;
          }
        }

        for (i = currentClosest = 0; (busArraySize + 0) > i; ++i) {
          for (timeArray[i] = 0; (earliestDepart + 0) > timeArray[i]; timeArray[i] += busArray[i]) {  }
int currentTime = timeArray[i];
          if ((timeArray[i] - earliestDepart) < (currentBest - earliestDepart)) {
            currentBest = timeArray[currentClosest = i];
          }
        }

        answerValue = (timeArray[currentClosest] - earliestDepart) * busArray[currentClosest];

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
