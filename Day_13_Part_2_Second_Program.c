/*
 ============================================================================
 Name        : Advent_2020_Day_13b.c
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

FILE*         filePtr;
int           fileSize;
char*         fileData;
int           lineNumber;
int           checkSize;
int           errorFlag   = 0;
long long int answerValue = 0;
int           i;


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
int            busArraySize;
int            element;
long long int  cntr;
long long int  interval;
long long int  increment;
long long int  difference;
long long int* busArray;
long long int* startArray;
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

        for (interval = increment = busArray[0], i = 1; (busArraySize + 0) > i; ++i) {
          difference = startArray[i] - startArray[i - 1];
          for (; (interval + difference) % busArray[i];) {
            interval += increment;
          }
          interval += difference;
          increment *= busArray[i];
        }

long long int answerValue = interval - startArray[busArraySize - 1];

        free(timeArray);
        free(busArray);

      }
      free(fileData);
    }
    fclose(filePtr);
  }

  if (!errorFlag) {
    printf("\n%I64d"
         , answerValue);
  }

	return EXIT_SUCCESS;
}
