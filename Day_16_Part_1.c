/*
 ============================================================================
 Name        : Advent_2020_Day_16.c
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

struct fieldValue {
  char fieldName[32];
  int  usedFlag;
  int  lowLow;
  int  highLow;
  int  lowHigh;
  int  highHigh;
};

int main(void) {

FILE*    filePtr;
int      fileSize;
char*    fileData;
int      lineNumber;
int      freadSize;
uint64_t answerValue = 0;
int      i;


#define nodoTest
#ifdef  doTest
  if (NULL == (filePtr = fopen("testInput.txt"
                             , "r"))) {
#else
  if (NULL == (filePtr = fopen("actualInput.txt"
                             , "r"))) {
#endif
    puts("No File Open Joy");
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
int               j;
int               n;
struct fieldValue fieldData[32];
int               fieldDataSize;


  for (i = fieldDataSize = 0; '\n' != fileData[i];) {
    for (j = 0; ':' != (fieldData[fieldDataSize].fieldName[j] = fileData[i]); ++j, ++i) {  }  fieldData[fieldDataSize].fieldName[j] = '\0';
    for (i += 2, fieldData[fieldDataSize].lowLow   = 0; '-'  != fileData[i]; ++i) {  fieldData[fieldDataSize].lowLow   = (fieldData[fieldDataSize].lowLow   * 10) + fileData[i] - '0';  }
    for (i += 1, fieldData[fieldDataSize].highLow  = 0; ' '  != fileData[i]; ++i) {  fieldData[fieldDataSize].highLow  = (fieldData[fieldDataSize].highLow  * 10) + fileData[i] - '0';  }
    for (i += 4, fieldData[fieldDataSize].lowHigh  = 0; '-'  != fileData[i]; ++i) {  fieldData[fieldDataSize].lowHigh  = (fieldData[fieldDataSize].lowHigh  * 10) + fileData[i] - '0';  }
    for (i += 1, fieldData[fieldDataSize].highHigh = 0; '\n' != fileData[i]; ++i) {  fieldData[fieldDataSize].highHigh = (fieldData[fieldDataSize].highHigh * 10) + fileData[i] - '0';  }
    ++i;  ++fieldDataSize;
  }

  for (++i; '\n' != fileData[i]; ++i) {  }  //  Skip Over "your ticket:"
  for (j = 0; fieldDataSize > j; ++j) {  fieldData[j].usedFlag = 0;  }

  for (++i; '\n' != fileData[i]; ++i) {  //  Read through the Ticket
    for (n = 0; (',' != fileData[i]) && ('\n' != fileData[i]); ++i)  {  n = (n * 10) + fileData[i] - '0';  }
    for (j = 0; fieldDataSize > j; ++j) {
      if (((fieldData[j].lowLow <= n) && (fieldData[j].highLow >= n)) || ((fieldData[j].lowHigh <= n) && (fieldData[j].highHigh >= n))) {
        break;
      }
    }
    if (j == fieldDataSize) {
      break;
    }
  }
  if (j == fieldDataSize) {
//todo: "n" is the erroneous number
  }

  for (++i; '\n' != fileData[i]; ++i) {  }  //  Skip Over "nearby tickets:"

  for (++i; '\0' != fileData[i]; ++i) {    //  Skip Over "nearby tickets:"
    for (j = 0; fieldDataSize > j; ++j) {  fieldData[j].usedFlag = 0;  }
    for (; '\n' != fileData[i];) {  //  Read through the Ticket
      for (n = 0; (',' != fileData[i]) && ('\n' != fileData[i]); ++i)  {  n = (n * 10) + fileData[i] - '0';  }
      for (j = 0; fieldDataSize > j; ++j) {
        if (((fieldData[j].lowLow <= n) && (fieldData[j].highLow >= n)) || ((fieldData[j].lowHigh <= n) && (fieldData[j].highHigh >= n))) {
          fieldData[j].usedFlag = 1;
          break;
        }
      }
      if (j == fieldDataSize) {
        break;
      }
      if (',' == fileData[i]) {
        ++i;
      }
    }
    if (j == fieldDataSize) {
      answerValue += n;
      for (; '\n' != fileData[i]; ++i) {  }
    }
  }


  free(fileData);
  fclose(filePtr);

  printf("\n%I64d"
       , answerValue);

	return EXIT_SUCCESS;

}
