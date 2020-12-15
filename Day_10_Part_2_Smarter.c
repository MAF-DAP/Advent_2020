/*
 ============================================================================
 Name        : Advent_2020_Day_10c.c
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


long long int singlesOptions(int singleCount) {


  switch (singleCount) {
  case 0:
  case 1: return 1;
  case 2: return 2;
  case 3: return 4;
  case 4: return 7;
  default:   //  Error
    return 0;
  }
}


int main(void) {

FILE* filePtr;
int   fileSize;
char* fileData;
int   checkSize;
int   errorFlag = 0;
int   answerValue = 0;
char  answer[10] = { '\0' };
int   i;


#define nodoTestb
#ifdef  doTesta
  if (NULL == (filePtr = fopen("testInputa.txt"
                             , "r"))) {
#else
#ifdef  doTestb
  if (NULL == (filePtr = fopen("testInputb.txt"
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



//todo: Put in Data Process code
int           j;
int           k;
int           lineNumber;
int*          joltArray;
int           oneCount;
int           difference;
long long int options = 1;


        for (i = lineNumber = 0; '\0' != fileData[i];) {
          for (; '\n' != fileData[i]; ++i) {  }
          ++lineNumber;  ++i;
        }

        joltArray = malloc(sizeof(int) * (lineNumber + 3));

        joltArray[0] = 0;
        for (i = 0, k = 1; '\0' != fileData[i];) {
          for (j = 0; '\n' != fileData[i]; ++i) {
            j = (j * 10) + fileData[i] - '0';
          }
          joltArray[k++] = j;  ++i;
        }

        for (i = 0; (lineNumber + 0) > i; ++i) {  //  Sort Low to High
          for (j = 0; (lineNumber + 0) > j; ++j) {
            if ((joltArray[j] + 0) > joltArray[j + 1]) {
              k = joltArray[j];
              joltArray[j] = joltArray[j + 1];
              joltArray[j + 1] = k;
            }
          }
        }
        joltArray[lineNumber + 1] = j = joltArray[lineNumber] + 3;

        for (i = 0; (lineNumber + 2) > i; ++i) {
          printf("\n%i", j = joltArray[i]);
        }


        for (i = 1, oneCount = 0; (lineNumber + 2) > i; ++i) {
          if (1 == (difference = joltArray[i] - joltArray[i - 1])) {
            ++oneCount;
          }
          else if (3 == difference) {
            options *= singlesOptions(oneCount);
            oneCount = 0;
          }
          else {  //  Error
            j = 4;  //  Error
          }
        }

        free(joltArray);


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

//	return EXIT_SUCCESS;
}
