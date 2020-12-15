/*
 ============================================================================
 Name        : Advent_2020_Day_10b.c
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


int recursiveCheck(int joltArray[]
                 , int checkValue
                 , int checkLevel
                 , int bottomIndex) {
int returnValue = 0;


  if ((bottomIndex + 0) == checkLevel) {  //  At bottom, return no matter what
    if (3 >= checkValue) {  //  At bottom, should be good
      return 1;  //  Check Value is 1, 2 or 3 and all okay
    }
    else {
      return 0;  //  Check Value is > 3 so nothing you can do
    }
  }

  if ((checkValue - 3) > joltArray[checkLevel]) {  //  Can't bridge this
    return 0;
  }

  if (30 == checkLevel) {
    printf(".");
  }

  returnValue += recursiveCheck(joltArray  //  Check with the current value Ignored
                              , checkValue
                              , checkLevel + 1
                              , bottomIndex);


  returnValue += recursiveCheck(joltArray  //  Check with the current value used as new checkValue
                              , joltArray[checkLevel]
                              , checkLevel + 1
                              , bottomIndex);

  return returnValue;

}


int main(void) {

FILE* filePtr;
int   fileSize;
char* fileData;
int   checkSize;
int   errorFlag = 0;
int   answerValue;
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
int  j;
int  k;
int  lineNumber;
int* joltArray;


        for (i = lineNumber = 0; '\0' != fileData[i];) {
          for (; '\n' != fileData[i]; ++i) {  }
          ++lineNumber;  ++i;
        }

        joltArray = malloc(sizeof(int) * (lineNumber + 1));

        for (i = k = 0; '\0' != fileData[i];) {
          for (j = 0; '\n' != fileData[i]; ++i) {
            j = (j * 10) + fileData[i] - '0';
          }
          joltArray[k++] = j;  ++i;
        }
        joltArray[k] = 0x7FFFFFFF;

        for (i = 0; (lineNumber - 1) > i; ++i) {  //  Sort High to Low
          for (j = 0; (lineNumber - 1) > j; ++j) {
            if ((joltArray[j] + 0) < joltArray[j + 1]) {
              k = joltArray[j];
              joltArray[j] = joltArray[j + 1];
              joltArray[j + 1] = k;
            }
          }
        }


        answerValue = recursiveCheck(joltArray
                                   , joltArray[0] + 3
                                   , 0
                                   , lineNumber);


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

	return EXIT_SUCCESS;
}
