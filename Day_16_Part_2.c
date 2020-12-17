/*
 ============================================================================
 Name        : Advent_2020_Day_16a.c
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
  int  field;
  int  value;
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


#define nodoTesta
#if defined(doTest)
  if (NULL == (filePtr = fopen("testInput.txt"
                             , "r"))) {
#elif defined(doTesta)
    if (NULL == (filePtr = fopen("testInputa.txt"
                               , "r"))) {
#else
  if (NULL == (filePtr = fopen("actualInput.txt"
                             , "r"))) {
#endif
    puts("\nNo File Open Joy");
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
struct fieldValue tempFieldData;
int               fieldDataSize;
int               fieldDataCount;
int               myTicketStart;
int               nearbyTicketStart;
int               ticketStart;
int               col;
int               matches;
int               matchRule;
int               rule;


  for (i = fieldDataSize = 0; '\n' != fileData[i];) {
    for (j = 0; ':' != (fieldData[fieldDataSize].fieldName[j] = fileData[i]); ++j, ++i) {  }  fieldData[fieldDataSize].fieldName[j] = '\0';
    for (i += 2, fieldData[fieldDataSize].lowLow   = 0; '-'  != fileData[i]; ++i) {  fieldData[fieldDataSize].lowLow   = (fieldData[fieldDataSize].lowLow   * 10) + fileData[i] - '0';  }
    for (i += 1, fieldData[fieldDataSize].highLow  = 0; ' '  != fileData[i]; ++i) {  fieldData[fieldDataSize].highLow  = (fieldData[fieldDataSize].highLow  * 10) + fileData[i] - '0';  }
    for (i += 4, fieldData[fieldDataSize].lowHigh  = 0; '-'  != fileData[i]; ++i) {  fieldData[fieldDataSize].lowHigh  = (fieldData[fieldDataSize].lowHigh  * 10) + fileData[i] - '0';  }
    for (i += 1, fieldData[fieldDataSize].highHigh = 0; '\n' != fileData[i]; ++i) {  fieldData[fieldDataSize].highHigh = (fieldData[fieldDataSize].highHigh * 10) + fileData[i] - '0';  }
    ++i;  ++fieldDataSize;
  }

  for (++i; '\n' != fileData[i]; ++i) {  }  //  Skip Over "your ticket:"

  for (myTicketStart = ++i; '\n' != fileData[i]; ++i) {  //  Read through the Ticket
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
    puts("\nUnexpected Error in \"My Ticket\"");
    return EXIT_FAILURE;
  }

  for (++i; '\n' != fileData[i]; ++i) {  }  //  Skip Over "nearby tickets:"

  for (nearbyTicketStart = ++i; '\0' != fileData[i]; ++i) {    //  Skip Over "nearby tickets:"
    for (ticketStart = i; '\n' != fileData[i];) {  //  Read through the Ticket
      for (n = 0; (',' != fileData[i]) && ('\n' != fileData[i]); ++i)  {  n = (n * 10) + fileData[i] - '0';  }
      for (j = 0; fieldDataSize > j; ++j) {
        if (((fieldData[j].lowLow <= n) && (fieldData[j].highLow >= n)) || ((fieldData[j].lowHigh <= n) && (fieldData[j].highHigh >= n))) {
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
      fileData[ticketStart] = '*';  //  Mark Ticket as bad
      answerValue += n;
      for (; '\n' != fileData[i]; ++i) {  }
    }
  }


  for (i = 0; fieldDataSize > i; ++i) {  fieldData[i].field = fieldData[i].value = -1;  }

  for (fieldDataCount = 0; fieldDataSize > fieldDataCount;) {
    for (col = 0; (fieldDataSize > fieldDataCount) && (fieldDataSize > col); ++col) {
      for (j = 0; fieldDataSize > j; ++j) {
        if ((col + 0) == fieldData[j].field) {
          break;
        }
      }
      if ((fieldDataSize + 0) == j) {  //  Position not filled
        for (matches = rule = 0; fieldDataSize > rule; ++rule) {
          if (-1 == fieldData[rule].field) {
            for (i = nearbyTicketStart; '\0' != fileData[i]; ++i) {
              if ('*' != fileData[i]) {  //  Skip Over bad ticket
                for (j = 0; col > j; ++j) {  for (; ',' != fileData[i]; ++i) {  }  ++i;  }
                for (n = 0; (',' != fileData[i]) && ('\n' != fileData[i]); ++i)  {  n = (n * 10) + fileData[i] - '0';  }
                if (((fieldData[rule].lowLow  > n) || (fieldData[rule].highLow  < n)) &&
                    ((fieldData[rule].lowHigh > n) || (fieldData[rule].highHigh < n))) {
                  break;  //  Not in Range
                }
              }
              for (; '\n' != fileData[i]; ++i) {  }
            }
            if ('\0' == fileData[i]) {
              matchRule = rule;
              ++matches;
            }
          }
        }
        if (1 == matches) {
          fieldData[matchRule].field = col;
          ++fieldDataCount;
        }
      }
    }
  }

  for (i = 0; (fieldDataSize - 1) > i; ++i) {
    for (j = 0; (fieldDataSize - 1) > j; ++j) {
      if (fieldData[j].field > fieldData[j + 1].field) {
        tempFieldData = fieldData[j];
        fieldData[j]  = fieldData[j + 1];
        fieldData[j + 1] = tempFieldData;
      }
    }
  }

  for (i = myTicketStart, j = 0, answerValue = 1; fieldDataSize > j; ++j) {
    for (fieldData[j].value = 0; (',' != fileData[i]) && ('\n' != fileData[i]); ++i) {  fieldData[j].value = (fieldData[j].value * 10) + fileData[i] - '0';  }
    if ('\n' != fileData[i]) {
      ++i;
    }
    if (('d' == fieldData[j].fieldName[0]) && ('e' == fieldData[j].fieldName[1])) {
      answerValue *= fieldData[j].value;
    }
  }

  free(fileData);
  fclose(filePtr);

  printf("\n%I64d"
       , answerValue);

	return EXIT_SUCCESS;

}
