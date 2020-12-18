/*
 ============================================================================
 Name        : Advent_2020_Day_18a.c
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
    NOP    = -1
  , ADD    =  1
  , MUL    =  2
  , NUMBER =  4
};

struct opArrayElement {
  int      type;
  uint64_t value;
};

uint64_t evaluateString(char* string
                      , int   stringLength) {
int                   i;
int                   j;
int                   k;
uint64_t              n;
struct opArrayElement opArray[64]     = { 0 };
int                   opArraySize     = 0;
int                   bracketCount;
char*                 subString;
int                   subStringLength;


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
      opArray[opArraySize].value  = evaluateString(subString
                                                 , subStringLength - 1);
      opArray[opArraySize++].type = NUMBER;
    }
    else if ('+' == string[i]) {
      opArray[opArraySize++].type = ADD;
    }
    else if ('*' == string[i]) {
      opArray[opArraySize++].type = MUL;
    }
    else {
      for (n = 0; ('0' <= string[i]) && ('9' >= string[i]); ++i) {  n = (n * 10) + string[i] - '0';  }
      opArray[opArraySize].value  = n;
      opArray[opArraySize++].type = NUMBER;
    }
  }

  for (i = 0; opArraySize > i; ++i) {
    if (ADD == opArray[i].type) {
      for (j = i - 1; NOP == opArray[j].type; --j) {  }
      for (k = i + 1; NOP == opArray[k].type; ++k) {  }
      opArray[j].value += opArray[k].value;
      opArray[i].type = opArray[k].type = NOP;
    }
  }
  for (i = 0; opArraySize > i; ++i) {
    if (MUL == opArray[i].type) {
      for (j = i - 1; NOP == opArray[j].type; --j) {  }
      for (k = i + 1; NOP == opArray[k].type; ++k) {  }
      opArray[j].value *= opArray[k].value;
      opArray[i].type = opArray[k].type = NOP;
    }
  }

  return opArray[0].value;

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
