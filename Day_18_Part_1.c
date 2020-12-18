/*
 ============================================================================
 Name        : Advent_2020_Day_18.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Advent of Code 2020 in C, Ansi-style
 ============================================================================
 */

#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

enum {
    NOP = -1
  , ADD =  0
  , MUL =  1
};

uint64_t evaluateString(char* string
                      , int   stringLength) {
int      i;
uint64_t n;
int      bracketCount;
char*    subString;
int      subStringLength;
int      nextOp          = NOP;
uint64_t returnValue     = 0;


  for (i = 0; stringLength > i; ++i) {
    if (' ' == string[i]) {
    }
    else if ('(' == string[i]) {
      for (subString = &string[++i], bracketCount = 1, subStringLength = 0; 0 != bracketCount; ++subStringLength, ++i) {
        if ('(' == string[i]) {
          ++bracketCount;
        }
        else if (')' == string[i]) {
          --bracketCount;
        }
      }
      n = evaluateString(subString
                       , subStringLength - 1);
      if (NOP == nextOp) {
        returnValue = n;
      }
      else if (ADD == nextOp) {
        returnValue += n;
      }
      else if (MUL == nextOp) {
        returnValue *= n;
      }
      nextOp = NOP;
    }
    else if ('+' == string[i]) {
      nextOp = ADD;
    }
    else if ('*' == string[i]) {
      nextOp = MUL;
    }
    else {
      for (n = 0; ('0' <= string[i]) && ('9' >= string[i]); ++i) {  n = (n * 10) + string[i] - '0';  }
      if (NOP == nextOp) {
        returnValue = n;
      }
      else if (ADD == nextOp) {
        returnValue += n;
      }
      else if (MUL == nextOp) {
        returnValue *= n;
      }
      nextOp = NOP;
    }
  }

  return returnValue;

}

int main(void) {

FILE*    filePtr;
int      fileSize;
char*    fileData;
int      lineNumber;
int      freadSize;
uint64_t answerValue = 0;
int      i;


#define nodoTest
#if defined(doTest)
  if (NULL == (filePtr = fopen("testInput.txt"
                             , "r"))) {
#else
  if (NULL == (filePtr = fopen("actualInput.txt"
                             , "r"))) {
#endif
    puts("\nFile Open Error");
    return EXIT_FAILURE;
  }

  fseek(filePtr
      , 0
      , SEEK_END);
  fileSize = ftell(filePtr);
  fseek(filePtr
      , 0
      , SEEK_SET);

  fileData = malloc(fileSize + 3);

  freadSize = fread(fileData
                  , sizeof(char)
                  , fileSize
                  , filePtr);
  if ('\n' != fileData[freadSize - 1]) {
    fileData[freadSize++] = '\n';
  }
  fileData[freadSize] = '\0';

  for (i = lineNumber = 0; '\0' != fileData[i];) {
    for (; '\n' != fileData[i]; ++i) {  }
    ++lineNumber;  ++i;
  }



//todo: Put in Data Process code
char* string;
int   stringLength;


  for (i = 0; '\0' != fileData[i];) {
    for (string = &fileData[i], stringLength = 0; '\n' != fileData[i]; ++i, ++stringLength) {  }  ++i;
    answerValue += evaluateString(string
                                , stringLength);
  }


  free(fileData);
  fclose(filePtr);

  printf("\n%I64d"
       , answerValue);

	return EXIT_SUCCESS;

}
