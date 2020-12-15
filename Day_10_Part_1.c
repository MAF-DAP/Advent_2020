/*
 ============================================================================
 Name        : Advent_2020_Day_10a.c
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



int getRoutes(int* joltArray
            , int  currentValue
            , int  currentIndex
            , int  arraySize) {
int returnValue = 0;
int checkValue;
int checkIndex;
int flag =  0;


  checkValue = joltArray[checkIndex = (currentIndex + 1)];
  if ((checkIndex + 0) >= arraySize) {
    flag =  0;
  }
  else if ((checkValue + 3) < currentValue) {
    return returnValue;
  }
  else if (3 >= checkValue) {
    ++returnValue;
  }
  else {
    returnValue += getRoutes(joltArray
                           , checkValue
                           , checkIndex
                           , arraySize);
  }

  checkValue = joltArray[checkIndex = (currentIndex + 2)];
  if ((checkIndex + 0) >= arraySize) {
    return returnValue;
  }
  else if ((checkValue + 3) < currentValue) {
    return returnValue;
  }
  else if (3 >= checkValue) {
    ++returnValue;
  }
  else {
    returnValue += getRoutes(joltArray
                           , checkValue
                           , checkIndex
                           , arraySize);
  }

  checkValue = joltArray[checkIndex = (currentIndex + 3)];
  if ((checkIndex + 0) >= arraySize) {
    return returnValue;
  }
  else if ((checkValue + 3) < currentValue) {
    return returnValue;
  }
  else if (3 >= checkValue) {
    ++returnValue;
  }
  else {
    returnValue += getRoutes(joltArray
                           , checkValue
                           , checkIndex
                           , arraySize);
  }

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


#define doTestb
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
int j;
int k;
int lineNumber;
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

        for (i = 0; lineNumber > i; ++i) {
          printf("\nlineNumber[%i] = %i"
               , i
               , j = joltArray[i]);
        }

        answerValue = getRoutes(joltArray
                              , joltArray[0]
                              , 0
                              , lineNumber);


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
