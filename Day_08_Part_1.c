/*
 ============================================================================
 Name        : Advent_2020_Day_8.c
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

char lineStart(char*  insList
             , int    lineNumber
             , char** currentIns) {
int i;
int checkLine;


  for (i = checkLine = 0; (checkLine + 0) != lineNumber;) {
    for (; '\n' != insList[i++];) {  }
    ++checkLine;
  }

  *currentIns = &insList[i];
  return insList[i];

}


int main(void) {

FILE* filePtr;
int   fileSize;
char* fileData;
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


//todo: Put in Data Process code
int   j;
char* insList;
char* currentIns;
int   accumulator;
int   lineNumber;
int   insValue;


        for (i = lineNumber = 0; '\0' != fileData[i]; ++i) {
          if ('\n' == fileData[i]) {
            ++lineNumber;
          }
        }

        insList = malloc(fileSize + 3 + lineNumber);
        insList[0] = ' ';
        for (i = 0, j = 1; '\0' != fileData[i];) {
          if ('\n' == (insList[j++] = fileData[i++])) {
            insList[j++] = ' ';
          }
        }
        insList[j] = '\0';


        for (lineNumber = accumulator = 0; ' ' == lineStart(insList
                                                          , lineNumber
                                                          , &currentIns);) {
          currentIns[0] = '*';
          if ('n' == currentIns[1]) {
            ++lineNumber;
          }
          else if ('a' == currentIns[1]) {
            for (j = 6, insValue = 0; '\n' != currentIns[j]; ++j) {
              insValue = (insValue * 10) + currentIns[j] - '0';
            }
            insValue = ('-' == currentIns[5]) ? (0 - insValue) : insValue;
            accumulator += insValue;
            ++lineNumber;
          }
          else {  //  "jmp"
            for (j = 6, insValue = 0; '\n' != currentIns[j]; ++j) {
              insValue = (insValue * 10) + currentIns[j] - '0';
            }
            insValue = ('-' == currentIns[5]) ? (0 - insValue) : insValue;
            lineNumber += insValue;
          }
        }

        answerValue = accumulator;

        free(insList);
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
