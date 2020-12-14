/*
 ============================================================================
 Name        : Advent_2020_Day_14a.c
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


struct mem {
  long long int addr;
  long long int value;
};

enum {
    WORDSIZE = 36
  , MEMSIZE  = 1 << 16
};


int main(void) {

FILE* filePtr;
int   fileSize;
char* fileData;
int   lineNumber;
int   checkSize;
int   errorFlag           = 0;
unsigned long long int answerValue = 0;
int   i;


#define nodoTesta
#ifdef  doTest
  if (NULL == (filePtr = fopen("testInput.txt"
                             , "r"))) {
#else
#ifdef  doTesta
  if (NULL == (filePtr = fopen("testInputa.txt"
                             , "r"))) {
#else
  if (NULL == (filePtr = fopen("actualInput.txt"
                             , "r"))) {
#endif
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
unsigned long long j;
unsigned long long k;
unsigned long long maskFLOAT;
unsigned long long maskOR;
struct mem*        memPtr     = malloc(sizeof(struct mem) * MEMSIZE);
unsigned long long memSize    = MEMSIZE;
unsigned long long memCount   = 0;
unsigned long long floatCount;
unsigned long long floatValue;
unsigned long long bit;
unsigned long long maskBit;
unsigned long long addr;
unsigned long long checkAddr;
unsigned long long value;
unsigned long long shifted;


        for (i = 0; '\0' != fileData[i];) {
          if ('a' == fileData[i + 1]) {  //  mask
            for (maskFLOAT = maskOR = floatCount = j = 0, i += 7; '\n' != fileData[i]; ++i, ++j) {
              maskFLOAT <<= 1;  maskOR <<= 1;
//              maskFLOAT *= 2;  maskOR *= 2;
              switch (fileData[i]) {
              case 'X':
                ++floatCount;
                break;
              case '1':
                maskFLOAT |= 1;
                maskOR |= 1;
                break;
              case '0':
                maskFLOAT |= 1;
                break;
              }
            }
          }
          else {  //  mem
            for (addr = 0, i += 4; ']' != fileData[i]; ++i) {  addr = (addr * 10) + fileData[i] - '0';  }
            for (value = 0, i += 4; '\n' != fileData[i]; ++i) {  value = (value * 10) + fileData[i] - '0';  }

            addr &= maskFLOAT;
            addr |= maskOR;

            for (floatValue = 0; (1 << floatCount) > floatValue; ++floatValue) {
              for (checkAddr = addr, bit = maskBit = 0; WORDSIZE > bit; ++bit) {
//                if (!(maskFLOAT & (1 << bit)) {
                for (k = 0, shifted = 1; bit > k; ++k, shifted *= 2) {  }
                if (!(maskFLOAT & shifted)) {
                  if ((floatValue >> maskBit) & 1UL) {
//                    checkAddr |= (1 << bit);
                    checkAddr |= shifted;
                  }
                  ++maskBit;
                }
              }

              for (j = 0; memCount > j; ++j) {
                if ((memPtr[j].addr + 0) == checkAddr) {
                  break;
                }
              }
              if ((memCount + 0) == j) {
                if ((memSize + 0) == memCount) {
                  memPtr = realloc(memPtr
                                 , sizeof(struct mem) * (memSize = ((memSize * 3) / 2)));
                }
                memPtr[j].addr = checkAddr;
                ++memCount;
              }
              memPtr[j].value = value;

            }

          }
          ++i;
        }

        for (answerValue = 0, i = 0; memCount > i; ++i) {
          answerValue += memPtr[i].value;
        }

        free(memPtr);


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
