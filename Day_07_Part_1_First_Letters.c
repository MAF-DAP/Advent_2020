/*
 ============================================================================
 Name        : Advent_2020_Day_6.c
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

int sgSearch(char* searchData
           , char char1
           , char char2
           , int  depth) {
int i;


  for (i = 0; '\0' != searchData[i];) {
    if (((char1 + 0) == searchData[i]) && ((char2 + 0) == searchData[i + 1])) {
      for (i += 2; '\n' != searchData[i]; i += 3) {
        if (('s' == searchData[i + 1]) && ('g' == searchData[i + 2])) {
          return 1;
        }
        else if (sgSearch(searchData
                        , searchData[i + 1]
                        , searchData[i + 2]
                        , depth + 1)) {
          return 1;
        }
      }
    }
    for (; '\n' != searchData[i]; ++i) {  }  ++i;
  }

  return 0;

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
int   j;
char* compData;

int   sgCount;

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

    if (NULL == (fileData = malloc(fileSize + 1))) {
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
        fileData[checkSize] = '\0';


        compData = malloc(fileSize + 1);
        for (i = j = 0; '\0' != fileData[i];) {
          compData[j++] = fileData[i++];
          for (; ' ' != fileData[i]; ++i) {  }  ++i;                          //  Skip First Descriptor
          compData[j++] = fileData[i++];
          for (; ' ' != fileData[i]; ++i) {  }  ++i;                          //  Skip Second Descriptor
          for (; ' ' != fileData[i]; ++i) {  }  ++i;                          //  Skip "bags"
          for (; ' ' != fileData[i]; ++i) {  }  ++i;                          //  Skip "contain"
          if ('n' == fileData[i]) {                                           //  Skip "no other bags"
            for (; '.' != fileData[i]; ++i) {  }  ++i;
          }
          else {
            for (; '.' != fileData[i];) {
              compData[j++] = fileData[i++];        ++i;                      //  Get Number of Bags
              compData[j++] = fileData[i++];
              for (; ' ' != fileData[i]; ++i) {  }  ++i;                      //  Skip First Descriptor
              compData[j++] = fileData[i++];
              for (; ' ' != fileData[i]; ++i) {  }  ++i;                      //  Skip Second Descriptor
              for (; (',' != fileData[i]) && ('.' != fileData[i]); ++i) {  }  //  Skip "bag" and "bags"
              i = (',' == fileData[i]) ? (i + 2) : i;
            }  ++i;
          }
          if ('\n' == fileData[i]) {
            compData[j++] = fileData[i++];
          }
        }
        if ('\n' != compData[j - 1]) {  compData[j++] = '\n';  }
        compData[j] = '\0';

        for (i = sgCount = 0; '\0' != compData[i];) {
          if (('s' != compData[i]) || ('g' != compData[i + 1])) {
            for (i += 2; '\n' != compData[i]; i += 3) {
              if (sgSearch(compData
                         , compData[i + 1]
                         , compData[i + 2]
                         , 1)) {
                ++sgCount;
                break;
              }
            }
          }
          for (; '\n' != compData[i]; ++i) {  }  ++i;
        }

        free(compData);


      }
      free(fileData);
    }
    fclose(filePtr);
  }

  if (!errorFlag) {
#ifdef doTest
    if (!(answerValue = i)) {
#else
    if (!(answerValue = sgCount)) {
#endif
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
