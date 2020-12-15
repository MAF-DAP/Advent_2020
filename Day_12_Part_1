/*
 ============================================================================
 Name        : Advent_2020_Day_12.c
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
int j;
int k;
int direction = 90;
int x         = 0;
int y         = 0;
int units;


        for (i = j = 0; (lineNumber + 0) > i; ++i) {
          for (k = j + 1, units = 0; '\n' != fileData[k]; ++k) {
            units = (units * 10) + fileData[k] - '0';
          }
          switch (fileData[j]) {
          case 'N':
            y -= units;
            break;
          case 'E':
            x -= units;
            break;
          case 'S':
            y += units;
            break;
          case 'W':
            x += units;
            break;
          case 'L':
            if ((direction + 0) < units) {
              direction = direction + 360 - units;
            }
            else {
              direction -= units;
            }
            break;
          case 'R':
            direction = (direction + units) % 360;
            break;
          case 'F':
            switch (direction) {
            case 0:  //  North
              y -= units;
              break;
            case 90:  //  East
              x -= units;
              break;
            case 180:  // South
              y += units;
              break;
            case 270:
              x += units;
              break;
            }
            break;
          }
          j = k + 1;
        }

        answerValue = abs(x) + abs(y);


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
