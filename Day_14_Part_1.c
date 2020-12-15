/*
 ============================================================================
 Name        : Advent_2020_Day_14.c
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
int   errorFlag           = 0;
long long int answerValue = 0;
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
enum {
    WORDSIZE = 36
  , MEMSIZE = 1 << 16
};
long long int maskAND;
long long int maskOR;
long long int mem[MEMSIZE] = { 0 };
int           index;
long long int value;


        for (i = 0; '\0' != fileData[i];) {
          if ('a' == fileData[i + 1]) {  //  mask
            for (maskAND = maskOR = 0, i += 7; '\n' != fileData[i]; ++i) {
              maskAND <<= 1;  maskOR <<= 1;
              switch (fileData[i]) {
              case 'X':
                maskAND |= 1;
                break;
              case '1':
                maskAND |= 1;
                maskOR |= 1;
                break;
              case '0':
                break;
              }
            }
          }
          else {  //  mem
            for (index = 0, i += 4; ']' != fileData[i]; ++i) {  index = (index * 10) + fileData[i] - '0';  }
            if (MEMSIZE <= index) {
              errorFlag = 1;  //  Not 64k of memory
            }
            for (value = 0, i += 4; '\n' != fileData[i]; ++i) {  value = (value * 10) + fileData[i] - '0';  }
            value &= maskAND;
            value |= maskOR;
            mem[index] = value;
          }
          ++i;
        }

        for (answerValue = 0, i = 0; MEMSIZE > i; ++i) {
          answerValue += mem[i];
        }


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
